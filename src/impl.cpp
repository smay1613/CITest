/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include <impl.h>

LinkedList::LinkedList(): _first(nullptr) {
}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr)
{
    for( auto i = std::begin( list); i != std::end( list); i++) {

    }
}

LinkedList::~LinkedList()
{
    for( int i = 0; i < getLength(); i++) {
        removeAt(i);
    }
}

void LinkedList::removeAt(int index)
{
//    Node* current = _first;
//    for( int i =)
}

void LinkedList::insertAt(int index,int value)
{
    Node* current = _first;
    for( int i = 0; i < index; i++) {
        if ( i == index) {
            Node* new_node = new Node(value);
            new_node->next = current->next;
            current->next = new_node;
            std::cout << "Element (" << value << ") was added" << std::endl;
            break;
        }
        current = current->next;
        if ( nullptr == current) {
            std::cout << "Error: end of list reached" << std::endl;
            break;
        }
    }
}

int LinkedList::getLength() const
{
    Node* current = _first;
    for( int i = 0;; i++) {
        if ( nullptr == current) {
            return i;
        }
    }
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
 return false;
}

std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{

 return os;
}

