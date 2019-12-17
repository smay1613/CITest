#include "impl.h"


LinkedList::LinkedList(): _first(nullptr) {}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr) 
{
    for (auto element : list)
    {
        insertAt(0, element);
    }
}

LinkedList::~LinkedList()
{
    while (_first)
    {
        Node* current_node = _first;
        _first = current_node->next;
        delete = current_node;
    }
}

LinkedList::LinkedList(const LinkedList& list) : _first(nullptr)
{
    Node* ptr = list._first;

    while(ptr)
    {
        insertAt(getLength(), ptr->value);
        ptr = ptr->next;
    }
}

LinkedList::LinkedList(LinkedList &&src)
{
    _first = src._first;
    src._first = nullptr;
}

void LinkedList::removeAt(int index)
{
    Node* current_node = _first;
    Node* next_node = _first;
    if (index > 0 && index < getLength)
    {
        for(int iter = 1; iter < index; iter++)
        {
            if (iter == index)
            {
                current_node->next = next_node->next;
                delete next_node;
            }
            current_node = next_node;
            next_node = current_node->next;
        }
    }
}

void LinkedList::insertAt(int index,int value)
{
    Node* new_node = new Node();
    Node* current_node = _first;
    Node* next_node = _first;

    if (index > 0)
    {
        for (int iter = 0; iter < index; iter++)
        {
            current_node = next_node;
            next_node = current_node->next;
        }
    }
    else
    {
        _first = new_node;
    }
    next_node = new_node;
    new_node->next = current_node;
    new_node->value = value;
}

int LinkedList::getLength() const
{
    unsignet int index = 0;
    Node* current_node = _first;

    while(current_node)
    {
        current_node = current_node->next;
        index++;
    }
    return index;
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
    if (op1.getLength() != op2.getLength())
    {
        return false;
    }

    Node* current1 = op1._first;
    Node* current2 = op2._first;

    while (current1 && current2 && (current1 == current2))
    {
        current1 = current1->next;
        current2 = current2->next;
    }
    
    if (!current1 && !current2) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{
    Node* current = _first;

    os << "[ ";
    while (current)
    {
        os << current->value << ", " ;
    }
    os << " ];" << std::endl;
    return os;
}

