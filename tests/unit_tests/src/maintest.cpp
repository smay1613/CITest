#include "maintest.h"
#include "impl.h"
#include <iostream>

TEST(Lab7,CopyConstructor)
{
    LinkedList myList{2,3,4};
    LinkedList expectedList{1,2,3,4};
    LinkedList clone = myList;
    myList.insertAt(0,1);

    ASSERT_EQ(myList,expectedList);
}

LinkedList Copy()
{
    LinkedList r = {1,2,3};
    return r;
}

TEST(Lab7,MoveConstructor)
{
    LinkedList expectedList{1,2,3};
    LinkedList clone = std::move(LinkedList{1,2,3});

    ASSERT_EQ(clone,expectedList);
}

