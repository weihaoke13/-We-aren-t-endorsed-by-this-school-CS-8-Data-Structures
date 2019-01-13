#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

class Queue
{
public:
    Queue();
    void iequeue();
    void dequeue();
    bool isEmpty();
    bool isFull();
    void peek();
    int Sizeof();
    int quantity();

};

#endif // QUEUE_H
