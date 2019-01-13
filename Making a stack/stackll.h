#ifndef STACKLL_H
#define STACKLL_H

#endif // STACKLL_H
#include "mystack.h"
#include<iostream>
using namespace std;


//   Creating a NODE Structure
struct node
{
    int data;
    struct node *next;
};

// Creating a class STACK
class stackLL
{
    struct node *top;
    public:
    stack() // constructure
    {
        top=NULL;
    }
    void push(); // to insert an element
    void pop();  // to delete an element
    void show(); // to show the stack
};
// PUSH Operation
void stackLL::push()
{
    int value;
    struct node *ptr;
    cout<<"nPUSH Operationn";
    cout<<"Enter a number to insert: ";
    cin>>value;
    ptr=new node;
    ptr->data=value;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;
    cout<<"nNew item is inserted to the stack!!!";

}

// POP Operation
void stackLL::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"nThe stack is empty!!!";
    }
    temp=top;
    top=top->next;
    cout<<"nPOP Operation........nPoped value is "<<temp->data;
    delete temp;
}

// Show stack
void stackLL::show()
{
    struct node *ptr1=top;
    cout<<"nThe stack isn";
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<" ->";
        ptr1=ptr1->next;
    }
    cout<<"NULLn";
}
