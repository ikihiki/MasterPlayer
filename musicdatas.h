#ifndef MUSICDATAS_H
#define MUSICDATAS_H

#include <QObject>
#include<QVariant>
#include <QQmlApplicationEngine>
#include"musicdata.h"
#include "audio3d.h"

class MusicDatas : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<MusicData> Musics READ Musics NOTIFY MusicsChanged)
    Q_PROPERTY(MusicData* SelectedMusic READ SelectedMusic WRITE setSelectedMusic NOTIFY SelectedMusicChanged)


public:
    explicit MusicDatas(QObject *parent = 0);
    explicit MusicDatas(const QUrl &path, QObject *parent = 0);

    QQmlListProperty<MusicData> Musics();

    MusicData* SelectedMusic() const;
    void setSelectedMusic(MusicData *data);

    ~MusicDatas();

signals:
    void MusicsChanged();
    void SelectedMusicChanged();
public slots:

private:
    QList<MusicData*> m_musics;
    MusicData *m_selectedMusic;
    Audio3D *audio;
};
#endif // MUSICDATAS_H
