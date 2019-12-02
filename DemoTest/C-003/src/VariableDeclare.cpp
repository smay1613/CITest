/*
 * VariableDeclare.cpp
 *
 *  Created on: 19 сент. 2017 г.
 *      Author: Паша
 */

#include "gtest/gtest.h"
int global = 2;
int& foo()
{
  return global;
}

TEST(Module2,AutoVsDecltype)
{
	decltype(foo()) a = foo();
	auto b = foo();
	a = 3;
	ASSERT_EQ(global,3);
	ASSERT_EQ(a,3);
	ASSERT_EQ(b,2);
}

TEST(Module2,DecltypeWithAuto)
{
	global = 2;
	decltype(auto) a = foo();
	a = 3;
	ASSERT_EQ(global,3);
	ASSERT_EQ(a,3);
}

