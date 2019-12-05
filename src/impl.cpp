#include "impl.h"

constexpr Complex::Complex(int re,int im): _re(re),_im(im) {
}

//Complex::~Complex() {
//}

Complex Complex::operator+(const Complex& op)
{
    return Complex(getRe() + op.getRe(), getIm() + op.getIm());
}

Complex Complex::operator-(const Complex &op)
{
    return Complex(getRe() - op.getRe(), getIm() - op.getIm());
}

bool operator==(const Complex &op1,const Complex &op2)
{
    return (op1.getRe() == op2.getRe()) && (op1.getIm() == op2.getIm());
}

void Complex::operator +=(const Complex &op2)
{
    _re += op2.getRe();
    _im += op2.getIm();
}

std::ostream & operator<<(std::ostream & os, const Complex comp)
{
    bool positiveIm = comp.getIm() >= 0;
    os << comp.getRe() << (positiveIm ? " + " : " - ") << comp.getIm() << "i" << std::endl;
    return os;
}
