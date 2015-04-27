#ifndef SPEAKER_H
#define SPEAKER_H

#define BUFFER_COUNT 4

#include <QObject>
#include <QtMultimedia>
#include <QVector>
#include <QtConcurrent>
#include <QUrl>
#include <al.h>
#include <alc.h>



class Speaker : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(bool isReady READ isReady WRITE setIsReady NOTIFY isReadyChanged)
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(float z READ z WRITE setZ NOTIFY zChanged)
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(qint64 loadedPosition READ loadedPosition WRITE setLoadedPosition NOTIFY loadedPositionChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(bool isLoadFinished READ isLoadFinished WRITE setIsLoadFinished NOTIFY isLoadFinishedChanged)
    Q_PROPERTY(bool isMute READ isMute WRITE setIsMute NOTIFY isMuteChanged)
    Q_PROPERTY(float gain READ gain WRITE setGain NOTIFY gainChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged)

public:

    enum State
    {
        loading,
        playing,
        buffering,
        paused,
        stopped,
        error
    };

    explicit Speaker(QObject *parent = 0);

    Speaker(Speaker &obj);

    QUrl source() const;
    void setSource(const QUrl &source);

    bool isReady() const;
    void setIsReady(const bool ready);

    State state() const;
    void setState(const State state);

    float x() const;
    void setX(const float x);

    float y() const;
    void setY(const float y);

    float z() const;
    void setZ(const float z);

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

    float gain() const;
    void setGain(const float gain);

    bool isPlaying() const;
    void setIsPlaying(const bool isplaying);

    ~Speaker();




signals:
    void sourceChanged();
    void isReadyChanged();
    void stateChanged();
    void xChanged();
    void yChanged();
    void zChanged();
    void durationChanged();
    void loadedPositionChanged();
    void positionChanged();
    void isLoadFinishedChanged();
    void isMuteChanged();
    void gainChanged();
    void isPlayingChanged();

public slots:
    void play();
    void pause();
    void stop();
    void load();
    void unload();

private slots:
    void getError(QAudioDecoder::Error error);
    void getBufferReady();
    void getStateChanged(QAudioDecoder::State state);
    void getPositionChanged(qint64 position);
    void getFinished();
    void loop();

private:
    QAudioDecoder *m_decoder;
    QAudioBuffer m_buffer;

    QUrl m_audioSource;

    QVector<ALuint> m_alBuffer;
    ALuint m_source = 0;

    bool m_isReady = false;
    bool m_isBufferReady = false;
    bool m_isBufferAvailable = false;

    State m_state=State::stopped;

    float m_x=0.0f;
    float m_y=0.0f;
    float m_z=0.0f;

    qint64 m_loadedPosition=0;
    quint64 m_position=0;
    bool m_isLoaded=false;
    bool m_isMute=false;
    float m_gain=1.0f;

    QTimer *m_timer;

    void setisReady(const bool ready);
    void setstate(const State state);

};

#endif // SPEAKER_H
