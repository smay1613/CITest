/*
 * IntegerTest.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <lab9/Integer.h>
#include <gtest/gtest.h>

TEST(Lab9,Five)
{
	Integer v(5);

	char* actual = (char*)v;

	ASSERT_STREQ(actual,"five");
}

TEST(Lab9,Seventeen)
{
	Integer v(7);

	char* actual = (char*)v;

	ASSERT_STREQ(actual,"seven");
}
