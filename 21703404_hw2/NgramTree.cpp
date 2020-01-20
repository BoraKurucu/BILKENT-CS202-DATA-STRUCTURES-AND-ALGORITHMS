#include "NgramTree.h"
#include <iostream>
#include <fstream>.
using namespace std;
/**
* Title : Binary Search Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 1
* Assignment : 2
*/
NgramTree::NgramTree()
{
    root = NULL;

}
TreeNode::TreeNode()
{
    item = "";
    count = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

NgramTree::~NgramTree()
{
    
}
int NgramTree::getTotalNgramCount()
{
    int cnt = 0;
    int cnt2 = 0;
    cntHelper(root,cnt,cnt2);
    return cnt;
}
void NgramTree::cntHelper(TreeNode * root,int & count,int &nodeNumber)
{
    if(root == NULL)
        return;
    count += 1;
    nodeNumber += 1;
    cntHelper(root->leftChildPtr,count,nodeNumber);
    cntHelper(root->rightChildPtr,count,nodeNumber);
}
bool NgramTree::isComplete()
{
    int cnt = 0;
    int cnt2 = 0;
    cntHelper(root,cnt,cnt2);
    int i = 0;
    bool check = true;
    compHelper(root,i,cnt2,check);
    return check;
}
void NgramTree::compHelper(TreeNode * root,int index,int total,bool & check)
{
    if(root == NULL)
        return;
    if(total <= index)
        check = false;
    compHelper(root->leftChildPtr,2*index+1,total,check);
    compHelper(root->rightChildPtr,2*index+2,total,check);
}
bool NgramTree::isFull()
{
    bool k = fullHelper(root);
 
    return k;
}
bool NgramTree::fullHelper(TreeNode * root)
{
    if(root == NULL)
        return true;

   if(root->leftChildPtr == NULL && root->rightChildPtr == NULL)
    return true;

   if(root->leftChildPtr == NULL || root->rightChildPtr == NULL)
    return false;
 	

    return( fullHelper(root->leftChildPtr) && fullHelper(root->rightChildPtr));

    return false;

}
void NgramTree::printNgramFrequencies()
{
    printHelper(root);
}
void NgramTree::printHelper(TreeNode * root)
{
     if(root == NULL)
        return;

    printHelper(root->leftChildPtr);

    cout<<root->item << " appears " << " ( " << root->count << " ) " <<" time(s)"<<endl;
 
    printHelper(root->rightChildPtr);
}
void NgramTree::addNgram(string ngram)
{
 bool exist = false;
 TreeNode * node = new TreeNode();

 string sample;
 for(int i = 0; i < ngram.length();i++)
 {
     if(ngram[i] != ' ')
        sample = sample + ngram[i];
 }
ngram = sample;
 bool k = retriever(sample,root,node);


if(k == false)
{
 addHelper(ngram,root);
}
else
{
    node->count += 1;
}


}
void NgramTree::addHelper(string ngram,TreeNode *& treePtr)
{
if(treePtr == NULL)
{
treePtr = new TreeNode();
treePtr->count += 1;
treePtr->item = ngram;
}
else if(ngram.compare(treePtr->item) < 0)
{
    addHelper(ngram,treePtr->leftChildPtr);
}
else
{
    addHelper(ngram,treePtr->rightChildPtr);
}

}
bool NgramTree::retriever(string ngram,TreeNode * root,TreeNode *& target)
{
    if(root == NULL)
        return NULL;

    if(ngram == root->item)
    {
        target = root;
        return true;
    }

   return( retriever(ngram,root->leftChildPtr,target) || retriever(ngram,root->rightChildPtr,target));
    return false;
}
void NgramTree::generateTree(string fileName,int n)
{
        string text;

   ifstream input;
    input.open(fileName);


    while (input >> text)
    {
	int len = text.length();
        if (len >= n)
        {
	int diff = text.length()-n;
        int index = 0;
	while(index <= diff)
	{

                addNgram(text.substr(index,n));
		index += 1;
	}
	
        }
    }




}
