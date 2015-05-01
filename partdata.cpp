#include "partdata.h"

PartData::PartData(QObject *parent) : QObject(parent)
{
	m_speaker = new Speaker(this);
}

PartData::PartData(const QString &path,QObject *parent):QObject(parent)
{
	m_speaker = new Speaker(this);
    m_dir=new QDir(path);
    m_name = m_dir->dirName();
    QStringList offList;
    offList<<"*off*";
    m_offImage = QUrl::fromLocalFile(m_dir->entryInfoList(offList,QDir::Files).first().filePath());
    QStringList onList;
    onList<<"*on*";
    m_onImsge = QUrl::fromLocalFile(m_dir->entryInfoList(onList,QDir::Files).first().filePath());
    QStringList vocalList;
    vocalList<<"*.mp3";
    m_speaker->setSource(QUrl::fromLocalFile(m_dir->entryInfoList(vocalList,QDir::Files).first().filePath()));
    setGain(50);
}

QString PartData::name() const
{
    return m_name;
}


QUrl PartData::offImage() const
{
    return m_offImage;
}

QUrl PartData::onImage() const
{
    return m_onImsge;
}


QUrl PartData::vocal() const
{
    return m_speaker->source();
}

float PartData::gain() const
{
    return m_speaker->gain();
}

void PartData::setGain(const float volume)
{
    if(volume!=m_speaker->gain())
    {
		m_speaker->setGain(volume);
        emit gainChanged();
    }
}

float PartData::x() const
{
	return m_speaker->x();
}

void PartData::setX(const float x)
{
	if (x != m_speaker->x())
	{
		m_speaker->setX(x);
		emit xChanged();
	}
}

float PartData::y() const
{
	return m_speaker->y();
}

void PartData::setY(const float y)
{
	if (y != m_speaker->y())
	{
		m_speaker->setY(y);
		emit yChanged();
	}
}

float PartData::z() const
{
	return m_speaker->z();
}

void PartData::setZ(const float z)
{
	if (z != m_speaker->z())
	{
		m_speaker->setZ(z);
		emit zChanged();
	}
}

bool PartData::isMute() const
{
	return m_speaker->isMute();
}

void PartData::setIsMute(const bool ismute)
{
    if (m_speaker->isMute() != ismute)
	{
		m_speaker->setIsMute(ismute);
		emit isMuteChanged();
	}
}

Speaker* PartData::getSpeaker() const
{
	return m_speaker;
}

PartData::~PartData()
{
    m_name=QString::null;
    m_offImage=QString::null;
    m_onImsge=QString::null;
    delete m_dir;
}

