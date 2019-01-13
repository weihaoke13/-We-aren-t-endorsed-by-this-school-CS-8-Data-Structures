#include "myqueue.h"

myQueue::myQueue(unsigned int s)
{
    head = tail = NULL;
    mySize = 0;
    myCap = s;
}

myQueue::~myQueue()
{
    head = tail = NULL;
    mySize = myCap = 0;
}

myQueue::myQueue(const myQueue &other)
{
    copy(other);
}


unsigned int myQueue::capacity()
{
    return myCap;
}

unsigned int myQueue::size()
{
    return mySize;
}

unsigned int myQueue::moreCapacity(unsigned int s)
{
    if(s < myCap)
        throw CANNOT_ADD_CAPACITY;
    myCap = s;
}

void myQueue::swap(myQueue &other)
{
    swap(mySize, other.mySize);
    swap(myCap, other.myCap);
    swap(head, other.head);
    swap(tail, other.tail);
}

void myQueue::swap(node* &x, node* &y)
{
    node* temp = x;
    x = y;
    y = temp;
}

void myQueue::swap(unsigned int &x, unsigned int &y)
{
    unsigned int temp = x;
    x = y;
    y = temp;
}

bool myQueue::full()
{
    return myCap == mySize;
}

bool myQueue::empty()
{
    return !head;
}

void* myQueue::peek()
{
    if(!empty())
        throw EMPTY;
    return head->getDataPtr();
}

myQueue& myQueue::operator<<(node *n)
{
    if(full())
        throw FULL;
    tail->setNext(n);
    tail = n;
    ++mySize;
    return *this;
}

myQueue& myQueue::operator>>(node*  &n)
{
    if(empty())
        throw EMPTY;
    n = head;
    head->setNext(head->getNext());
    return *this;
}
