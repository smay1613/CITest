/*
 * ArrayDemo.cpp
 *
 *  Created on: 20 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"

TEST(Module5, MultidimensionalArray)
{
	char TwoDimArray[3][2] = { {'a','b'}, {'c','d'},{'e','f'}};
	char Array[6];
	for(int i=0;i< 3*2;i++)
		Array[i] = TwoDimArray[0][i];
	Array[6] = '\0';
	ASSERT_STREQ(Array,"abcdef");
}



