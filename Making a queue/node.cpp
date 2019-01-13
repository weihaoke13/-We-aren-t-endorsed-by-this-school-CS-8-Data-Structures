#include "node.h"

node::node()
{
    data = priority = next = NULL;
}

node::~node()
{
    data = priority = next = NULL;
}

node* node::getNext()
{
    return next;
}

void node::setNext(node* n)
{
    next = n;
}

void* node::getDataPtr()
{
    return data;
}

void node::setDataPtr(void *d)
{
    data = d;
}

void* node::getPriorityPtr()
{
    return priority;
}

void node::setPriorityPtr(void* p)
{
    priority = p;
}
