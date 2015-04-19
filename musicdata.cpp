#include "musicdatas.h"

MusicData::MusicData(QObject *parent) : QObject(parent)
{

}

MusicData::MusicData(const QUrl &path,QObject *parent):QObject(parent)
{
    QDir dir=QDir(path.toLocalFile());
    setPath(path);
    setName(dir.dirName());
    QStringList instList;
    instList<<"*.mp3";
    setInstrumental(QUrl::fromLocalFile(dir.entryInfoList(instList,QDir::Files).first().filePath()));
    setVolume(50);
    for(const QFileInfo part : dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        m_parts<<QVariant::fromValue(static_cast<QObject *>(new PartData(part.absoluteFilePath(),this)));
    }


}

QUrl MusicData::Path() const
{
    return m_path;
}
void MusicData::setPath(const QUrl &path)
{
    if(path!=m_path)
    {
        m_path=path;
        emit PathChanged();
    }
}

QString MusicData::Name() const
{
    return m_name;
}
void MusicData::setName(const QString &name)
{
    if(m_name!=name)
    {
        m_name=name;
        emit NameChanged();
    }
}

QUrl MusicData::Instrumental() const
{
    return m_instrumental;
}
void MusicData::setInstrumental(const QUrl &inst)
{
    if(inst!=m_instrumental)
    {
        m_instrumental=inst;
        emit InstrumentalChanged();
        setMetaData(QVariant::fromValue(static_cast<QObject *>(new MetaData(inst,this))));
    }
}


double MusicData::Volume() const
{
    return m_volume;
}
void MusicData::setVolume(const double volume)
{
    if(volume!=m_volume)
    {
        m_volume=volume;
        emit VolumeChanged();
    }
}

QVariantList MusicData::Parts() const
{
    return m_parts;
}
void MusicData::setParts(const QVariantList &parts)
{
    if(parts!=m_parts)
    {
        m_parts=parts;
        emit PartsChanged();
    }
}

QVariant MusicData::metaData() const
{
    return m_metadata;
}

void MusicData::setMetaData(const QVariant &metadata)
{
    if(metadata!=m_metadata)
    {
        m_metadata=metadata;
        emit MetaDataChanged();
    }
}

void MusicData::selectMusic() const
{
    MusicDatas *datas =dynamic_cast<MusicDatas*>(parent());
    if(datas!=NULL)
    {
        datas->setSelectedMusic(QVariant::fromValue(static_cast<QObject *>(const_cast<MusicData *>(this))));
    }
}

MusicData::~MusicData()
{
}

