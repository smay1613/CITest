/*
 * seaWarTest.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: Pavel Tsytovich
 *
 */
#include <lab8/Ship.h>
#include <lab8/BigShip.h>
#include <gtest/gtest.h>

TEST(Lab8,OneShip)
{
	Ship myShip(1,2);

	ASSERT_FALSE(myShip.fire(3,2));
	ASSERT_TRUE(myShip.fire(1,2));
	ASSERT_FALSE(myShip.getStatus());
}

TEST(Lab8,BigShip)
{
	BigShip myShip(1,2,HORIZONTAL,2);

	ASSERT_FALSE(myShip.fire(5,2));
	ASSERT_TRUE(myShip.fire(1,2));
	ASSERT_TRUE(myShip.getStatus());
	ASSERT_TRUE(myShip.fire(2,2));
	ASSERT_FALSE(myShip.getStatus());
}

TEST(Lab8,GameField)
{
	IShip * fields [] = { new Ship(1,2),
			             new BigShip(5,6,VERTICAL,3),
						 new Ship(10,11),
						 new BigShip(20,30,HORIZONTAL,2)
					   };
	Point pt[] = { Point{1,2},Point{5,6},Point{10,11},Point{20,30}};

	for(int i = 0; i < 4;i++ )
		fields[i]->fire(pt[i].x,pt[i].y);

	ASSERT_FALSE(fields[0]->getStatus());
	ASSERT_TRUE(fields[1]->getStatus());
	ASSERT_FALSE(fields[2]->getStatus());
	ASSERT_TRUE(fields[3]->getStatus());
}
