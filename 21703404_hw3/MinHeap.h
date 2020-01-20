#ifndef MINHEAP_H
#define MINHEAP_H
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/

class MinHeap
{
    public:
        MinHeap(int maxSize = 50);
        virtual ~MinHeap();
        void insert (int value );
        int peek ();
        int extractMin();
        void heapRebuild(int root);
        int size();
        int * items;



    private:

        int sizeHeap;
        int maxItems;
};

#endif // MINHEAP_H
