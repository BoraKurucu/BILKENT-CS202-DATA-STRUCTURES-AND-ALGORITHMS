    #include "HuffmanQueue.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/

    HuffmanQueue::HuffmanQueue()
    {
        heap = new HuffmanHeap();
    }
    void HuffmanQueue::insert(MinHeapNode * node)
    {
        heap->insert(node);
    }
    MinHeapNode * HuffmanQueue::extractMin()
    {
        return heap->extractMin();
    }
