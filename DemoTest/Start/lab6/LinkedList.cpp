/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <lab6/LinkedList.h>

LinkedList::LinkedList(): _first(nullptr) {


}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr)
{
}

LinkedList::~LinkedList()
{
}

void LinkedList::removeAt(int index)
{
}

void LinkedList::insertAt(int index,int value)
{
}
int LinkedList::getLength() const
{
 return -1;
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
 return false;
}

std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{
 return os;
}



