#include "viewer.h"

Viewer::Viewer(QObject *parent) : QObject(parent)
{
    qmlRegisterType<Speaker>("AudioSystem", 1, 0, "Speaker");
    m_engine = new QQmlApplicationEngine(this);
}

Viewer::Viewer(const QUrl &music, const QUrl &skin, QObject *parent):QObject(parent)
{
    qmlRegisterType<Speaker>("AudioSystem", 1, 0, "Speaker");
    m_engine = new QQmlApplicationEngine(this);
    setMusicFolder(music);
    setSkinFolder(skin);
}

void Viewer::setMusicFolder(const QUrl &path)
{
    m_datas= new MusicDatas(path,this);
    m_engine->rootContext()->setContextProperty("Data",m_datas);
}

void Viewer::setSkinFolder(const QUrl &path)
{
    m_skin= new SkinData(path,this);
    m_engine->rootContext()->setContextProperty("Skin",m_skin);
}

void Viewer::goPlayer()
{
    QMetaObject::invokeMethod( m_engine->rootObjects()[0],"goPlayer");
}

void Viewer::goSelect()
{
    QMetaObject::invokeMethod( m_engine->rootObjects()[0],"goSelect");
}

QQmlApplicationEngine* Viewer::Engine()
{
    return m_engine;
}

void Viewer::Start()
{
    m_engine->load(QUrl(QStringLiteral("qrc:/Main.qml")));

}

Viewer::~Viewer()
{

}

