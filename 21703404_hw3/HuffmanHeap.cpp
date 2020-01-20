#include "HuffmanHeap.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/

HuffmanHeap::HuffmanHeap()
{
    for(int i = 0; i < 400;i++)
    {
        items[i] = NULL;
    }
    sizeHeap = 0;

}
void HuffmanHeap::insert(MinHeapNode * node)
{
if (sizeHeap >= 400)
{
  cout<<"Heap is full."<<endl;
  return;
}

 items[sizeHeap] = node;

 // Trickle new item up to its proper position
 int place = sizeHeap;
 int parent = (place - 1)/2;
 while ( (place > 0) && (items[place]->freq < items[parent]->freq) ) {
  MinHeapNode * temp = items[parent];
  items[parent] = items[place];
  items[place] = temp;

  place = parent;
  parent = (place - 1)/2;
 }
  ++sizeHeap;
}

void HuffmanHeap::heapRebuild(int root)
{
  int child = 2 * root + 1;
 if ( child < sizeHeap ) {
  int rightChild = child + 1;

  if ( (rightChild < sizeHeap) &&
       (items[rightChild]->freq < items[child]->freq) )
   child = rightChild;


  if ( items[root]->freq > items[child]->freq ) {
   MinHeapNode * temp = items[root];
   items[root] = items[child];
   items[child] = temp;

   // transform the new subtree into a heap
   heapRebuild(child);
  }

}
}
MinHeapNode* HuffmanHeap::peek()
{
    return items[0];
}
MinHeapNode*  HuffmanHeap::extractMin()
{
    if(sizeHeap > 0)
    {
    MinHeapNode * node = items[0];
  items[0] = items[--sizeHeap];
  heapRebuild(0);
  return node;

    }
    return 0;
}
