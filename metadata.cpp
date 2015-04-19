#include "metadata.h"

MetaData::MetaData(QObject *parent) : QObject(parent)
{

}

MetaData::MetaData(const QUrl &path, QObject *parent):QObject(parent)
{
        TagLib::MPEG::File f(path.toLocalFile().toLocal8Bit().data());
        m_tag = f.ID3v2Tag();
}

MetaData::~MetaData()
{

}

