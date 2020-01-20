#include "MinHeap.h"
#include <iostream>
using namespace std;
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


MinHeap::MinHeap(int maxSize)
{
    items = new int[maxSize];
    for(int i = 0; i < maxSize;i++)
        items[i] = 0;
    sizeHeap = 0;
    maxItems = maxSize;
}

MinHeap::~MinHeap()
{
    if(items)
    delete[] items;
    sizeHeap = 0;

}
void MinHeap::insert(int value)
{
if (sizeHeap >= maxItems)
{
  cout<<"Heap is full."<<endl;
  return;
}

 // Place the new item at the end of the heap
 items[sizeHeap] = value;

 // Trickle new item up to its proper position
 int place = sizeHeap;
 int parent = (place - 1)/2;
 while ( (place > 0) && (items[place] < items[parent]) ) {
  int temp = items[parent];
  items[parent] = items[place];
  items[place] = temp;

  place = parent;
  parent = (place - 1)/2;
 }
  ++sizeHeap;
}
int MinHeap::peek()
{
    return items[0];
}
void MinHeap::heapRebuild(int root)
{
  int child = 2 * root + 1;
 if ( child < sizeHeap ) {
  int rightChild = child + 1;

  if ( (rightChild < sizeHeap) &&
       (items[rightChild] < items[child]) )
   child = rightChild;


  if ( items[root] > items[child] ) {
    int temp = items[root];
   items[root] = items[child];
   items[child] = temp;

   // transform the new subtree into a heap
   heapRebuild(child);
  }

}
}
int MinHeap::extractMin()
{
    if(sizeHeap > 0)
    {
        int rootItem = items[0];
  items[0] = items[--sizeHeap];
  heapRebuild(0);
  return rootItem;

    }
    return 0;
}

int MinHeap::size()
{
    return sizeHeap;
}
