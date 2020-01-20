#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H
#include "MaxHeap.h"
#include "MinHeap.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


class MedianHeap
{
    public:
        MedianHeap(int maxSize = 50);
        void insert (int value );
        int findMedian();

    protected:

    private:

        int sizeHeap;
        int maxItems;
        MaxHeap * maxHeap;
        MinHeap * minHeap;



};

#endif // MEDIANHEAP_H
