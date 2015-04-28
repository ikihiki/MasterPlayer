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
    for(const QFileInfo part : dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        m_parts<<new PartData(part.absoluteFilePath(),this);
    }


}

QUrl MusicData::path() const
{
    return m_path;
}
void MusicData::setPath(const QUrl &path)
{
    if(path!=m_path)
    {
        m_path=path;
        emit pathChanged();
    }
}

QString MusicData::name() const
{
    return m_name;
}
void MusicData::setName(const QString &name)
{
    if(m_name!=name)
    {
        m_name=name;
        emit nameChanged();
    }
}

QUrl MusicData::instrumental() const
{
    return m_instrumental;
}
void MusicData::setInstrumental(const QUrl &inst)
{
    if(inst!=m_instrumental)
    {
        m_instrumental=inst;
        emit instrumentalChanged();
        setMetaData(QVariant::fromValue(static_cast<QObject *>(new MetaData(inst,this))));
    }
}



QQmlListProperty<PartData> MusicData::Parts() const
{
    return (QQmlListProperty<PartData>)QQmlListProperty<PartData>((QObject*)this,(QList<PartData*>)m_parts);
}

QVariant MusicData::metaData() const
{
    return m_metadata;
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

