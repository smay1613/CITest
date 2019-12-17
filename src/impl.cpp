#include "impl.h"

using namespace ::Lab7;

LinkedList::LinkedList(): _first(nullptr),size(0) {


}

LinkedList::LinkedList(std::initializer_list<int> list): _first(nullptr),size(0)
{
    for (auto &it: list)
    {
        insertAt(size, it);
    }
}
LinkedList::LinkedList(const LinkedList &src) : _first(nullptr),size(0)
{
    LinkedList::Node *ptr = src._first;

    while(ptr)
    {
        insertAt(size, ptr->value);
        ptr = ptr->next;
    }
}
LinkedList::LinkedList(LinkedList &&src) : size(0)
{
    LinkedList::Node *ptr = src._first;

    while(ptr)
    {
        insertAt(size, ptr->value);
        ptr = ptr->next;
    }
}
LinkedList::~LinkedList()
{
    Node *prev = _first;
    Node *next;

    while(prev)
    {
        next = prev->next;
        delete prev;
        prev = next;
    }
}

void LinkedList::removeAt(int index)
{
    int counter = 0;
     if (!getLength() || index >= getLength()) return;

     Node *removeNode;

     if (index == 0)
     {
         removeNode = _first;
         _first = _first->next;
         delete removeNode;
     }
     else
     {
         Node *currNode = _first;
         Node *prevNode;
         while(counter < index && (prevNode = currNode) && (currNode = currNode->next))
         {
             counter++;
         }

         if (index == counter)
         {
             removeNode = currNode;
             prevNode->next = currNode->next;
             delete removeNode;
         }
     }
     size--;
}

void LinkedList::insertAt(int index,int value)
{
    Node *prev = _first;
    Node *next;
    int nextPosition = 0;

    if (index <= size)
    {
        Node *newNode = new Node();
        newNode->value = value;
        if (size == 0)
        {
            _first = newNode;
        }
        else if (size == 1)
        {
            prev->next = newNode;
        }
        else
        {
            if (index == 0)
            {
                newNode->next = _first;
                _first = newNode;
            }
            while ((nextPosition < index) && prev)
            {
                next = prev->next;
                if (++nextPosition == index)
                {
                    prev->next = newNode;
                    newNode->next = next;
                    break;
                }
                 prev = next;
            }
        }
       size++;
    }
}
int LinkedList::getLength() const
{
    return size;
}

bool Lab7::operator==(const Lab7::LinkedList&op1,const Lab7::LinkedList&op2)
{
    if (op1.getLength() != op2.getLength())
    {
        return false;
    }

    LinkedList::Node *ptr1 = op1._first, *ptr2 = op2._first;

    while(ptr1 && ptr2 && (ptr1->value == ptr2->value))
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return !ptr1 && !ptr2;
}

std::ostream& Lab7::operator<<(std::ostream& os,const Lab7::LinkedList &list)
{
    LinkedList::Node *ptr = list._first;

    os << "List content: [ ";
    while (ptr) {
        os << ptr->value << " ";
        ptr = ptr->next;
    }
    os << ']' << std::endl;

    return os;
}
