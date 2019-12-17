/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include "impl.h"

LinkedList::LinkedList(): _first(nullptr) {
}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr)
{
    Node** current_node = &_first;
    for( auto i : list) {
        *current_node = new Node { i, nullptr};
        current_node = &(*current_node)->next;
    }
}

LinkedList::LinkedList( const LinkedList& list) : _first(nullptr) {
    Node** node = &_first;
    for( Node* const* current_node = &list._first;
         *current_node != nullptr;
         current_node = &(*current_node)->next) {

        *node = new Node { (*current_node)->value, nullptr};
        node = &(*node)->next;
    }
}

LinkedList::LinkedList(LinkedList &&src) {
    _first = src._first;
    src._first = nullptr;
}

LinkedList::~LinkedList()
{
    while( nullptr != _first) {
        Node* current_node = _first;
        _first = current_node->next;
        delete current_node;
    }
}

void LinkedList::removeAt(int index)
{
    Node** current = &_first;
    for( int pos = 0; *current != nullptr; pos++) {
        if ( pos == index) {
            Node* for_delete = *current;
            *current = for_delete->next;
            delete for_delete;
            break;
        }
        current = &(*current)->next;
    }
}

void LinkedList::insertAt(int index,int value)
{
    Node** current_node = &_first;
    int     position = 0;
    do {
        if ( index == position) {
            *current_node = new Node { value, *current_node};
            break;
        }
        current_node = &(*current_node)->next;
        position++;
    } while( nullptr != *current_node);
}

int LinkedList::getLength() const
{
    Node* current = _first;
    for( int i = 0;; i++) {
        if ( nullptr == current) {
            return i;
        }
        current = current->next;
    }
    return 0;
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
    LinkedList::Node* current1 = op1._first;
    LinkedList::Node* current2 = op2._first;
    bool res = false;
    while(( nullptr != current1)&&( nullptr != current2)) {
        if (( current1->value) == ( current2->value)) {
            res = true;
        } else {
            res = false;
            break;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return res;
}

std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{
    LinkedList::Node* current_node = list._first;
    for( int i = 0; i < list.getLength(); i++ ) {
        os << "[" << i << "]" << current_node->value << std::endl;
    }
 return os;
}

