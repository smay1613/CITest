/*
 * BasicString.cpp
 *
 *  Created on: 19 ����. 2017 �.
 *      Author: ����
 */
#include "gtest/gtest.h"

TEST(Module5,StringLength)
{
	char srcStr[6] = "12345";
	char dstStr[3] = {0};
	int i=0;
	for(i=0;srcStr[i];i++)
		dstStr[i] = srcStr[i];
    dstStr[i] = '\0';
	int length = 0;
	for(i=0;dstStr[i];i++,length++);

	ASSERT_EQ(length,5);
}

