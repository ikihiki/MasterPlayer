#ifndef VIEWER_H
#define VIEWER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QQmlContext>
#include <QtQml>
#include "musicdatas.h"
#include "skindata.h"
#include "speaker.h"

class Viewer : public QObject
{
    Q_OBJECT
public:
    explicit Viewer(QObject *parent = 0);
    explicit Viewer(const QUrl &music, const QUrl &skin, QObject *parent = 0);

    void setMusicFolder(const QUrl &path);
    void setSkinFolder(const QUrl &path);

    Q_INVOKABLE void goPlayer();

    Q_INVOKABLE void goSelect();

    QQmlApplicationEngine* Engine();

    void Start();

    ~Viewer();

signals:

public slots:

private:
    QQmlApplicationEngine *m_engine;
    MusicDatas *m_datas;
    SkinData *m_skin;
};

#endif // VIEWER_H
