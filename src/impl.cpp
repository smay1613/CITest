/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include "impl.h"

Ship::Ship(int x,int y) : _coord {x,y} {
}

Ship::~Ship() {}

bool Ship::getStatus() {
    return _status;
}

bool Ship::fire(int x,int y) {
    if ( (_coord.x == x)&&
         (_coord.y == y)) {
        _status = false;
        return true;
    }
    return false;
}

void Ship::setStatus(bool value) {
    _status = value;
}

Point Ship::getPoint() {
    return Point();
}

BigShip::BigShip(int x,int y, Orientation o, int deck) {
    _countDeck = deck;
    _decks = new IShip*[_countDeck];
    for( int i = 0; i < deck; ++i) {
        _decks[i] =
            new Ship { (HORIZONTAL == o)?x+i:x,
                       (VERTICAL == o)?y+i:y};
    }
}

BigShip::~BigShip() {
    delete [] _decks;
}

bool BigShip::fire(int x,int y) {
    for(int i = 0; i < _countDeck; ++i) {
        if (_decks[i]->fire( x, y))
            return true;
    }
    return false;
}

bool BigShip::getStatus() {
    for(int i = 0; i < _countDeck; ++i) {
        if (_decks[i]->getStatus())
            return true;
    }
    return false;
}

Point BigShip::getPoint() {
    return Point();
}

