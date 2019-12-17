/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include "impl.h"

Ship::Ship(int x,int y)
{

}

Ship::~Ship()
{
}

bool Ship::getStatus()
{
    return true;
}

bool Ship::fire(int x,int y)
{
    return false;
}

void Ship::setStatus(bool value)
{

}

Point Ship::getPoint()
{
    return Point();
}

BigShip::BigShip(int x,int y,Orientation o,int deck)
{
}

BigShip::~BigShip()
{
}

bool BigShip::fire(int x,int y)
{
 return false;
}
bool BigShip::getStatus()
{
 return true;
}
Point BigShip::getPoint()
{
    return Point();
}

