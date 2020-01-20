    #ifndef HUFFMANCODE_H
    #define HUFFMANCODE_H
    using namespace std;
    #include <iostream>
    #include "HuffmanQueue.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/


    class HuffmanCode
    {
        public:
            HuffmanCode();
            MinHeapNode * buildHuffman(HuffmanQueue *& huffmanq,int n);
            void mark();



        private:
    };

    #endif // HUFFMANCODE_H
