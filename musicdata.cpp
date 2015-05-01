#include "musicdatas.h"

MusicData::MusicData(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(loop()));
}

MusicData::MusicData(const QUrl &path,QObject *parent):QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(loop()));
    QDir dir=QDir(path.toLocalFile());
    m_path = path;
    m_name = dir.dirName();
    QStringList instList;
    instList<<"*.mp3";
   m_instrumental = new Instrumental(dir.entryInfoList(instList,QDir::Files).first().filePath(),this);
   m_listener = new Listener(this);
    for(const QFileInfo part : dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        m_parts<<new PartData(part.absoluteFilePath(),this);
    }


}

QUrl MusicData::path() const
{
    return m_path;
}

QString MusicData::name() const
{
    return m_name;
}

Instrumental* MusicData::instrumental() const
{
    return m_instrumental;
}

Listener* MusicData::listener() const
{
    return m_listener;
}

QQmlListProperty<PartData> MusicData::parts()
{
    return QQmlListProperty<PartData>(this,m_parts);
}

QVariant MusicData::metaData() const
{
    return m_metadata;
}


float MusicData::duration() const
{
	return m_instrumental->getSpeaker()->duration();
}

float MusicData::loadedPosition() const
{
    float result = m_instrumental->getSpeaker()->loadedPosition();
	for (auto part : m_parts)
	{
		if (result > part->getSpeaker()->loadedPosition())
		{
			result = part->getSpeaker()->loadedPosition();
		}
	}
	return result;
}

float MusicData::position() const
{
    return m_position;
}

void MusicData::setPosition(float position)
{
    if(m_position!=position)
    {

    m_instrumental->getSpeaker()->setPosition(position);
    for (auto part : m_parts)
    {
        part->getSpeaker()->setPosition(position);
    }
    m_position = position;
    emit positionChanged();
    }
}

bool MusicData::isLoadFinished() const
{
	return false;
}

bool MusicData::isPlaying() const
{
	return m_isPlaying;
}
void MusicData::setIsPlaying(const bool isplaying)
{
    if (!isplaying)
	{
		play();
	}
	else
	{
		pause();
	}
}




void MusicData::selectMusic()
{
    MusicDatas *datas =dynamic_cast<MusicDatas*>(parent());
    if(datas!=NULL)
    {
        datas->setSelectedMusic(this);
    }
}

void MusicData::play()
{
	if (!m_isPlaying)
	{
		m_isPlaying = true;
        m_instrumental->getSpeaker()->play();
        for (auto part : m_parts)
        {
            part->getSpeaker()->play();
        }
        m_timer->start(100);
		emit isPlayingChanged();
	}
}

void MusicData::pause()
{
	if (m_isPlaying)
	{
		m_isPlaying = false;
		m_instrumental->getSpeaker()->pause();
		for (auto part : m_parts)
		{
			part->getSpeaker()->pause();
		}
		m_timer->stop();
		emit isPlayingChanged();
	}
}

void MusicData::stop()
{
	if (m_isPlaying)
	{
		m_isPlaying = false;
		m_instrumental->getSpeaker()->stop();
		for (auto part : m_parts)
		{
			part->getSpeaker()->stop();
		}
		m_timer->stop();
		emit isPlayingChanged();
	}
}

void MusicData::load()
{
    m_instrumental->getSpeaker()->load();
    for (auto part : m_parts)
    {
        part->getSpeaker()->load();
    }

}

void MusicData::unload()
{
    m_instrumental->getSpeaker()->unload();
    for (auto part : m_parts)
    {
        part->getSpeaker()->unload();
    }
}

void MusicData::loop()
{
	if (m_position != m_instrumental->getSpeaker()->position())
	{
		m_position = m_instrumental->getSpeaker()->position();
		emit positionChanged();
	}

    bool miss=false;
    float tmp = m_instrumental->getSpeaker()->position();
    for (auto part : m_parts)
    {
        float direction =part->getSpeaker()->position() -tmp;
        if ( direction<-0.0001||direction>0.0001)
		{
            miss=true;
		}
    }
    if(miss)
    {
    setPosition(tmp);
    qDebug()<<"miss";
    }

    switch (m_instrumental->getSpeaker()->state()) {
    case Speaker::stopped:
        stop();
        break;
    case Speaker::paused:
        pause();
        break;
    case Speaker::playing:
        break;
    default:
        stop();
        break;
    }
}

MusicData::~MusicData()
{
}

