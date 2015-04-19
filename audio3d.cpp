#include "audio3d.h"

Audio3D::Audio3D(QObject *parent) : QObject(parent)
{
    m_device = alcOpenDevice(nullptr);
    m_context = alcCreateContext(m_device,nullptr);
    alcMakeContextCurrent(m_context);
}

Audio3D::~Audio3D()
{
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(m_context);
    alcCloseDevice(m_device);
}

