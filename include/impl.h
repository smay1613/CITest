#pragma once

class Complex {
private:
    int _re;
    int _im;
public:
    constexpr Complex(int re = 0,int im = 0);
    //virtual ~Complex();
    constexpr int getRe() const { return _re;}
    constexpr int getIm() const { return _im;}
    Complex operator+(const Complex &op);

    Complex operator-(const Complex &op);

};

bool operator==(const Complex &op1,const Complex &op2);
