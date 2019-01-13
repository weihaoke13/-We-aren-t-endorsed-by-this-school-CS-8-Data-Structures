#include "stack.h"
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
Stack::Stack()
{

}

void Stack::push1(int data){
    np1 = new node1;
    np1->data1 = data;
    np1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = np1;
    }
    else
    {
        np1->next1 = top1;
        top1 = np1;
    }

}
void Stack::push2(int data){
    np2 = new node2;
       np2->data2 = data;
       np2->next2 = NULL;
       if (top2 == NULL)
       {
           top2 = np2;
       }
       else
       {
           np2->next2 = top2;
           top2 = np2;
       }

}

void Stack::push3(int data){
    np3 = new node3;
       np3->data3 = data;
       np3->next3 = NULL;
       if (top3 == NULL)
       {
           top3 = np3;
       }
       else
       {
           np3->next3 = top3;
           top3 = np3;
       }

}

int Stack::pop1(){
    int b = 999;
       if (top1 == NULL)
       {
           return b;
       }
       else
       {
           p1 = top1;
           top1 = top1->next1;
           return(p1->data1);
           delete(p1);
       }

}
int Stack::pop2(){
    int b = 999;
        if (top2 == NULL)
        {
            return b;
        }
        else
        {
            p2 = top2;
            top2 = top2->next2;
            return(p2->data2);
            delete(p2);
        }

}

int Stack::pop3(){

    int b = 999;
        if (top3 == NULL)
        {
            return b;
        }
        else
        {
            p3 = top3;
            top3 = top3->next3;
            return(p3->data3);
            delete(p3);
        }
}

int Stack::top_of_stack(){
    if (top1 != NULL && top1->data1 == 1 )
       {
           return 1;
       }
       else if (top2 != NULL && top2->data2 == 1)
       {
           return 2;
       }
       else if (top3 != NULL && top3->data3 == 1)
       {
           return 3;
       }
}
