#include "impl.h"

LinkedList::LinkedList(): _first(nullptr) 
{
}

LinkedList::LinkedList(std::initializer_list<int> list)
{
    int nodeNumber {0};

    for(int element:list)
    {
        insertAt(nodeNumber,element);
        nodeNumber ++;
    }
}

LinkedList::LinkedList(const LinkedList &src)
{
    int nodeNumber  {0};
    Node *curNodeSrc {src._first};

    while(curNodeSrc)
    {
        insertAt(nodeNumber ,curNodeSrc->value);
        curNodeSrc = curNodeSrc->next;
        nodeNumber++;
    }
}

LinkedList::LinkedList(LinkedList &&src)
{
    _first = src._first;
    linkSize = src.linkSize;
    src._first = nullptr;
    src.linkSize = 0;
}

LinkedList::~LinkedList()
{
    Node *curNode {_first};
    Node *prevNode {nullptr};

    while(curNode)
    {
        prevNode = curNode;
        curNode = curNode->next;
        delete prevNode;
    }
}

void LinkedList::removeAt(int index)
{
    if ((index >= 1) && (index <= linkSize))
    {
        Node *currentNode {_first};
        Node *previousNode {nullptr};

        if (index>1)
        {
            findNode(index, &previousNode, &currentNode);
            previousNode->next = currentNode->next;
            delete currentNode;
        }
        else
        {
            _first = currentNode->next;
            delete currentNode;
        }
        linkSize--;
    }
}

void LinkedList::insertAt(int index,int value)
{
    if ((index >= 0) && (index <= linkSize))
    {
        Node *n = new Node;
        Node *currentNode {_first};
        Node *previousNode {nullptr};

        if (index>0)
        {
            findNode(index, &previousNode, &currentNode);
            previousNode->next = n;
        }
        else
        {
            _first = n;
        }
        n->next = currentNode;
        n->value = value;
        linkSize++;
    }
}

int LinkedList::getLength() const
{
    return linkSize;
}

void LinkedList::findNode(int index, Node **previousNode, Node **currentNode)
{
    for(int ii=0; ii<index; ii++)
    {
        *previousNode = *currentNode;
        *currentNode = (*currentNode)->next;
    }
}

bool operator==(const LinkedList&op1,const LinkedList&op2)
{
    LinkedList::Node *Node1 {op1._first};
    LinkedList::Node *Node2 {op2._first};

    while (Node1 && Node2 && (Node1->value == Node2->value))
    {
        Node1 = Node1->next;
        Node2 = Node2->next;
    }

    return (Node1 == nullptr) && (Node2 == nullptr);

}

std::ostream& operator<<(std::ostream& os,const LinkedList &list)
{
    LinkedList::Node *currentNode {list._first};
    while (currentNode)
    {
        os << currentNode->value;
        currentNode = currentNode->next;
    }
 return os;
}

