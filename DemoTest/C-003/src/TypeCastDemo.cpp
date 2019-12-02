/*
 * TypeCastDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"
#include <cmath>
class Dummy {
    double i,j;
};

class Addition {
    int x,y;
  public:
    Addition (int a, int b) { x=a; y=b; }
    int result() { return x+y;}
};

TEST(Module9,ProblemCCastStyle)
{
   Dummy d;
   Addition * padd;
   padd = (Addition*) &d;
   padd->result();//What is object!?

}
//---------------------------------------------------------

void ChangeConstVar(const int* pt,int n)
{
	int *pc = const_cast<int*>(pt);
	*pc+=n;
}
TEST(Module9,ConstCast)
{
	const int p = 300;
	ChangeConstVar(&p,1);
	ASSERT_EQ(p,301);
}
//----------------------------------------------------------

class FooStaticCast
{
	int value;
public:
	FooStaticCast(char *src): value(src[0]-'0') {}
	FooStaticCast(int src) : value(src) {}
	int GetValue() const { return value;}
};

TEST(Module9,StaticCast)
{
	char *x = "2";
	char *y ="3";
	int z = 4;
	FooStaticCast fx = static_cast<FooStaticCast>(x);
	FooStaticCast fy = static_cast<FooStaticCast>(y);
	FooStaticCast fe = static_cast<FooStaticCast>(z);
	ASSERT_EQ(fx.GetValue(),2);
	ASSERT_EQ(fy.GetValue(),3);
	ASSERT_EQ(fe.GetValue(),4);

}
//---------------------------------------------------------
class BaseDynCast
{
public:
	virtual int GetValue() { return 2;}
};
class DerivedDynCast : public BaseDynCast
{
public:
	int GetValue() override {return 3;}
};

TEST(Module9,DynamicCast)
{
	BaseDynCast *bdc = new BaseDynCast;
	DerivedDynCast *ddc = new DerivedDynCast;

	BaseDynCast *a = dynamic_cast<BaseDynCast*>(ddc);
	DerivedDynCast *b = dynamic_cast<DerivedDynCast*>(bdc);
	ASSERT_TRUE(a != nullptr);
	ASSERT_TRUE(b == nullptr);
}

//--------------------------------------------------------------

class BaseReinterpretCast
{
private:
	int Value;
public:
	BaseReinterpretCast() : Value(0){};
	BaseReinterpretCast(int v) : Value(v) {}
   int GetValue() { return Value;}
};

class DerivedReinterpretCast : public BaseReinterpretCast
{
	int Value;
public:
	DerivedReinterpretCast(int v) : Value(v+4) {}
	int GetValue()  { return Value;}
};

TEST(Module9,ReintepretCast)
{
	BaseReinterpretCast *brc = new BaseReinterpretCast(10);
	DerivedReinterpretCast *drc = new DerivedReinterpretCast(20);

	BaseReinterpretCast *a = reinterpret_cast<BaseReinterpretCast*>(drc);
	DerivedReinterpretCast *b = reinterpret_cast<DerivedReinterpretCast*>(brc);

	ASSERT_EQ(a->GetValue(),0);
	//ASSERT_EQ(b->GetValue(),10);
}
//-----------------------------------------------------------------------------------
class OverloadCastOperator
{
	int v1;
	int v2;
public:
	OverloadCastOperator(int v1,int v2): v1(v1),v2(v2) {}
	operator long(){ return v1+v2;}
	operator int() { return v1;}
};

TEST(Module9,OverloadCastOperator)
{
	OverloadCastOperator x(3,2);
	int a = x;
	long b = x;
	ASSERT_EQ(a,3);
	ASSERT_EQ(b,5);
}
