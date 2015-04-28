#ifndef PARTDATA_H
#define PARTDATA_H

#include <QObject>
#include<QDir>
#include<QUrl>
#include"speaker.h"

class PartData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl offImage READ offImage WRITE setOffImage NOTIFY offImageChanged)
    Q_PROPERTY(QUrl onImage READ onImage WRITE setOnImage NOTIFY onImageChanged)
    Q_PROPERTY(QUrl vocal READ vocal WRITE setVocal NOTIFY vocalChanged)
    Q_PROPERTY(float gain READ gain WRITE setGain NOTIFY gainChanged)
	Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
	Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
	Q_PROPERTY(float z READ z WRITE setZ NOTIFY zChanged)
	Q_PROPERTY(bool isMute READ isMute WRITE setIsMute NOTIFY isMuteChanged)


public:
    explicit PartData(QObject *parent = 0);
    explicit PartData(const QString &path,QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    QUrl offImage() const;
    void setOffImage(const QUrl &path);

    QUrl onImage() const;
    void setOnImage(const QUrl &path);

    QUrl vocal() const;
    void setVocal(const QUrl &path);

	float gain() const;
	void setGain(const float gain);

	float x() const;
	void setX(const float x);

	float y() const;
	void setY(const float y);

	float z() const;
	void setZ(const float z);

	bool isMute() const;
	void setIsMute(const bool ismute);


    ~PartData();

signals:
    void nameChanged();
    void offImageChanged();
    void onImageChanged();
    void vocalChanged();
	void gainChanged();
	void xChanged();
	void yChanged();
	void zChanged();
	void isMuteChanged();


public slots:

private:
    QString m_name;
    QUrl m_offImage;
    QUrl m_onImsge;
    QDir* m_dir;
	Speaker *speaker = nullptr;
};

#endif // PARTDATA_H
