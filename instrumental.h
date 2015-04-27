#ifndef INSTRUMENTAL_H
#define INSTRUMENTAL_H

#include <QObject>

class Instrumental : public QObject
{
      Q_OBJECT
      Q_PROPERTY(float gain READ gain WRITE setGain NOTIFY gainChanged) 
     	Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged) 
      Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged) 
      Q_PROPERTY(float z READ z WRITE setZ NOTIFY zChanged) 
      Q_PROPERTY(bool isMute READ isMute WRITE setIsMute NOTIFY isMuteChanged) 

public:
      explicit Instrumental(QObject *parent = 0);
      explicit Instrumental(const QString &path,QObject *parent = 0);
      
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

~Instruments();

si

}
#endif //INSTRUMENTAL_H
