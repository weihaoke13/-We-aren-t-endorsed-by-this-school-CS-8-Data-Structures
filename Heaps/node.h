#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

template<typename T>
struct node
{
    T data;
    node* child[2];

    node(const T &d = T());
    ~node();
    node<T>& operator=(const node<T> &other);
    node(const node<T> &n);
    void swap(node<T> &x);

    template<typename U>
    friend
    ostream& operator<<(ostream& out, const node<U> &n);

    template<typename U>
    friend
    istream& operator>>(istream& in, node<U> &n);

    template<typename U>
    friend
    bool operator>(node<U> &x, node<U> &y);
};

template<typename T>
node<T>::node(const T &d)
{
    data = d;
    child[0] = child[1] = NULL;
}

template<typename T>
node<T>::~node()
{
    data = T();
    child[0] = child[1] = NULL;
}

template<typename T>
node<T>& node<T>::operator=(const node<T> &other)
{
    if(this != &other)
    {
        data = other.data;
    }
    return *this;
}

template<typename T>
node<T>::node(const node<T> &n)
{
    data = n.data;
    child[0] = child[1] = NULL;
}

template<typename T>
void node<T>::swap(node<T> &x)
{
    T temp = x.data;
    x.data = data;
    data = temp;
}

template<typename U>
ostream& operator<<(ostream& out, const node<U> &n)
{
    out<<n.data<<" ";
    return out;
}

template<typename U>
istream& operator>>(istream& in, node<U> &n)
{
    if(in>>n.data)
        n.child[0] = n.child[1] = NULL;
    return in;
}

template<typename U>
bool operator>(node<U> &x, node<U> &y)
{
    return x.data > y.data;
}

#endif // NODE_H
