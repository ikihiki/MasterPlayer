#ifndef PARTDATA_H
#define PARTDATA_H

#include <QObject>
#include<QDir>
#include<QUrl>

class PartData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
    Q_PROPERTY(QUrl OffImage READ OffImage WRITE setOffImage NOTIFY OffImageChanged)
    Q_PROPERTY(QUrl OnImage READ OnImage WRITE setOnImage NOTIFY OnImageChanged)
    Q_PROPERTY(QUrl Vocal READ Vocal WRITE setVocal NOTIFY VocalChanged)
    Q_PROPERTY(double Volume READ Volume WRITE setVolume NOTIFY VolumeChanged)

public:
    explicit PartData(QObject *parent = 0);
    explicit PartData(const QString &path,QObject *parent=0);

    QString Name() const;
    void setName(const QString &name);

    QUrl OffImage() const;
    void setOffImage(const QUrl &path);

    QUrl OnImage() const;
    void setOnImage(const QUrl &path);

    QUrl Vocal() const;
    void setVocal(const QUrl &path);

    double Volume() const;
    void setVolume(const double volume);

    ~PartData();

signals:
    void NameChanged();
    void OffImageChanged();
    void OnImageChanged();
    void VocalChanged();
    void VolumeChanged();

public slots:

private:
    QString m_name;
    QUrl m_offImage;
    QUrl m_onImsge;
    QUrl m_vocal;
    double m_volume;
    QDir* m_dir;
};

#endif // PARTDATA_H
