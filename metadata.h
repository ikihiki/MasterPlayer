#ifndef METADATA_H
#define METADATA_H

#include <QObject>
#include <QUrl>
#include <QTextCodec>
#include <mpegfile.h>
#include <id3v2tag.h>

using namespace std;

class MetaData : public QObject
{
    Q_OBJECT
public:
    explicit MetaData(QObject *parent = 0);
    explicit MetaData(const QUrl &path, QObject *parent = 0);

    ~MetaData();

signals:

public slots:

private:
    TagLib::ID3v2::Tag *m_tag;
};

#endif // METADATA_H
