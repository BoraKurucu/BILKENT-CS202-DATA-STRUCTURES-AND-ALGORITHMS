#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
using namespace std;
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


class MaxHeap
{
    public:
        MaxHeap(int maxSize = 30);
        virtual ~MaxHeap();
        void insert (int value );
        int peek ();
        int extractMax();
        void heapRebuild(int root);
        int size();
         int * items;



    private:

        int sizeHeap;
        int maxItems;
};

#endif // MAXHEAP_H
