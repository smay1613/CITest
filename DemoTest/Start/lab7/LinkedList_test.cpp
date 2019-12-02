/*
 * LinkedList_test.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <lab7/LinkedList.h>
#include <gtest/gtest.h>

using namespace Lab7;

TEST(Lab7,CopyConstructor)
{
	LinkedList myList{1,2,3};

	LinkedList expectedList{1,2,3};

	LinkedList clone = myList;

	myList.insertAt(0,2);

	ASSERT_EQ(clone,expectedList);

}

LinkedList Copy()
{
	LinkedList r={1,2,3};
	return r;
}

TEST(Lab7,MoveConstructor)
{
	LinkedList expectedList{1,2,3};
	LinkedList clone = std::move(LinkedList{1,2,3});


	ASSERT_EQ(clone,expectedList);
}
