/*
 * MutablePropertyDemo.cpp

 *
 *  Created on: 22 сент. 2017 г.
 *      Author: Luxoft
 */

#include "gtest/gtest.h"
class ConstCalculate
{

	mutable int cachedValue;
public:
	ConstCalculate() : cachedValue(0) {}
	int Calculate() const;

};
int ConstCalculate::Calculate()  const
{
  if(!cachedValue)
	  return cachedValue++;
  else
	  return cachedValue;
}

TEST(Module8,Mutable)
{
	ConstCalculate x;
	ASSERT_EQ(x.Calculate(),0);
	ASSERT_EQ(x.Calculate(),1);
}



