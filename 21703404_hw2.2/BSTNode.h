/**
* Title : Binary Search Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 2
* Description : Header for BSTNode, item is private
*/
#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
#include <cstddef>
using namespace std;

class BSTNode
{
    public:
    BSTNode(int value = 0);
    BSTNode();
    int getKey();
    void setKey(int val);
    void operator=(const BSTNode & right);
    void operator=(const BSTNode * right);

    BSTNode * leftChild;
	BSTNode * rightChild;

    ~BSTNode();
    private:
    int item;

};

#endif // BSTNODE_H
