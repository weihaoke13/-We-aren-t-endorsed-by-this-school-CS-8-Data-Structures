#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdlib>
#include "word.h"

using namespace std;

const int FRONT = 1;

class Heap
{
public:
    /** Constructor with default parameter of 100 elements **/
    Heap(int mSize = 100);

    /** Insert new element into the Heap **/
    void insert(Word);

    /** Helper function to check if the heap is empty **/
    bool isEmpty() const;

    /** Function to remove the minimum element from the heap **/
    Word remove();

    /** Helper function to see if an element exists **/
    int exists(string) const;

    /** Helper function to update the word count and line numbers **/
    void update(int, int);

private:
    Word  * heap;
    int size;
    int maxSize;

    /** Find the location/index of parent node of a given position **/
    int parent(int) const;

    /** Find the location/index of Left child node of a given position **/
    int left(int) const;

    /** Find the location/index of Right child node of a given position **/
    int right(int) const;

    /** Check if given node is a leaf node at a given position **/
    bool isLeaf(int) const;

    /** Function to swap two elements of the Heap **/
    void swap(int, int);

    /** Helper function to heapify the Heap to maintain the order **/
    void heapify(int);

    /** Helper utility to grow the size of heap array if needed **/
    void grow();

    /** helper function to maintain the heap order **/
    void perculate();
};
#endif
