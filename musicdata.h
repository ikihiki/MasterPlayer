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
#include "listener.h"

class MusicData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl path READ path)
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(Instrumental* instrumental READ instrumental)
	Q_PROPERTY(Listener listener READ listener)
    Q_PROPERTY(QQmlListProperty<PartData> parts READ parts)
    Q_PROPERTY(QVariant metaData READ metaData)
    Q_PROPERTY(float duration READ duration)
    Q_PROPERTY(float loadedPosition READ loadedPosition NOTIFY loadedPositionChanged)
    Q_PROPERTY(float position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(bool isLoadFinished READ isLoadFinished NOTIFY isLoadFinishedChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged)

public:
    explicit MusicData(QObject *parent = 0);
    explicit MusicData(const QUrl &path, QObject *parent=0);

    QUrl path() const;

    QString name() const;

	Instrumental* instrumental() const;

    Listener* listener() const;

    QQmlListProperty<PartData> parts();

    QVariant metaData() const;

    float duration() const;

    float loadedPosition() const;

    float position() const;
    void setPosition(float position);

    bool isLoadFinished() const;

    bool isPlaying() const;
    void setIsPlaying(const bool isplaying);


    Q_INVOKABLE void selectMusic();

	Q_INVOKABLE void play();
	Q_INVOKABLE void pause();
	Q_INVOKABLE void stop();

    void load();
    void unload();

    ~MusicData();

signals:
	void loadedPositionChanged();
	void positionChanged();
	void isLoadFinishedChanged();
	void isPlayingChanged();
public slots:

private slots :
void loop();

private:
    QUrl m_path;
    QString m_name;
    Instrumental* m_instrumental;
	Listener* m_listener;
    QList<PartData*> m_parts;
    QVariant m_metadata;
    float m_position=0;
    bool m_isPlaying = false;
    QTimer *m_timer;
 };

Q_DECLARE_METATYPE(MusicData*)

#endif // MUSICDATA_H
