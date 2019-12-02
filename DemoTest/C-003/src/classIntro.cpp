/*
 * classIntro.cpp
 *
 *  Created on: 20 сент. 2017 г.
 *      Author: Паша
 */

#include "gtest/gtest.h"

TEST(Module5,ClassField)
{
	class Foo
	{
	public:
		int k;
		char v;
	};
	Foo a1,a2;
	a1.k = 2;
	a1.v = '@';
	a2.k = 3;
	a2.v = '#';
	ASSERT_EQ(a1.k,2);
	ASSERT_EQ(a1.v,'@');
	ASSERT_EQ(a2.k,3);
	ASSERT_EQ(a2.v,'#');
}
class FooWithStaticField
{
	public:
		int k;
		static char v;
};
char FooWithStaticField::v;

TEST(Module5,StaticClassField)
{
	FooWithStaticField a1,a2;
		a1.k = 2;
		a1.v = '@';
		a2.k = 3;
		a2.v = '#';
		ASSERT_EQ(a1.k,2);
		ASSERT_EQ(a1.v,'#');
		ASSERT_EQ(a2.k,3);
		ASSERT_EQ(a2.v,'#');
}

class FooMethodDemo
{
	int v;
	char c;
public:
	void Init(int a,int b);
	int GetV();
	char GetC();
};

void FooMethodDemo::Init(int a,int b)
{
	v = a;
	c = b;
}
int FooMethodDemo::GetV()
{
	return v;
}
char FooMethodDemo::GetC()
{
	return c;
}

TEST(Module5, MethodDemo)
{
	FooMethodDemo x;
	x.Init(2,3);
	ASSERT_EQ(x.GetV(),2);
	ASSERT_EQ(x.GetC(),3);
}

TEST(Module5,MethodDemoWithTwoObjects)
{
	FooMethodDemo x,y;
	x.Init(2,3);
	y.Init(4,5);
	ASSERT_EQ(x.GetV(),2);
	ASSERT_EQ(x.GetC(),3);
	ASSERT_EQ(y.GetV(),4);
	ASSERT_EQ(y.GetC(),5);
}
