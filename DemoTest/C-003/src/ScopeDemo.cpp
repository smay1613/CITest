/*
 * ScopeDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"


int Global = 0;

void IncGlobal() { Global++;}
void DecGlobal() { Global--;}

TEST(Module7,GlobalVariable)
{
  IncGlobal();
  DecGlobal();
  ASSERT_EQ(Global,0);
}

int var = 5;

TEST(Module7, LocalVariable)
{
	int var = 2;
	{
		int var = 4;
		ASSERT_EQ(var,4);
	}
	ASSERT_EQ(var,2);
	ASSERT_EQ(::var,5);
}

class FooStatic
{
public:
	int val;
	FooStatic() : val(10) {}
	void Inc() { val++;}
};

FooStatic FuncWithStatic()
{
	static FooStatic statVar;
	statVar.Inc();
	return statVar;
}
TEST(Module7,StaticVariable)
{
	ASSERT_EQ(FuncWithStatic().val,11);
	ASSERT_EQ(FuncWithStatic().val,12);
}
