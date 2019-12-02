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
	Complex(int re = 0,int im = 0);
	virtual ~Complex();
	int getRe() const { return _re;}
	int getIm() const { return _im;}
	 Complex operator+(const Complex& op);

	 Complex operator-(const Complex &op);

};

bool operator==(const Complex &op1,const Complex &op2);
#endif /* LAB5_COMPLEX_H_ */
