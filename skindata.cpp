#include "skindata.h"

SkinData::SkinData(QObject *parent) : QObject(parent)
{

}

SkinData::SkinData(const QUrl &path, QObject *parent):QObject(parent)
{
    m_select=QUrl(QStringLiteral("qrc:/MusicSelectTmp.qml"));
    m_player=QUrl(QStringLiteral("qrc:/PlayerTmp.qml"));
}

QUrl SkinData::SelectSkin() const
{
    return m_select;
}

void SkinData::setSelectSkin(const QUrl &url)
{
    if(url!=m_select)
    {
        m_select=url;
        emit SelectSkinChanged();
    }
}

QUrl SkinData::PlayerSkin() const
{
    return m_player;
}

void SkinData::setPlayerSkin(const QUrl &url)
{
    if(url!=m_player)
    {
        m_player=url;
        emit PlayerSkinChanged();
    }
}


SkinData::~SkinData()
{

}

