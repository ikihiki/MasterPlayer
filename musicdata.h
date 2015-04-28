#ifndef MUSICDATA_H
#define MUSICDATA_H

#include <QObject>
#include <QDir>
#include <QUrl>
#include <QVariant>
#include <QQmlListProperty>

#include "metadata.h"
#include "partdata.h"
#include "instrumental.h"
#include "speaker.h"

class MusicData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(Instrumental* instrumental READ instrumental)
    Q_PROPERTY(double gain READ gain WRITE setGain NOTIFY gainChanged)
    Q_PROPERTY(QQmlListProperty<PartData> Parts READ Parts)
    Q_PROPERTY(QVariant metaData READ metaData)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionchanged)

public:
    explicit MusicData(QObject *parent = 0);
    explicit MusicData(const QUrl &path, QObject *parent=0);

    QUrl path() const;
    void setPath(const QUrl &path);

    QString name() const;
    void setName(const QString &name);

	Instrumental* instrumental() const;

	QQmlListProperty<PartData> Parts() const;

    QVariant metaData() const;

    qint64 duration() const;
    void setDuration(const quint64 duration);

    qint64 loadedPosition() const;
    void setLoadedPosition(const qint64 position);

    qint64 position() const;
    void setPosition(const qint64 position);

    bool isLoadFinished() const;
    void setIsLoadFinished(const bool isfinishied);

    bool isMute() const;
    void setIsMute(const bool ismute);

    bool isPlaying() const;
    void setIsPlaying(const bool isplaying);


    Q_INVOKABLE void selectMusic() const;
    ~MusicData();

signals:

    void pathChanged();
    void nameChanged();
    void instrumentalChanged();
    void gainChanged();
    void metaDataChanged();
    void speakerChanged();
    void positionchanged();
public slots:

private:
    QUrl m_path;
    QString m_name;
    Instrumental* m_instrumental;
    double m_volume;
    QList<PartData*> m_parts;
    QVariant m_metadata;
 };
#endif // MUSICDATA_H
