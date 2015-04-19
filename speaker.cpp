#include "speaker.h"

Speaker::Speaker(QObject *parent) : QObject(parent)
{
    m_decoder = new QAudioDecoder(this);
    connect(m_decoder,SIGNAL(bufferReady()),this,SLOT(getBufferReady()));
    connect(m_decoder,SIGNAL(error(QAudioDecoder::Error)),this,SLOT(getError(QAudioDecoder::Error)));
    connect(m_decoder,SIGNAL(stateChanged(QAudioDecoder::State)),this,SLOT(getStateChanged(QAudioDecoder::State)));
    connect(m_decoder,SIGNAL(positionChanged(qint64)),this,SLOT(getPositionChanged(qint64)));
    connect(m_decoder,SIGNAL(finished()),this,SLOT(getFinished()));
    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(loop()));
}

Speaker::Speaker(Speaker &obj)
{

}

QUrl Speaker::source() const
{
    return m_audioSource;
}

void Speaker::setSource(const QUrl &source)
{
    if(m_audioSource!=source)
    {
        if(source.isLocalFile())
        {
            m_audioSource=source;
            emit sourceChanged();
            m_decoder->setSourceFilename(source.toLocalFile());
            m_isBufferAvailable = m_decoder->bufferAvailable();
        }
    }
}

bool Speaker::isReady() const
{
    return m_isReady;
}

void Speaker::setIsReady(const bool ready)
{}

void Speaker::setisReady(const bool ready)
{
    if(ready!=m_isReady)
    {
        m_isReady = ready;
        emit isReadyChanged();
    }
}

Speaker::State Speaker::state() const
{
    return m_state;
}

void Speaker::setState(const State state)
{}

void Speaker::setstate(const State state)
{
    if(state!=m_state)
    {
        m_state=state;
        emit stateChanged();
        emit isPlayingChanged();
    }
}

float Speaker::x() const
{
    return m_x;
}

void Speaker::setX(const float x)
{
    if(x!=m_x)
    {
        m_x=x;
        if(m_source!=NULL)
        {
            alSource3f(m_source,AL_POSITION,m_x,m_y,m_z);
        }
        emit xChanged();
    }
}

float Speaker::y() const
{
    return m_y;
}

void Speaker::setY(const float y)
{
    if(y!=m_y)
    {
        m_y=y;
        if(m_source!=NULL)
        {
            alSource3f(m_source,AL_POSITION,m_x,m_y,m_z);
        }
        emit yChanged();
    }
}

float Speaker::z() const
{
    return m_z;
}

void Speaker::setZ(const float z)
{
    if(z!=m_z)
    {
        m_z=z;
        if(m_source!=NULL)
        {
            alSource3f(m_source,AL_POSITION,m_x,m_y,m_z);
        }
        emit zChanged();
    }
}

qint64 Speaker::duration() const
{
    return m_decoder->duration();
}

void Speaker::setDuration(const quint64 duration){}

qint64 Speaker::loadedPosition() const
{
    return m_loadedPosition;
}

void Speaker::setLoadedPosition(const qint64 position){}

qint64 Speaker::position() const
{
    return m_position;
}

void Speaker::setPosition(const qint64 position)
{
    if(position>0&&position!=m_position)
    {
        if(position>duration())
        {
            return;
        }
        if(position>loadedPosition())
        {
            setstate(State::buffering);
            m_position=position;
            return;
        }
        alSourcef(m_source,AL_SEC_OFFSET,position/1000.0f);
        float tmp;
        alGetSourcef(m_source,AL_SEC_OFFSET,&tmp);
        m_position=tmp*1000;
        emit positionChanged();
    }
}

bool Speaker::isLoadFinished() const
{
    return m_isLoaded;
}
void Speaker::setIsLoadFinished(const bool isfinishied){}

bool Speaker::isMute() const
{
    return m_isMute;
}
void Speaker::setIsMute(const bool ismute)
{
    if(ismute!=m_isMute)
    {
        m_isMute=ismute;
        if(m_isMute)
        {
            alSourcef(m_source,AL_GAIN,0.0f);
        }else
        {
            alSourcef(m_source,AL_GAIN,m_gain);
        }
        emit isMuteChanged();
    }
}

float Speaker::gain() const
{
    return m_gain;
}
void Speaker::setGain(const float gain)
{
    if(gain!=m_gain)
    {
        alSourcef(m_source,AL_GAIN,gain);
        alGetSourcef(m_source,AL_GAIN,&m_gain);
        emit gainChanged();
    }
}

bool Speaker::isPlaying() const
{
    if(state()==State::playing)
    {
        return true;
    }
    else{
        return false;
    }
}

void Speaker::setIsPlaying(const bool isplaying)
{
    if(isplaying)
    {
        play();
    }else
    {
        pause();
    }
    emit isPlayingChanged();
}


void Speaker::play()
{
    load();
    setstate(State::playing);
    m_timer->start(100);

}

