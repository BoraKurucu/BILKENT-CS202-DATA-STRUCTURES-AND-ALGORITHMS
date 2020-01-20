#include "MedianHeap.h"
#include "MaxHeap.h"
#include "MinHeap.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


MedianHeap::MedianHeap(int maxSize)
{
    sizeHeap = 0;
    maxItems = maxSize;
    maxHeap = new MaxHeap(maxSize);
    minHeap = new MinHeap(maxSize);

}
void MedianHeap::insert(int value)
{
if (sizeHeap >= maxItems)
{
  cout<<"Heap is full."<<endl;
  return;
}
int med;
if(sizeHeap % 2 == 0)
    med = minHeap->items[0];
else
    med= maxHeap->items[0];

if(med > value)
{
    //cout<<"increased in minheap "<<value<<endl;
    minHeap->insert(value);
}
else
{
    //cout<<"increased in maxheap "<<value<<endl;
    maxHeap->insert(value);
}
int temp = sizeHeap + 1;
//cout<<"temp is "<<temp<<endl;

if(maxHeap->size() - minHeap->size() > 1)
{
    int max = maxHeap->extractMax();
    minHeap->insert(max);
}
else if(minHeap->size() - maxHeap->size() > 1)
{
    int min = minHeap->extractMin();
    maxHeap->insert(min);
}
else
{
if(sizeHeap == 0)
   minHeap->items[0] = maxHeap->items[0];

}
sizeHeap++;
}
int MedianHeap::findMedian()
{
    cout<<"items "<<minHeap->items[0]<<endl;
    return minHeap->items[0];
}
