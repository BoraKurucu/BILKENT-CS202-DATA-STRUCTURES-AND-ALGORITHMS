    #ifndef HUFFMANQUEUE_H
    #define HUFFMANQUEUE_H
    using namespace std;
    #include <iostream>
    #include "HuffmanHeap.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


    class HuffmanQueue
    {
        public:
            HuffmanQueue();
            void insert (MinHeapNode * node);
            MinHeapNode * extractMin();



        private:
            HuffmanHeap * heap;

    };

    #endif // HUFFMANQUEUE_H