void Speaker::pause()
{
    setstate(State::paused);
}

void Speaker::stop()
{
    setstate(State::stopped);
}

void Speaker::loop()
{
        ALint state;
        alGetSourcei(m_source,AL_SOURCE_STATE,&state);

        switch(m_state)
        {
        case State::loading:
            switch(state)
            {
            case AL_INITIAL:
                break;

            case AL_PLAYING:
                alSourceStop(m_source);
                break;

            case AL_PAUSED:
                break;

            case AL_STOPPED:
                break;
            }
            break;

        case State::playing:
            switch(state)
            {
            case AL_INITIAL:
                alSourcePlay(m_source);
                break;

            case AL_PLAYING:
                break;

            case AL_PAUSED:
                alSourcePlay(m_source);
                break;

            case AL_STOPPED:
                alSourcePlay(m_source);
                break;
            }
            float tmp;
            alGetSourcef(m_source,AL_SEC_OFFSET,&tmp);
            m_position=tmp*1000;
            emit positionChanged();

            break;

        case State::buffering:
            switch(state)
            {
            case AL_INITIAL:
                break;

            case AL_PLAYING:
                alSourceStop(m_source);
                break;

            case AL_PAUSED:
                break;

            case AL_STOPPED:
                break;
            }

            if(loadedPosition()>position())
            {
                alSourcef(m_source,AL_SEC_OFFSET,m_position/1000.0f);
                float tmp;
                alGetSourcef(m_source,AL_SEC_OFFSET,&tmp);
                m_position=tmp*1000;
                emit positionChanged();
                setstate(State::playing);
            }

            break;

        case State::paused:
            switch(state)
            {
            case AL_INITIAL:
                setstate(State::stopped);
                break;

            case AL_PLAYING:
                alSourcePause(m_source);
                break;

            case AL_PAUSED:
                break;

            case AL_STOPPED:
                setstate(State::stopped);
                break;
            }
            break;

        case State::stopped:
            switch(state)
            {
            case AL_INITIAL:
                break;

            case AL_PLAYING:
                alSourceStop(m_source);
                break;

            case AL_PAUSED:
                alSourceStop(m_source);
                break;

            case AL_STOPPED:
                break;
            }
            break;
        }
}

void Speaker::load()
{
    setstate(State::loading);
    if(!m_isReady)
    {
        if( alcGetCurrentContext()==NULL)
        {
            qDebug()<<"error";
        }
        alGenSources(1,&m_source);
        ALenum error;
        if ((error = alGetError()) != AL_NO_ERROR) {
          qDebug()<<error;
        }
        alSource3f(m_source,AL_POSITION,m_x,m_y,m_z);
        m_decoder->start();
        setisReady(true);
        emit durationChanged();
    }
}

void Speaker::unload()
{
    if(m_isReady)
    {
        setisReady(false);
    }
}

void Speaker::getError(QAudioDecoder::Error error)
{
    qDebug()<<error;
    qDebug()<<m_decoder->errorString();
}

void Speaker::getBufferReady()
{
    QAudioBuffer buffer = m_decoder->read();
    ALuint albuff;
    alGenBuffers(1,&albuff);

    ALenum format=0;

    if(buffer.format().channelCount()==1)
    {
        if(buffer.format().sampleSize()==8)
        {
            format=AL_FORMAT_MONO8;
        }
        else if(buffer.format().sampleSize()==16)
        {
            format=AL_FORMAT_MONO16;
        }
        else
        {
            qDebug()<<"Can not read.";
        }
    }else if(buffer.format().channelCount()==2)
    {
        if(buffer.format().sampleSize()==8)
        {
            format=AL_FORMAT_STEREO8;

        }
        else if(buffer.format().sampleSize()==16)
        {
            format=AL_FORMAT_STEREO16;
        }
        else
        {
            qDebug()<<"Can not read.";
        }

    }
    else
    {
        qDebug()<<"Can not read.";
    }

    if(format!=0)
    {
        alBufferData(albuff,format,buffer.data(),buffer.byteCount(),buffer.format().sampleRate());
        m_alBuffer.append(albuff);
        alSourceQueueBuffers(m_source,1,&albuff);
    }

    if(state()==State::playing)
    {

    }
}

void Speaker::getStateChanged(QAudioDecoder::State state)
{
    qDebug()<<state;
}

void Speaker::getPositionChanged(qint64 position)
{
    m_loadedPosition=position;
    emit loadedPositionChanged();
}

void Speaker::getFinished()
{
    m_isLoaded=true;
    emit isLoadFinishedChanged();
}

Speaker::~Speaker()
{
    alDeleteSources(1,&m_source);
    alDeleteBuffers(m_alBuffer.size(),&m_alBuffer[0]);
    ALenum error;
    if ((error = alGetError()) == AL_NO_ERROR) {
      qDebug()<<error;
    }
}

