#include "partdata.h"

PartData::PartData(QObject *parent) : QObject(parent)
{

}

PartData::PartData(const QString &path,QObject *parent):QObject(parent)
{
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
    setVolume(50);
}

QString PartData::Name() const
{
    return m_name;
}

void PartData::setName(const QString &name)
{
    if(name!=m_name)
    {
        m_name=name;
        emit NameChanged();
    }
}

QUrl PartData::OffImage() const
{
    return m_offImage;
}

void PartData::setOffImage(const QUrl &path)
{
    if(path!=m_offImage)
    {
        m_offImage=path;
        emit OffImageChanged();
    }
}

QUrl PartData::OnImage() const
{
    return m_onImsge;
}

void PartData::setOnImage(const QUrl &path)
{
    if(path!=m_onImsge)
    {
        m_onImsge=path;
        emit OnImageChanged();
    }
}

QUrl PartData::Vocal() const
{
    return m_vocal;
}

void PartData::setVocal(const QUrl &path)
{
    if(path!=m_vocal)
    {
        m_vocal=path;
        emit VocalChanged();
    }
}

double PartData::Volume() const
{
    return m_volume;
}

void PartData::setVolume(const double volume)
{
    if(volume!=m_volume)
    {
        m_volume=volume;
        emit VolumeChanged();
    }
}


PartData::~PartData()
{
    m_name=QString::null;
    m_offImage=QString::null;
    m_onImsge=QString::null;
    m_vocal=QString::null;
    m_volume=NULL;
    delete m_dir;
}

