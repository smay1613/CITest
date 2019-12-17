#include "maintest.h"
#include "impl.h"

#include <impl.h>
#include <gtest/gtest.h>


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
