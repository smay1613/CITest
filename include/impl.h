#pragma once
/*
 * LinkedList.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#ifndef LAB6_LINKEDLIST_H_
#define LAB6_LINKEDLIST_H_
#include <iostream>

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

enum Orientation {HORIZONTAL,VERTICAL};

class BigShip: public IShip {
private:
    Orientation _orientation;
    int _countDeck;
    IShip** _decks;
public:
    BigShip(int x,int y,Orientation o,int deck);
    virtual ~BigShip() override;
    bool fire(int x,int y) override;
    bool getStatus() override;
    Point getPoint() override;
    int getDeck();
    Orientation getOrientation();
};



#endif /* LAB6_LINKEDLIST_H_ */

