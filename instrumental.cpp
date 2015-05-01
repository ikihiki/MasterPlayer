#include"instrumental.h"

Instrumental::Instrumental(QObject *parent):QObject(parent)
{
	m_speaker = new Speaker(this);
}

Instrumental::Instrumental(const QString &path, QObject *parent) : QObject(parent)
{
	m_speaker = new Speaker(this);
	setInstrumental(QUrl::fromLocalFile(path));
}

QUrl Instrumental::instrumental() const
{
	return m_speaker->source();
}
void Instrumental::setInstrumental(const QUrl &inst)
{
	m_speaker->setSource(inst);
	emit instrumentalChanged();
}

float Instrumental::gain() const
{
	return m_speaker->gain();
}
void Instrumental::setGain(const float gain)
{
	if (m_speaker->gain() != gain)
	{
		m_speaker->setGain(gain);
		emit gainChanged();
	}
}

float Instrumental::x() const
{
	return m_speaker->x();
}
void Instrumental::setX(const float x)
{
	if (x != m_speaker->x())
	{
		m_speaker->setX(x);
		emit xChanged();
	}
}

float Instrumental::y() const
{
	return m_speaker->y();
}
void Instrumental::setY(const float y)
{
	if (y != m_speaker->y())
	{
		m_speaker->setY(y);
		emit yChanged();
	}
}

float Instrumental::z() const
{
	return m_speaker->z();
}
void Instrumental::setZ(const float z)
{
	if (z != m_speaker->z())
	{
		m_speaker->setZ(z);
		emit zChanged();
	}
}

bool Instrumental::isMute() const
{
	return m_speaker->isMute();
}
void Instrumental::setIsMute(const bool ismute)
{
    if (m_speaker->isMute() != ismute)
	{
		m_speaker->setIsMute(ismute);
		emit isMuteChanged();
	}
}

Speaker* Instrumental::getSpeaker() const
{
    return m_speaker;
}


Instrumental::~Instrumental()
{

}
