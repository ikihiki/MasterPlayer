#ifndef INSTRUMENTAL_H
#define INSTRUMENTAL_H

#include <QObject>
#include <QUrl>

#include "speaker.h"

class Instrumental : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl instrumental READ instrumental WRITE setInstrumental NOTIFY instrumentalChanged)
    Q_PROPERTY(float gain READ gain WRITE setGain NOTIFY gainChanged)
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(float z READ z WRITE setZ NOTIFY zChanged)
    Q_PROPERTY(bool isMute READ isMute WRITE setIsMute NOTIFY isMuteChanged)

public:
      explicit Instrumental(QObject *parent = 0);
      explicit Instrumental(const QString &path,QObject *parent = 0);
      

    QUrl instrumental() const;
    void setInstrumental(const QUrl &inst);

    float gain() const;
	void setGain(const float gain);

	float x() const;
	void setX(const float x);

	float y() const;
	void setY(const float y);

	float z() const;
	void setZ(const float z);

	bool isMute() const;
	void setIsMute(const bool ismute);

	Speaker* getSpeaker() const;

~Instrumental();

signals:
    void instrumentalChanged();
    void gainChanged();
    void xChanged();
    void yChanged();
    void zChanged();
    void isMuteChanged();


private:

	Speaker* m_speaker;

};

Q_DECLARE_METATYPE(Instrumental*)

#endif //INSTRUMENTAL_H
