/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include "impl.h"
#include <exception>
#include <stdexcept>

Integer::Integer(int value) : _value {value} {
    if ((value < 0)&&( value > 9)) {
        throw std::out_of_range("out of range value");
    }
}

Integer::~Integer() {
}

Integer::operator char*() {
    auto val = map.begin();
    if ( val = map.find(_value), val != map.end()) {
        return (val->second).c_str();
    }
    return nullptr;
}
