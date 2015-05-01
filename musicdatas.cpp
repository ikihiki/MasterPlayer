#include "musicdatas.h"

MusicDatas::MusicDatas(QObject *parent) : QObject(parent)
{

}

MusicDatas::MusicDatas(const QUrl &path, QObject *parent):QObject(parent)
{
    QDir dir=QDir(path.toLocalFile());
    for(const QFileInfo music : dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        m_musics<<new MusicData(QUrl::fromLocalFile(music.absoluteFilePath()),this);
    }
    audio=new Audio3D(this);
}

QQmlListProperty<MusicData> MusicDatas::Musics()
{
    return QQmlListProperty<MusicData>(this,m_musics);
}


MusicData* MusicDatas::SelectedMusic() const
{
    return m_selectedMusic;
}

void MusicDatas::setSelectedMusic(MusicData *data)
{
    if(m_selectedMusic!=data)
    {
        if(m_selectedMusic!=nullptr)
        {
            m_selectedMusic->unload();
        }
        m_selectedMusic=data;
        m_selectedMusic->load();
        emit SelectedMusicChanged();
    }
}


MusicDatas::~MusicDatas()
{

}

