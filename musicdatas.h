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

    Q_PROPERTY(QVariantList Musics READ Musics WRITE setMusics NOTIFY MusicsChanged)
    Q_PROPERTY(QVariant SelectedMusic READ SelectedMusic WRITE setSelectedMusic NOTIFY SelectedMusicChanged)


public:
    explicit MusicDatas(QObject *parent = 0);
    explicit MusicDatas(const QUrl &path, QObject *parent = 0);

    QVariantList Musics() const;
    void setMusics(const QVariantList &musics);

    QVariant SelectedMusic() const;
    void setSelectedMusic(const QVariant &data);

    ~MusicDatas();

signals:
    void MusicsChanged();
    void SelectedMusicChanged();
public slots:

private:
    QVariantList m_musics;
    QVariant m_selectedMusic;
    Audio3D *audio;
};
#endif // MUSICDATAS_H
