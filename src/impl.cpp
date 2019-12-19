#include "impl.h"
#include <iostream>

LinkedList::LinkedList(): _first(nullptr) {

}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr)
{
    Node *newNode {nullptr};
    Node *tmp {nullptr};
    _first = new Node();
    _first->value = -1;
    tmp = _first;

    for (auto it=list.begin(); it != list.end(); ++it)
    {
        newNode = new Node();
        newNode->value = *it;
        tmp->next = newNode;
        tmp = newNode;
    }
}
LinkedList::LinkedList(const LinkedList &src) : _first(nullptr)
{
    int NewNodeCount {0};
    Node *BaseNodePtr {src._first};
    while (BaseNodePtr)
    {
        insertAt(NewNodeCount,BaseNodePtr->value);
        BaseNodePtr = BaseNodePtr->next;
        NewNodeCount++;
    }
}
LinkedList::LinkedList(LinkedList &&src)
{
    _first = src._first;
    _first = nullptr;
}
LinkedList::~LinkedList()
{
    Node *currentNode = _first;
    Node *NextNode;
    while (currentNode->next){
        NextNode = currentNode->next;
        delete currentNode;
        currentNode = NextNode;
    }
    delete currentNode;
}

void LinkedList::removeAt(int index)
{
    Node *tmp {_first};
    Node *del {nullptr};
    int i {index};
    while (i){
        tmp = tmp->next;
        i--;
    }
    del = tmp->next;
    tmp->next = tmp->next->next;
    delete del;
}

void LinkedList::insertAt(int index,int value)
{
    Node *tmp {_first};
    if (index)
    {
        int i {index};
        while (i){
            tmp = tmp->next;
            i--;
        }
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    else
    {
        tmp = new Node();
        tmp->value = value;
        tmp->next = _first->next;
        _first->next = tmp;
    }
}
int LinkedList::getLength() const
{
    int i {0};
    Node *tmp {_first};
    while (tmp->next) {
        tmp = tmp->next;
        i++;
    }
    return i;
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
    if (op1.getLength() == op2.getLength())
    {
        int i {op1.getLength()};
        LinkedList::Node *tmp1 {op1._first};
        LinkedList::Node *tmp2 {op2._first};
        while (i) {
            if (tmp1->value != tmp2->value)
                return false;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            i--;
        }
        return true;
    }
    else
    {
        return false;
    }

}

std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{
    LinkedList::Node *tmp{list._first->next};
    os << "List contents" << std::endl;
    while (tmp) {
        os << ' ' << tmp->value;
        tmp = tmp->next;
    }
    os << '\n';
    return os;
}
