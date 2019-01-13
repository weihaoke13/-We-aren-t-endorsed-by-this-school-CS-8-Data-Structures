#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <cstdlib>
#include "stackll.h"

//fixing and make arrays

using namespace std;

enum STACK_ERRORS {STACK_FULL, STACK_EMPTY};

template<typename T>
class myStack
{
    public:
        myStack(int s = 5, int c = 1<<29);
        ~myStack();
        myStack(const myStack<T>& other);
        myStack<T>& operator=(const myStack<T> &other);

        void push(const T &data);
        T pop();
        T peek();
        bool empty();
        bool full();
        int size();
        int capacity();
        void clear();
        void resize(int s);
        void swap(myStack<T> &other);
        myStack<T>& operator<<(const T& data);
        myStack<T>& operator>>(T& data);

        template<typename U>
        friend
        ostream& operator<<(ostream &out, const myStack<U> &s);

        template<typename U>
        friend
        istream& operator>>(istream &in, myStack<U> &s);

     private:
        T *stack;
        int msize, cap, tos;

        void copy(const myStack<T>& other);
        void nukem();
};


template<typename T>
myStack<T>::myStack(int s, int c)
{
    stack = new T[msize = s];
    cap = c;
    tos = -1;
}

template<typename T>
myStack<T>::~myStack()
{
    nukem();
}

template<typename T>
myStack<T>::myStack(const myStack<T>& other)
{
    copy(other);
}

template<typename T>
myStack<T>& myStack<T>::operator=(const myStack<T> &other)
{
    if(this != &other)
    {
            nukem();
            copy(other);
    }
    return *this;
}


template<typename T>
void myStack<T>::push(const T &data)
{
    if(full())
        throw STACK_FULL;
    stack[++msize] = data;
}

template<typename T>
T myStack<T>::pop()
{
    if(empty())
        throw STACK_EMPTY;
    T data = stack[tos--];
    return data;
}


template<typename T>
myStack<T>& myStack<T>::operator<<(const T& data)
{
    push(data);
    return *this;
}

template<typename T>
myStack<T>& myStack<T>::operator>>( T& data)
{
    data = pop();
    return *this;
}

template<typename T>
T myStack<T>::peek()
{
    if(empty())
        throw STACK_EMPTY;
    return stack[tos];
}

template<typename T>
bool myStack<T>::empty()
{
    return tos == -1;
}

template<typename T>
bool myStack<T>::full()
{
    return tos + 1 == msize;
}

template<typename T>
int myStack<T>::size()
{
    return tos;
}

template<typename T>
int myStack<T>::capacity()
{
    return cap;
}

template<typename T>
void myStack<T>::clear()
{
    tos = -1;
}

template<typename A>
void swapItNow(A &z, A& y)
{
    A temp = z;
    z = y;
    y = temp;
}

template<typename T>
void myStack<T>::swap(myStack<T> &other)
{
    swapItNow(tos, other.tos);
    swapItNow(stack, other.stack);
    swapItNow(cap,other.cap);
    swapItNow(msize, other.msize);
}

template<typename T>
void myStack<T>::nukem()
{
    for(unsigned int i = 0; i < msize; ++i)
        stack[i] = T();
    delete [] stack;
    msize = 0;
    tos = -1;
}


template<typename U>
ostream& operator<<(ostream &out, const myStack<U> &s)
{
   if(&cout == &out)
   {
      for(unsigned int i = s.size(); i >=0;--i)
          out<<"stack["<<i<<"] = "<<s.stack[i]<<endl;

   }
   else
   {
        out<<"Size:"<<s.msize<<endl
           <<"Capacity:"<<s.cap<<endl
           <<"TOS:"<<s.tos;
        for(int i = s.tos; s > -1; --s)
            out<<s[i];
   }
   return out;
}

template<typename U>
istream& operator>>(istream &in, myStack<U> &s)
{
     U data;
     if(&in == & cin)
     {
        unsigned int size;
        cout<<"What size of a stack do you need? ";
        in>>size;
        s.resize(size);
        for(auto i : s.stack)
        {
            cout<<"Value: ";
            cin>>data;
            s<<data;
        }
     }
     else
     {
         char input;
         while((input=in.get())!=':');
         in>>s.msize;
         while((input=in.get())!=':');
         in>>s.cap;
         while((input=in.get())!=':');
         in>>s.tos;
         s.stack = new U[s.msize];
         for(unsigned int i = 0; i <=s.tos; ++i)
             in>>s.stack[i];
     }
     return in;
}

#endif // MYSTACK_H
