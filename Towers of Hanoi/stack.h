#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;



class Stack
{
public:
    struct node1
    {
        int data1;
        node1 *next1;
    }*top1 = NULL, *p1 = NULL, *np1 = NULL;
    struct node2
    {
        int data2;
        node2 *next2;
    }*top2 = NULL, *p2 = NULL, *np2 = NULL;
    struct node3
    {
        int data3;
        node3 *next3;
    }*top3 = NULL, *p3 = NULL, *np3 = NULL;

    Stack();
    void push1(int data);
    void push2(int data);
    void push3(int data);

    int pop1();
    int pop2();
    int pop3();

    int top_of_stack();

    void peek();
    int isEmpty();
    int isFull();
    int Sizeof();
    int quantity();
private:
    int MAX;
    int TOP;


};


//Stack::Stack(){

//}

//void Stack::push1(int data){
//    np1 = new node1;
//    np1->data1 = data;
//    np1->next1 = NULL;
//    if (top1 == NULL)
//    {
//        top1 = np1;
//    }
//    else
//    {
//        np1->next1 = top1;
//        top1 = np1;
//    }

//}
//void Stack::push2(int data){
//    np2 = new node2;
//       np2->data2 = data;
//       np2->next2 = NULL;
//       if (top2 == NULL)
//       {
//           top2 = np2;
//       }
//       else
//       {
//           np2->next2 = top2;
//           top2 = np2;
//       }

//}

//void Stack::push3(int data){
//    np3 = new node3;
//       np3->data3 = data;
//       np3->next3 = NULL;
//       if (top3 == NULL)
//       {
//           top3 = np3;
//       }
//       else
//       {
//           np3->next3 = top3;
//           top3 = np3;
//       }

//}

//int Stack::pop1(){
//    int b = 999;
//       if (top1 == NULL)
//       {
//           return b;
//       }
//       else
//       {
//           p1 = top1;
//           top1 = top1->next1;
//           return(p1->data1);
//           delete(p1);
//       }

//}
//int Stack::pop2(){
//    int b = 999;
//        if (top2 == NULL)
//        {
//            return b;
//        }
//        else
//        {
//            p2 = top2;
//            top2 = top2->next2;
//            return(p2->data2);
//            delete(p2);
//        }

//}

//int Stack::pop3(){

//    int b = 999;
//        if (top3 == NULL)
//        {
//            return b;
//        }
//        else
//        {
//            p3 = top3;
//            top3 = top3->next3;
//            return(p3->data3);
//            delete(p3);
//        }
//}

//int Stack::top_of_stack(){
//    if (top1 != NULL && top1->data1 == 1 )
//       {
//           return 1;
//       }
//       else if (top2 != NULL && top2->data2 == 1)
//       {
//           return 2;
//       }
//       else if (top3 != NULL && top3->data3 == 1)
//       {
//           return 3;
//       }
//}

//void Stack::peek(){

//}

//int Stack::isEmpty(){

//}

//int Stack::isFull(){

//}

//int Stack::Sizeof(){

//}

//int Stack::quantity(){

//}

#endif // STACK_H
