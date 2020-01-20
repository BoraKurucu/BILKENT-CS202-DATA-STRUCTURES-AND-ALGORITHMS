    #ifndef HUFFMANHEAP_H
    #define HUFFMANHEAP_H
    using namespace std;
    #include <iostream>
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/

    struct MinHeapNode
    {
    char character ; // An input character
    int freq ; // Frequency of the character
    MinHeapNode * left , * right ; // Left and right child
    };


    class HuffmanHeap
    {
        public:
            HuffmanHeap();
            void insert (MinHeapNode * node);
            MinHeapNode* peek();
            void heapRebuild(int root);
            MinHeapNode*  extractMin();



        private:
        MinHeapNode * items[400];
        int sizeHeap;


    };



    #endif // HUFFMANHEAP_H
