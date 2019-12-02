/*
 * InheritanceDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */

#include "gtest/gtest.h"
#include <memory>
class A
{
public:
  static char OrderCall[8];
  static int CallCount;
  static void SetUp();
  A() { OrderCall[CallCount++] = 'A';}
};

class B : public A
{
public:
	B() { OrderCall[CallCount++] = 'B';}
};

class C : public B
{
	A var;
public:
	C() {OrderCall[CallCount++] = 'C';}
};

char A::OrderCall[8] = {0};
int A::CallCount = 0;

void A::SetUp()
{
	A::CallCount = 0;
	memset(A::OrderCall,0,sizeof(A::OrderCall));
}
TEST(Module8,OrderInheritance)
{
	A::SetUp();

	C x;
	ASSERT_STREQ(A::OrderCall,"ABAC");
}

class D : public B, public C
{
public:
	D() { OrderCall[CallCount++] = 'D';}
};

TEST(Module8,OrderMultipleInheritance)
{
   A::SetUp();
   D x;
   ASSERT_STREQ(A::OrderCall,"ABABACD");
}

class Bv : public virtual A
{
public:
	Bv() { OrderCall[CallCount++] = 'b';}
};

class Cv : public virtual Bv
{
	A var;
public:
	Cv() { OrderCall[CallCount++] = 'c';}
};

class Dv : virtual public Bv, public Cv
{
public:
	Dv() { OrderCall[CallCount++] = 'd';}
};

TEST(Module8, VirtualInheritance)
{
	A::SetUp();
	Dv x;
	ASSERT_STREQ(A::OrderCall,"AbAcd");
}
