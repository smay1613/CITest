#ifndef LAB6_LINKEDLIST_H_
#define LAB6_LINKEDLIST_H_
#include <iostream>

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
    LinkedList(const LinkedList &src);
    LinkedList(LinkedList &&src);
	virtual ~LinkedList();
	void insertAt(int index,int value);
	void removeAt(int index);
	int getLength() const;
    friend bool operator==(const LinkedList&op1,const LinkedList&op2);
    friend std::ostream& operator<<(std::ostream& os,const LinkedList &list);
};

#endif /* LAB7_LINKEDLIST_H_ */

std::ostream& operator<<(std::ostream& os,const LinkedList &list);

bool operator==(const LinkedList&op1,const LinkedList&op2);
