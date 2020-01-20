    #include "HuffmanCode.h"
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
*/

    HuffmanCode::HuffmanCode()
    {

    }
    MinHeapNode * HuffmanCode::buildHuffman(HuffmanQueue *& huffmanq,int n)
    {
    for(int i = 0; i < n - 1;i++)
    {
    MinHeapNode * node = new MinHeapNode();
    MinHeapNode * x;
    MinHeapNode * y;
    node->left= huffmanq->extractMin();
    x = node->left;
    node->right = huffmanq->extractMin();
    y = node->right;
    //cout<<" x freq is "<<x->freq<<" y freq is "<<y->freq<<endl;
    node->freq = x->freq + y->freq;
    huffmanq->insert(node);
    }
    return huffmanq->extractMin();

    }

