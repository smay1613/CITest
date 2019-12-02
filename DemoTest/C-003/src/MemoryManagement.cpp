/*
 * MemoryManagement.cpp
 *
 *  Created on: 20 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"
#include <new>

#define SIZEOFPOINTER sizeof(void*) == 4 ? 4:8

TEST(Module6,TypeOfPointer)
{
	long l = 0x12345678;
    long *pl = &l;
	short int *pi = (short int*) &l;
	char *pc = (char*)&l;

	ASSERT_EQ(pl,&l);
	ASSERT_EQ(pi,&l);
	ASSERT_EQ(pc,&l);
    ASSERT_EQ(*pl,0x12345678);
    ASSERT_EQ(*pi,0x5678);
    ASSERT_EQ(*pc,0x78);
}
TEST(Module6,AddressOfArray)
{
	char str[] = "TEST";
	char *ptr = str;
	char ** pptr = (char**)&str;
	char *p = (char*) pptr;
	ASSERT_EQ(str,p);
	ASSERT_EQ(str,pptr);
	ASSERT_EQ(sizeof(str),5);
}
TEST(Module6,AddressOfPointer)
{
	char *str = "TEST";
	char *ptr = str;
	char ** pptr = &str;
	ASSERT_EQ(str,ptr);
	ASSERT_NE(str,pptr);
	ASSERT_EQ(sizeof(str),SIZEOFPOINTER);
}

int Func1(const int a)
{
	return a+2;
}
int Func2(const int a)
{
	return a-2;
}

typedef int (*FnPtr)(int);

TEST(Module6,FunctionPointer)
{
  FnPtr callback[] = { Func1,Func2 };
  int x = 5;
  for(auto c : callback)
	  x += c(x);
  ASSERT_EQ(x,22);
}

class FooThis
{
public:
	FooThis * myAddress;
	void SetupAddress();
};

void FooThis::SetupAddress()
{
 myAddress = this;
}

TEST(Module6,ThisPointer)
{
	FooThis a,b;
	a.SetupAddress();
	b.SetupAddress();
	ASSERT_EQ(a.myAddress,&a);
	ASSERT_EQ(b.myAddress,&b);
}

