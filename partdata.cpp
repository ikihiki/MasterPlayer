#include "partdata.h"

PartData::PartData(QObject *parent) : QObject(parent)
{
	speaker = new Speaker(this);
}

PartData::PartData(const QString &path,QObject *parent):QObject(parent)
{
	speaker = new Speaker(this);
    m_dir=new QDir(path);
    setName(m_dir->dirName());
    QStringList offList;
    offList<<"*off*";
    setOffImage(QUrl::fromLocalFile(m_dir->entryInfoList(offList,QDir::Files).first().filePath()));
    QStringList onList;
    onList<<"*on*";
    setOnImage(QUrl::fromLocalFile(m_dir->entryInfoList(onList,QDir::Files).first().filePath()));
    QStringList vocalList;
    vocalList<<"*.mp3";
    setVocal(QUrl::fromLocalFile(m_dir->entryInfoList(vocalList,QDir::Files).first().filePath()));
    setGain(50);
}

QString PartData::name() const
{
    return m_name;
}

void PartData::setName(const QString &name)
{
    if(name!=m_name)
    {
        m_name=name;
        emit nameChanged();
    }
}

QUrl PartData::offImage() const
{
    return m_offImage;
}

void PartData::setOffImage(const QUrl &path)
{
    if(path!=m_offImage)
    {
        m_offImage=path;
        emit offImageChanged();
    }
}

QUrl PartData::onImage() const
{
    return m_onImsge;
}

void PartData::setOnImage(const QUrl &path)
{
    if(path!=m_onImsge)
    {
        m_onImsge=path;
        emit onImageChanged();
    }
}

QUrl PartData::vocal() const
{
    return speaker->source();
}

void PartData::setVocal(const QUrl &path)
{
	if (path != speaker->source())
    {
		speaker->setSource(path);
        emit vocalChanged();
    }
}

float PartData::gain() const
{
    return speaker->gain();
}

void PartData::setGain(const float volume)
{
    if(volume!=speaker->gain())
    {
		speaker->setGain(volume);
        emit gainChanged();
    }
}

float PartData::x() const
{
	return speaker->x();
}

void PartData::setX(const float x)
{
	if (x != speaker->x())
	{
		speaker->setX(x);
		emit xChanged();
	}
}

float PartData::y() const
{
	return speaker->y();
}

void PartData::setY(const float y)
{
	if (y != speaker->y())
	{
		speaker->setY(y);
		emit yChanged();
	}
}

float PartData::z() const
{
	return speaker->z();
}

void PartData::setZ(const float z)
{
	if (z != speaker->z())
	{
		speaker->setZ(z);
		emit zChanged();
	}
}



PartData::~PartData()
{
    m_name=QString::null;
    m_offImage=QString::null;
    m_onImsge=QString::null;
    delete m_dir;
}

