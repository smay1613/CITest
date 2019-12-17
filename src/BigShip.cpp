/*
 * BigShip.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <BigShip.h>

BigShip::BigShip(int x,int y,Orientation o,int deck)
{
    _orientation = o;
    _countDeck = deck;

    _decks = new Ship*[deck];
    if (o)
    {
        for (int i = 0; i < deck; i++)
        {
            _decks[i] = new Ship(x,y+i);
        }
    }
    else
    {
        for (int i = 0; i < deck; i++)
        {
            _decks[i] = new Ship(x+i,y);
        }
    }
}

BigShip::~BigShip()
{
    for (int i = 0; i < _countDeck; i++)
        delete _decks[i];
    delete _decks;
}

bool BigShip::fire(int x,int y)
{
    for (int i = 0; i < _countDeck; i++)
    {
        if(_decks[i]->fire(x,y))
            return true;
    }
    return false;
}
bool BigShip::getStatus()
{
    for (int i = 0; i < _countDeck; i++)
    {
        if(_decks[i]->getStatus())
            return true;
    }
    return false;
}
Point BigShip::getPoint()
{
	return Point();
}

