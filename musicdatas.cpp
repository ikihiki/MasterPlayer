#include "musicdatas.h"

MusicDatas::MusicDatas(QObject *parent) : QObject(parent)
{

}

MusicDatas::MusicDatas(const QUrl &path, QObject *parent):QObject(parent)
{
    QDir dir=QDir(path.toLocalFile());
    for(const QFileInfo music : dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        m_musics<<QVariant::fromValue(static_cast<QObject *>(new MusicData(QUrl::fromLocalFile(music.absoluteFilePath()),this)));
    }
    audio=new Audio3D(this);
}

QVariantList MusicDatas::Musics() const
{
    return m_musics;
}

void MusicDatas::setMusics(const QVariantList &musics)
{
    if(musics!=m_musics)
    {
        m_musics=musics;
        emit MusicsChanged();
    }
}

QVariant MusicDatas::SelectedMusic() const
{
    return m_selectedMusic;
}

void MusicDatas::setSelectedMusic(const QVariant &data)
{
    if(m_selectedMusic!=data)
    {
        m_selectedMusic=data;
        emit SelectedMusicChanged();
    }
}


MusicDatas::~MusicDatas()
{

}

