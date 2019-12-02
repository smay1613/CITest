/*
 * LinkedList.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#ifndef LAB7_LINKEDLIST_H_
#define LAB7_LINKEDLIST_H_
#include <iostream>

namespace Lab7
{
class LinkedList {
private:
	struct Node
	{
		int value;
		Node *next;
	};
Node* _first;

public:
	LinkedList();
	LinkedList(std::initializer_list<int> list);
	LinkedList(const LinkedList& src);
	LinkedList(LinkedList &&src);
	virtual ~LinkedList();
	void insertAt(int index,int value);
	void removeAt(int index);
	int getLength() const;
	friend bool operator==(const Lab7::LinkedList&op1,const Lab7::LinkedList&op2);
	friend std::ostream& operator<<(std::ostream& os,const Lab7::LinkedList &list);
};

#endif /* LAB6_LINKEDLIST_H_ */

std::ostream& operator<<(std::ostream& os,const Lab7::LinkedList &list);

bool operator==(const Lab7::LinkedList&op1,const Lab7::LinkedList&op2);
};
