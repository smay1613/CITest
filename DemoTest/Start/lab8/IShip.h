/*
 * IShip.h
 *
 *  Created on: 31 џэт. 2018 у.
 *      Author: ptsytovich
 */

#ifndef LAB8_ISHIP_H_
#define LAB8_ISHIP_H_

struct Point
{
	int x,y;
};

class IShip {
public:
	virtual ~IShip() {};
	virtual bool fire(int x,int y) = 0;
    virtual bool getStatus() = 0;
	virtual Point getPoint() = 0;
};

#endif /* LAB8_ISHIP_H_ */
