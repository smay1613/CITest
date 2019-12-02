/*
 * LinkedList_test.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <lab6/LinkedList.h>
#include <gtest/gtest.h>

TEST(Lab6,InsertAt0)
{
	LinkedList myList{1,2,3};
	LinkedList expectedList{2,1,2,3};

	myList.insertAt(0,2);

	ASSERT_EQ(myList,expectedList);

}
TEST(Lab6,InsertAt1)
{
	LinkedList myList{1,2,3};
	LinkedList expectedList{1,2,2,3};

	myList.insertAt(1,2);

	ASSERT_EQ(myList,expectedList);

}

TEST(Lab6,RemoveAt1)
{
	LinkedList myList{1,2,3};
	LinkedList expectedList{1,3};

	myList.removeAt(1);

	ASSERT_EQ(myList,expectedList);
}

TEST(Lab6,RemoveAt0)
{
	LinkedList myList{1,2,3};
	LinkedList expectedList{2,3};

	myList.removeAt(0);

	ASSERT_EQ(myList,expectedList);

}

TEST(Lab6,RemoveAtLast)
{
	LinkedList myList{1,2,3};
	LinkedList expectedList{1,2};

	myList.removeAt(2);

	ASSERT_EQ(myList,expectedList);
}
