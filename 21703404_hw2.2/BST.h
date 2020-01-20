/**
* Title : Binary Search Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 2
* Description :BST header,public functions use private functions as helper functions,especially for recursive functions this is needed
*/
#ifndef BST_H
#define BST_H
#include "BSTNode.h"
#include <cstddef>
#include <iostream>
using namespace std;
class BST
{
    public:
    BST();
    BST(int value);
    void insertItem(int key);
    void deleteItem(int key);
    BSTNode * retrieveItem(int key);
    bool containsSequence(int* seq, int length);
    int countNodesDeeperThan(int level);
    int maxBalancedHeight();
    int * inorderTraversal(int& length);


    private:
     BSTNode * root;
     void insertItem(BSTNode *& root,int key);
     void retrieveItem(BSTNode * source,int searchKey,BSTNode *& retrieved);
     void processLeftmost(BSTNode *&nodePtr,int& treeItem);
     int findLength(BSTNode * root);
     bool InArray(int * ar,int size,int value);
     BSTNode * containsSequence(BSTNode * root,int* arr, int length);
     void traverseFromStart(BSTNode * root,int * arr,int &index,int &track);
     void countNodesDeeperThan(BSTNode * root,int level,int &count,int start);
     int calcHeight(BSTNode * root);
     int maxBalancedHeight(BSTNode * root);
     void deleteItem(BSTNode * &nodePtr, int searchKey);
     void deleteNodeItem(BSTNode *& nodePtr);
     void printAr(int * arr,int length);
     void inorderTraversal(BSTNode * root,int& length,int *&ar,int &index);




};

#endif // BST_H
