#pragma once

/*
 * Complex.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#ifndef LAB5_COMPLEX_H_
#define LAB5_COMPLEX_H_

class Complex {
private:
    int _re;
    int _im;
public:
    constexpr Complex(int re,int im): _re(re),_im(im) {}

//    virtual ~Complex();
    constexpr int getRe() const { return _re;}
    constexpr int getIm() const { return _im;}
    constexpr Complex operator+(const Complex& op) { return Complex( _re + op.getRe(), _im + op.getIm()); }
    constexpr Complex operator-(const Complex& op) { return Complex( _re - op.getRe(), _im - op.getIm()); }

    Complex operator+=( const Complex& op);
    Complex operator-=( const Complex& op);

};

bool operator==(const Complex &op1,const Complex &op2);
Complex operator "" _i( const char* str, size_t size);


#endif /* LAB5_COMPLEX_H_ */
