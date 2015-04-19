#ifndef AUDIO3D_H
#define AUDIO3D_H

#include <QObject>
#include <al.h>
#include <alc.h>

class Audio3D : public QObject
{
    Q_OBJECT
public:
    explicit Audio3D(QObject *parent = 0);
    ~Audio3D();


signals:

public slots:

private:
    ALCdevice* m_device;
    ALCcontext* m_context;
};

#endif // AUDIO3D_H
