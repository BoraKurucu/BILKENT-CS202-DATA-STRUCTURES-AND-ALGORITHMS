/**
* Title : Binary Search Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 2
* Description : implementations of functions in the header
*/
#include "BST.h"
#include <cstddef>
#include <iostream>
using namespace std;
BST::BST()
{
    root = NULL;
}
BST::BST(int value)
{
    root = NULL;
}
void BST::insertItem(int key)
{
insertItem(root,key);

}
void BST::insertItem(BSTNode *& root,int key)
{
    if (root == NULL) {
			root = new BSTNode(key);

		}
		// Else search for the insertion position
		else if (key < root->getKey())
			insertItem(root->leftChild, key);
		else
			insertItem(root->rightChild, key);

}
BSTNode * BST::retrieveItem(int key)
{
    BSTNode * temp = new BSTNode(0);
    retrieveItem(root,key,temp);
    return temp;

}
void BST::retrieveItem(BSTNode * source,int searchKey,BSTNode *& retrieved)
{
if (source == NULL)
{
    return;
}
else if (searchKey == source->getKey())
retrieved = source;
else if (searchKey < source->getKey())
retrieveItem(source->leftChild, searchKey,retrieved);
else
retrieveItem(source->rightChild, searchKey,retrieved);
}
void BST::deleteItem(int key)
{
 deleteItem(root,key);
}
void BST:: deleteItem(BSTNode * &nodePtr, int searchKey)
{
    if (nodePtr == NULL) // Empty tree
			return;

		// Position of deletion found
		else if (searchKey == nodePtr->getKey())
			deleteNodeItem(nodePtr);

		// Else search for the deletion position
		else if (searchKey < nodePtr->getKey())
			deleteItem(nodePtr->leftChild,searchKey);
		else
			deleteItem(nodePtr->rightChild,searchKey);
}
void BST::deleteNodeItem(BSTNode *& nodePtr)
{
BSTNode *delPtr;
  int replacementItem;


  // (1)  Test for a leaf
  if ( (nodePtr->leftChild == NULL) &&
       (nodePtr->rightChild == NULL) ) {
   delete nodePtr;
   nodePtr = NULL;
  }


  // (2)  Test for no left child
  else if (nodePtr->leftChild == NULL){
   delPtr = nodePtr;
   nodePtr = nodePtr->rightChild;
   delPtr->rightChild = NULL;
   delete delPtr;
  }

  // (3)  Test for no right child
  else if (nodePtr->rightChild == NULL) {
   delPtr = nodePtr;
   nodePtr = nodePtr->leftChild;
   delPtr->leftChild = NULL;
   delete delPtr;
  }
  else {
   processLeftmost(nodePtr->rightChild, replacementItem);
   nodePtr->setKey(replacementItem);
  }

}
void BST::processLeftmost(BSTNode *&nodePtr,
        int& treeItem){

  if (nodePtr->leftChild == NULL) {
   treeItem = nodePtr->getKey();
   BSTNode *delPtr = nodePtr;
   nodePtr = nodePtr->rightChild;
   delPtr->rightChild = NULL; // defense
   delete delPtr;
  }
  else
   processLeftmost(nodePtr->leftChild, treeItem);
}
 bool BST::containsSequence(int* seq, int length)
 {
    int checker = findLength(root);
    if(checker < length)
    {
        cout<<"No visited node, array's length is bigger than tree's length, it does not contain the sequence"<<endl;
        return false;
    }
    BSTNode * temp = containsSequence(root,seq,length);
    int track = 0;
    int index = 0;
    traverseFromStart(temp,seq,length,track);
    if( track == length)
    {
        cout<<"it contains the sequence"<<endl;
        return true;
    }
    cout<<"it does not contain the sequence"<<endl;
    return false;
 }
