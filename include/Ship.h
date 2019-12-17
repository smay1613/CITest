/*
 * Ship.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: Pavel Tsytovich
 */

#ifndef LAB8_SHIP_H_
#define LAB8_SHIP_H_

#include <IShip.h>

class Ship : public IShip{
private:
	bool _status;
	Point _coord;
public:
	Ship(int x,int y);
	~Ship();
	bool fire(int x,int y) override;
	bool getStatus() override;
	Point getPoint() override;
protected:
	virtual void setStatus(bool value);
};

#endif /* LAB8_SHIP_H_ */
