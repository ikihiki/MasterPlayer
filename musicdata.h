#ifndef MUSICDATA_H
#define MUSICDATA_H

#include <QObject>
#include <QDir>
#include <QUrl>
#include <QVariant>
#include<QQmlListProperty>

#include "metadata.h"
#include"partdata.h"

class MusicData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl instrumental READ instrumental WRITE setInstrumental NOTIFY instrumentalChanged)
    Q_PROPERTY(double gain READ gain WRITE setGain NOTIFY gainChanged)
    Q_PROPERTY(QQmlListProperty<PartData> Parts READ Parts)
    Q_PROPERTY(QVariant MetaData READ metaData WRITE setMetaData NOTIFY MetaDataChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionchanged)

public:
    explicit MusicData(QObject *parent = 0);
    explicit MusicData(const QUrl &path, QObject *parent=0);

    QUrl path() const;
    void setPath(const QUrl &path);

    QString name() const;
    void setName(const QString &name);

    QUrl instrumental() const;
    void setInstrumental(const QUrl &inst);

    double gain() const;
    void setGain(const double volume);

	QQmlListProperty<PartData> Parts() const;

    QVariant metaData() const;
    void setMetaData(const QVariant &metadata);

    Q_INVOKABLE void selectMusic() const;
    ~MusicData();

signals:

    void PathChanged();
    void NameChanged();
    void InstrumentalChanged();
    void VolumeChanged();
    void MetaDataChanged();
    void speakerChanged();
public slots:

private:
    QUrl m_path;
    QString m_name;
    QUrl m_instrumental;
    double m_volume;
    Qlist<PartData*> m_parts;
    QVariant m_metadata;
 };
#endif // MUSICDATA_H
