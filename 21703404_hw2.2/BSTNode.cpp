/**
* Title : Binary Search Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 2
* Description : implementations of functions in the header
*/
#include "BSTNode.h"
#include <cstddef>
#include <iostream>
using namespace std;
BSTNode::BSTNode(int value)
{
    item = value;
    leftChild = NULL;
    rightChild = NULL;

}
BSTNode::BSTNode()
{
    item = 0;
    leftChild = NULL;
    rightChild = NULL;
}
int BSTNode::getKey()
{
    return item;
}
void BSTNode::operator=(const BSTNode * right)
{

    if(right != NULL)
    {
        item = right->item;
        leftChild = right->leftChild;
        rightChild = right->rightChild;
    }
    else
    {

        item = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
}
void BSTNode::operator=(const BSTNode &right)
{


    if(&right != this)
    {

    item = right.item;
    leftChild = right.leftChild;
    rightChild = right.rightChild;
    }
    else
    {


    }
}
void BSTNode::setKey(int val)
{
    item = val;
}
BSTNode::~BSTNode()
{
item = 0;
delete leftChild;
delete rightChild;
leftChild = NULL;
rightChild = NULL;
}
