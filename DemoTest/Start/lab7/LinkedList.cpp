/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <lab7/LinkedList.h>

using namespace ::Lab7;

LinkedList::LinkedList(): _first(nullptr) {


}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr)
{
}
LinkedList::LinkedList(const LinkedList &src) : _first(nullptr)
{
}
LinkedList::LinkedList(LinkedList &&src)
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

bool Lab7::operator==(const Lab7::LinkedList&op1,const Lab7::LinkedList&op2)
{
 return false;
}

std::ostream& Lab7::operator<<(std::ostream& os,const Lab7::LinkedList &list)
{
 return os;
}