//goes to staring to prevent visiting unnesaccary nodes
BSTNode * BST:: containsSequence(BSTNode * root,int* arr, int length)
{

      for( int i  = 0;i < length;i++)
      {

      int k = 0;
      while(root->getKey() > arr[length-1] && !(InArray(arr,length,root->getKey())))
      {
          cout<<"Visited root is: "<< root->getKey()<<endl;
          root = root ->leftChild;
          if(root == NULL)
            return root;
           /*if( !(root->getKey() > arr[length-1] && !(InArray(arr,length,root->getKey()))))
            return root;
            */
      }
       while(root->getKey() < arr[length-1] && !(InArray(arr,length,root->getKey())))
      {
          cout<<"Visited root is: "<< root->getKey()<<endl;
          root = root -> rightChild;
          if(root == NULL)
            return root;
          /*if( !(root->getKey() < arr[length-1] && !(InArray(arr,length,root->getKey()))))
            return root;
            */
      }
      }
      return root;
}
//it traverses from a root inorder and checks if the array exists inorder
void BST::traverseFromStart(BSTNode * root,int * arr,int &length,int &track)
{
    if(root == NULL)
    {
        return;
    }
    //do not go lower than necessity
    if(root->getKey() > arr[0])
    traverseFromStart(root->leftChild,arr,length,track);

    cout<<"Visited root is: "<< root->getKey()<<endl;

    if( InArray(arr,length,root->getKey()))
    {


        track++;
    }
    else
    {

        track--;
        return;
    }
    //do not go higher than necessity
    if(root ->getKey() < arr[length - 1])
    traverseFromStart(root->rightChild,arr,length,track);
}
 bool BST :: InArray(int * ar,int size,int value)
 {

     for(int i = 0;i < size;i++)
     {
        if(ar[i] == value)
        {
        return true;
        }

     }
     return false;
 }
int BST::countNodesDeeperThan(int level)
{
    if(level <= 0)
    {
        cout<<"level should be at least 1"<<endl;
        return 0;
    }
    int count = 0;
    int start = 1;
    countNodesDeeperThan( root,level,count,start);
    cout<<"deeper count for level "<< level<<" is "<<count<<endl;
    return count;
}
void BST::countNodesDeeperThan(BSTNode * root,int level,int &count,int start)
{
    if(level <= 0)
    {
        count = 0;
        return;
    }
    if(root == NULL)
        return;
    //go to the desired level
    if(start < level)
    {
    countNodesDeeperThan( root->leftChild,level,count,start+1);
    countNodesDeeperThan( root->rightChild,level,count,start+1);
    }
    else
    {
    countNodesDeeperThan( root->leftChild,level,count,start);
    count++;
    countNodesDeeperThan( root->rightChild,level,count,start);
    }
}
int BST::maxBalancedHeight()
{
int count = 0;
count = calcHeight(root);
cout<<"max balanced height is "<<count<<endl;
return count;
}
int BST:: calcHeight(BSTNode * root)
{
if(root == NULL)
    return 0;

   int l = calcHeight(root -> leftChild);
   int r =  calcHeight(root -> rightChild);
//if root,decide depending on the difference between children
if( l == 0 && r == 0)
{
    return 1;
}
//if left or right is 0
else if( l == 0 || r == 0)
{
  return 2;

}
//if their abs difference <= 1, this does not corrupt balance
else if( l - r >= -1 && l - r <= 1)
{

    if( l > r)
        return l + 1;
    return r + 1;
}
//if difference is more than 1, add 1 to smaller one, add 1 for the root
else
{
    if( l > r)
    {
        return r + 2;
    }
    else if(l == r)
    {
        return l + 1;
    }
    else
    {
        return l + 2;
    }
}
}
//find number of nodes
int BST::findLength(BSTNode * root)
{
     if(root == NULL)
        return 0;
     return 1 + findLength(root->leftChild) + findLength(root->rightChild);
}
int* BST::inorderTraversal(int& length)
{
    length = findLength(root);
    int index = 0;
    int * ar = new int[length];
    inorderTraversal(root,length,ar,index);
    printAr(ar,length);
    return ar;
}
//simple inorder traversal and stroing the tree in an array
void BST::inorderTraversal(BSTNode * root,int& length,int *&ar,int &index)
{
    if(root == NULL)
        return;
    inorderTraversal(root ->leftChild,length,ar,index);
    ar[index] = root->getKey();
    index++;
    inorderTraversal(root ->rightChild,length,ar,index);

}
void BST::printAr(int * arr,int length)
{
    cout<<"the array is: ";
    for(int i =0;i < length;i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<""<<endl;
}

