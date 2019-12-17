#include "impl.h"
#include <iostream>

LinkedList::LinkedList(): _first(nullptr) 
{
}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr)
{
    int ii = 0;

    for(int element:list)
    {
        insertAt(ii,element);
    }
}

LinkedList::LinkedList(const LinkedList &src):_first(nullptr)
{
    int ii = 0;
    Node *curNodeSrc = src._first;

    while(curNodeSrc)
    {
        insertAt(ii,curNodeSrc->value);
        curNodeSrc = curNodeSrc->next;
        ii++;
    }
}

LinkedList::LinkedList(LinkedList &&src):_first(nullptr)
{
    int ii = 0;
    Node *curNodeSrc = src._first;

    while(curNodeSrc)
    {
        insertAt(ii,curNodeSrc->value);
        curNodeSrc = curNodeSrc->next;
        ii++;
    }
}

LinkedList::~LinkedList()
{
    Node *curNode = _first;
    Node *prevNode = nullptr;

    while(curNode)
    {
        prevNode = curNode;
        curNode = curNode->next;
        delete prevNode;
    }
}

void LinkedList::removeAt(int index)
{
    Node *curNode = _first;
    Node *prevNode = nullptr;

    if (index>1)
    {
        for(int ii=1; ii<index; ii++)
        {
            prevNode = curNode;
            curNode = curNode->next;
        }
        prevNode->next = curNode->next; 
        delete curNode;
    }
    else
    {
        _first = curNode->next;
        delete curNode;
    }
}

void LinkedList::insertAt(int index,int value)
{
    Node *n = new Node;
    Node *curNode = _first;
    Node *prevNode = nullptr;

    if (index>0)
    {
        for(int ii=0; ii<index; ii++)
        {
            prevNode = curNode;
            curNode = curNode->next;
        }
        prevNode->next = n;
    }
    else
    {
        _first = n;
    }
    n->next = curNode;
    n->value = value;
}

int LinkedList::getLength() const
{
    int index = 0;
    Node *curNode = _first;

    while(curNode)
    {
        curNode = curNode->next;
        index++;
    }
    return index;
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
    LinkedList::Node *curNode1 = op1._first;
    LinkedList::Node *curNode2 = op2._first;

    while ((curNode1->value == curNode2->value) && curNode1 && curNode2)
    {
        curNode1 = curNode1->next;
        curNode2 = curNode2->next;
    }

    if (!curNode1 && !curNode2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{
 return os;
}
*/
