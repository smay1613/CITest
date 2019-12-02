/*
 * LinkedList_test.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */
#include <gtest/gtest.h>
#include <lab10/LinkedList.h>


using namespace Lab10;

TEST(Lab10,SortList)
{
	LinkedList<int> myList{3,2,1};

	myList.sort([](int x,int y) { return x < y;});

	LinkedList<int> expectedList{1,2,3};

	ASSERT_EQ(myList,expectedList);

}
