#ifndef SPEAKER_H
#define SPEAKER_H

#define BUFFER_COUNT 4

#include <QObject>
#include <QtMultimedia>
#include <QVector>
#include <QUrl>
#include <al.h>
#include <alc.h>



class Speaker : public QObject
{
    Q_OBJECT

public:

    enum State
    {
        playing,
        paused,
        stopped
    };

    explicit Speaker(QObject *parent = 0);

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

    float duration() const;

    float loadedPosition() const;

    float position() const;
    void setPosition(const float position);

    bool isLoadFinished() const;

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

    void setisReady(const bool ready);
    void setstate(const State state);

};

#endif // SPEAKER_H
