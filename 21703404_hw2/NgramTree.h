#ifndef NGRAMTREE_H
#define NGRAMTREE_H
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


class TreeNode { 	// a node in the tree
public:
		TreeNode();



		string item; 		// a data item in the tree
		TreeNode *leftChildPtr;	// pointers to children
		TreeNode *rightChildPtr;
		int count;


	// friend class - can access private parts
	friend class BinarySearchTree;
};
class NgramTree
{
public :
NgramTree ();
~ NgramTree ();
void addNgram (string ngram );
int getTotalNgramCount ();
void printNgramFrequencies ();
bool isComplete ();
bool isFull ();
void generateTree ( string fileName , int n );

bool retriever(string ngram,TreeNode * root,TreeNode *& target);
void addHelper(string ngram,TreeNode *& treePtr);
void cntHelper(TreeNode * root,int & count,int & nodeNumber);
void printHelper(TreeNode * root);
void compHelper(TreeNode * root,int index,int total,bool & check);
bool fullHelper(TreeNode * root);
private:
TreeNode * root;
};
#endif // NGRAMTREE_H
