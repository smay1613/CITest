/*
 * Complex.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include "impl.h"

Complex::Complex(int re,int im): _re(re),_im(im) {
}

Complex::~Complex() {
}

Complex Complex::operator+(const Complex& op)
{
  return Complex( _re + op.getRe(), _im + op.getIm());
}

Complex Complex::operator-(const Complex &op)
{
  return Complex( _re - op.getRe(), _im - op.getIm());
}
bool operator==(const Complex &op1,const Complex &op2)
{
  return ((op1.getRe()==op2.getRe())&&(op1.getIm()==op2.getIm()));
}

