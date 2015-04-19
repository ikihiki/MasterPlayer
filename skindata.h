#ifndef SKINDATA_H
#define SKINDATA_H

#include <QObject>
#include <QUrl>

class SkinData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl SelectSkin READ SelectSkin WRITE setSelectSkin NOTIFY SelectSkinChanged)
    Q_PROPERTY(QUrl PlayerSkin READ PlayerSkin WRITE setPlayerSkin NOTIFY PlayerSkinChanged)

public:
    explicit SkinData(QObject *parent = 0);
    explicit SkinData(const QUrl &path, QObject *parent = 0);

    QUrl SelectSkin() const;
    void setSelectSkin(const QUrl &url);

    QUrl PlayerSkin() const;
    void setPlayerSkin(const QUrl &url);

    ~SkinData();

signals:
    void SelectSkinChanged();
    void PlayerSkinChanged();

public slots:

private:
    QUrl m_select;
    QUrl m_player;
};

#endif // SKINDATA_H
