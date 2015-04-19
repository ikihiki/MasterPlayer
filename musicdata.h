#ifndef MUSICDATA_H
#define MUSICDATA_H

#include <QObject>
#include <QDir>
#include <QUrl>
#include <QVariant>

#include "metadata.h"
#include"partdata.h"

class MusicData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl Path READ Path WRITE setPath NOTIFY PathChanged)
    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
    Q_PROPERTY(QUrl Instrumental READ Instrumental WRITE setInstrumental NOTIFY InstrumentalChanged)
    Q_PROPERTY(double Volume READ Volume WRITE setVolume NOTIFY VolumeChanged)
    Q_PROPERTY(QVariantList Parts READ Parts WRITE setParts NOTIFY PartsChanged)
    Q_PROPERTY(QVariant MetaData READ metaData WRITE setMetaData NOTIFY MetaDataChanged)

public:
    explicit MusicData(QObject *parent = 0);
    explicit MusicData(const QUrl &path, QObject *parent=0);

    QUrl Path() const;
    void setPath(const QUrl &path);

    QString Name() const;
    void setName(const QString &name);

    QUrl Instrumental() const;
    void setInstrumental(const QUrl &inst);

    double Volume() const;
    void setVolume(const double volume);

    QVariantList Parts() const;
    void setParts(const QVariantList &parts);

    QVariant metaData() const;
    void setMetaData(const QVariant &metadata);

    Q_INVOKABLE void selectMusic() const;
    ~MusicData();

signals:

    void PathChanged();
    void NameChanged();
    void InstrumentalChanged();
    void VolumeChanged();
    void PartsChanged();
    void MetaDataChanged();
    void speakerChanged();
public slots:

private:
    QUrl m_path;
    QString m_name;
    QUrl m_instrumental;
    double m_volume;
    QVariantList m_parts;
    QVariant m_metadata;
 };
#endif // MUSICDATA_H
