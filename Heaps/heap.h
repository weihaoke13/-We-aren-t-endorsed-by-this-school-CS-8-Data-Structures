#include <vector>
#include <iostream>
#include <functional>

#define MAX_VALUE 999999
const int StartIndex = 1;

using namespace std;


template <class ElemType,class Compare = less<ElemType> >
class MyHeap{
private:
    vector<ElemType> heapDataVec;
    int numCounts;
    Compare comp;

public:
    MyHeap();

    vector<ElemType> getVec();

    void initHeap(ElemType *data,const int n);
    void printfHeap();
    void makeHeap();
    void sortHeap();
    void pushHeap(ElemType elem);
    void popHeap();
    void adjustHeap(int childTree,ElemType adjustValue);
    void percolateUp(int holeIndex,ElemType adjustValue);
};

template <class ElemType,class Compare>
MyHeap<ElemType,Compare>::MyHeap()
:numCounts(0)
{
    heapDataVec.push_back(MAX_VALUE);
}

template <class ElemType,class Compare>
vector<ElemType> MyHeap<ElemType,Compare>::getVec()
{
    return heapDataVec;
}

template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::initHeap(ElemType *data,const int n)
{

    for (int i = 0;i < n;++i)
    {
        heapDataVec.push_back(*(data + i));
        ++numCounts;
    }
}

template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::printfHeap()
{
    cout << "Heap : ";
    for (int i = 1;i <= numCounts;++i)
    {
        cout << heapDataVec[i] << " ";
    }
    cout << endl;
}

template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::makeHeap()
{

    if (numCounts < 2)
        return;

    int parent = numCounts / 2;
    while(1)
    {
        adjustHeap(parent,heapDataVec[parent]);
        if (StartIndex == parent)
            return;

        --parent;
    }
}

template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::sortHeap()
{

    while(numCounts > 0)
        popHeap();
}

template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::pushHeap(ElemType elem)
{

    heapDataVec.push_back(elem);
    ++numCounts;


    percolateUp(numCounts,heapDataVec[numCounts]);
}

template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::popHeap()
{

    ElemType adjustValue = heapDataVec[numCounts];

    heapDataVec[numCounts] = heapDataVec[StartIndex];

    --numCounts;

    adjustHeap(StartIndex,adjustValue);
}


template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::adjustHeap(int childTree,ElemType adjustValue)
{

    int holeIndex = childTree;
    int secondChid = 2 * holeIndex + 1;
    while(secondChid <= numCounts)
    {
        if (comp(heapDataVec[secondChid],heapDataVec[secondChid - 1]))
        {
            --secondChid;
        }


        heapDataVec[holeIndex] = heapDataVec[secondChid];
        holeIndex = secondChid;/
        secondChid = 2 * secondChid + 1;
    }
    if (secondChid == numCounts + 1)
    {

        heapDataVec[holeIndex] = heapDataVec[secondChid - 1];
        holeIndex = secondChid - 1;
    }
    //
    heapDataVec[holeIndex] = adjustValue;

    //
    percolateUp(holeIndex,adjustValue);
}

//
template <class ElemType,class Compare>
void MyHeap<ElemType,Compare>::percolateUp(int holeIndex,ElemType adjustValue)
{
    //
    //
    int parentIndex = holeIndex / 2;
    while(holeIndex > StartIndex && comp(heapDataVec[parentIndex],adjustValue))
    {
        heapDataVec[holeIndex] = heapDataVec[parentIndex];
        holeIndex = parentIndex;
        parentIndex /= 2;
    }
    heapDataVec[holeIndex] = adjustValue;//
}
