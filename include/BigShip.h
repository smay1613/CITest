/*
 * BigShip.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#ifndef LAB8_BIGSHIP_H_
#define LAB8_BIGSHIP_H_

#include <Ship.h>
#include <IShip.h>

enum Orientation {HORIZONTAL,VERTICAL};

class BigShip: public IShip {
private:
	Orientation _orientation;
	int _countDeck;
        Ship** _decks;
public:
	BigShip(int x,int y,Orientation o,int deck);
	virtual ~BigShip() override;
	bool fire(int x,int y) override;
	bool getStatus() override;
	Point getPoint() override;
	int getDeck();
	Orientation getOrientation();
};

#endif /* LAB8_BIGSHIP_H_ */
