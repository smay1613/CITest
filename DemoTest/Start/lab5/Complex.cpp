/*
 * Complex.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <lab5/Complex.h>

Complex::Complex(int re,int im): _re(re),_im(im) {
}

Complex::~Complex() {
}

Complex Complex::operator+(const Complex& op)
{
 return Complex();
}

Complex Complex::operator-(const Complex &op)
{
  return Complex();
}
bool operator==(const Complex &op1,const Complex &op2)
{
  return false;
}
