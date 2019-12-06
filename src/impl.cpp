#include "impl.h"
constexpr Complex::Complex(int re,int im): _re(re),_im(im) {
}

//Complex::~Complex() {
//}

Complex Complex::operator+(const Complex& op)
{
    return Complex {getRe() + op.getRe(), getIm() + op.getIm()};
}

Complex Complex::operator-(const Complex &op)
{
    return Complex {getRe() - op.getRe(), getIm() - op.getIm()};
}
bool operator==(const Complex &op1,const Complex &op2)
{
  if ((op1.getRe() == op2.getRe()) && (op1.getIm() == op2.getIm()))
  {
    return true;
  }
  else
  {
    return false;
  }
}
