#include"instrumental.h"

Instrumental::Instrumental(QObject *parent):QObject(parent)
{

}

Instrumental::Instrumental(const QString &path, QObject *parent) : QObject(parent)
{

}

QUrl Instrumental::instrumental() const
{
    return QUrl();
}
void Instrumental::setInstrumental(const QUrl &inst)
{

}

float Instrumental::gain() const
{
    return 0;
}
void Instrumental::setGain(const float gain)
{

}

float Instrumental::x() const
{
    return 0;
}
void Instrumental::setX(const float x)
{

}

float Instrumental::y() const
{
    return 0;
}
void Instrumental::setY(const float y)
{

}

float Instrumental::z() const
{
    return 0;
}
void Instrumental::setZ(const float z)
{

}

bool Instrumental::isMute() const
{
    return true;
}
void Instrumental::setIsMute(const bool ismute)
{

}


Instrumental::~Instrumental()
{

}
