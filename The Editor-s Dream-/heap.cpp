#include "heap.h"

/** Constructor with default parameter of 100 elements **/
Heap::Heap(int mSize)
    : size(0), maxSize(mSize)
{
    heap = new Word[maxSize + 1];
}

/** Find the location/index of parent node of a given position **/
int Heap::parent(int pos) const
{
    return pos / 2;
}

/** Find the location/index of Left child node of a given position **/
int Heap::left(int pos) const
{
    return pos * 2;
}

/** Find the location/index of Right child node of a given position **/
int Heap::right(int pos) const
{
    return pos * 2 + 1;
}

/** Check if given node is a leaf node at a given position **/
bool Heap::isLeaf(int pos) const
{
    if (pos >= (size / 2) && pos <= size)
    {
        return true;
    }

    return false;
}

/** Function to swap two elements of the Heap **/
void Heap::swap(int fpos, int spos)
{
    Word tmp = heap[fpos];
    heap[fpos] = heap[spos];
    heap[spos] = tmp;
}

/** Helper function to heapify the Heap to maintain the order **/
void Heap::heapify(int pos)
{
    if (!isLeaf(pos))
    {
        if (heap[pos] > heap[left(pos)]  ||
            heap[pos] > heap[right(pos)])
        {
            if (heap[left(pos)] < heap[right(pos)])
            {
                swap(pos, left(pos));
                heapify(left(pos));
            }
            else
            {
                swap(pos, right(pos));
                heapify(right(pos));
            }
        }
    }
}

void Heap::insert(Word element)
{
    if (size + 1 >= maxSize)
    {
        grow();
    }

    heap[++size] = element;
    int current = size;

    //maintain order
    while (heap[current] < heap[parent(current)])
    {
        swap(current, parent(current));
        current = parent(current);
    }
}

void Heap::grow()
{
    //current array
    Word * tmp = new Word[maxSize + 1];

    //copy
    for (int i = 0; i<size; i++)
    {
        tmp[i] = heap[i];
    }

    //Resize
    maxSize *= 2;
    heap = new Word[maxSize + 1];

    //copy back
    for (int i = 0; i<size; i++)
    {
        heap[i] = tmp[i];
    }
}

void Heap::perculate()
{
    for (int pos = (size / 2); pos >= 1; pos--)
    {
        heapify(pos);
    }
}

Word Heap::remove()
{
    Word popped = heap[FRONT];
    heap[FRONT] = heap[size--];
    heapify(FRONT);
    return popped;
}

bool Heap::isEmpty() const
{
    return size == 0;
}

/** Helper function to see if an element exists **/
int Heap::exists(string w) const
{
    int index = -1;

    for (int i = FRONT; i <= size; i++)
    {
        if (heap[i].word == w)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** Helper function to update the word count and line numbers **/
void Heap::update(int index, int lineNumber)
{
    if (index >= FRONT && index <= size)
    {
        heap[index].count += 1;
        heap[index].lineNumbers.push_back(lineNumber);
    }
}
