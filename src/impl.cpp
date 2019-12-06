/*
 * Complex.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */
#include <iostream>
#include <sstream>
#include "impl.h"

bool operator==(const Complex &op1,const Complex &op2)
{
  return ((op1.getRe()==op2.getRe())&&(op1.getIm()==op2.getIm()));
}

Complex Complex::operator+=( const Complex& op) {
    _re += op.getRe();
    _im += op.getIm();
    return *this;
}

Complex Complex::operator-=( const Complex& op) {
    _re -= op.getRe();
    _im -= op.getIm();
    return *this;
}

#define UNUSED( a) (void)(a)

Complex operator "" _i( const char* str,  size_t size) {
    UNUSED( size);
    std::stringstream s(str);
    int re, im;
    s >> re >> im;
    return Complex( re, im);
}

