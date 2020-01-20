#include "MaxHeap.h"
#include <iostream>
using namespace std;
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


MaxHeap::MaxHeap(int maxSize)
{
    items = new int[maxSize];
    for(int i = 0; i < maxSize;i++)
        items[i] = 0;
    sizeHeap = 0;
    maxItems = maxSize;
}

MaxHeap::~MaxHeap()
{
   if(items)
    delete[] items;
    sizeHeap = 0;

}
void MaxHeap::insert(int value)
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
 while ( (place > 0) && (items[place] > items[parent]) ) {
  int temp = items[parent];
  items[parent] = items[place];
  items[place] = temp;

  place = parent;
  parent = (place - 1)/2;
 }
  ++sizeHeap;
}
int MaxHeap::peek()
{
    return items[0];
}
void MaxHeap::heapRebuild(int root)
{
  int child = 2 * root + 1;  // index of root's left child, if any
 if ( child < sizeHeap ) {
  // root is not a leaf so that it has a left child
  int rightChild = child + 1;  // index of a right child, if any
  // If root has right child, find larger child
  if ( (rightChild < sizeHeap) &&
       (items[rightChild] >items[child]) )
   child = rightChild;  // index of larger child

  // If root’s item is smaller than larger child, swap values
  if ( items[root] < items[child] ) {
    int temp = items[root];
   items[root] = items[child];
   items[child] = temp;

   // transform the new subtree into a heap
   heapRebuild(child);
  }

}
}
int MaxHeap::extractMax()
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

int MaxHeap::size()
{
    return sizeHeap;
}
