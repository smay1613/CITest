#include "impl.h"

Complex::Complex(int re,int im): _re(re),_im(im) {
}

Complex::~Complex() {
}

Complex Complex::operator+(const Complex& op)
{
	_re += op.getRe();
	_im += op.getIm();

	return Complex();
}

Complex Complex::operator-(const Complex &op)
{
	_re -= op.getRe();
	_im -= op.getIm();

	return Complex();
}

bool operator==(const Complex &op1,const Complex &op2)
{
	if ((op1.getRe() == op2.getRe()) && (op1.getIm() == op2.getIm()))
	{
		return true;
	}
	return false;
}
