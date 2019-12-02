/*
 * DestructorDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"

class FooDestructor
{
public:
	static int CountDestructor;
	~FooDestructor() {CountDestructor++;}
};

int FooDestructor::CountDestructor = 0;

TEST(Module7,Destructor)
{
	FooDestructor *p;
	{
		FooDestructor a,b;
		p = new FooDestructor();
	}
	ASSERT_EQ(FooDestructor::CountDestructor,2);
	delete p;
	ASSERT_EQ(FooDestructor::CountDestructor,3);
}


