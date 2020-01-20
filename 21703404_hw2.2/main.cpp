/**
* Title : Binary Search Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 2
* Description : Main file,tests the functions
*/
#include <iostream>
#include <cstddef>
#include "BST.h"
using namespace std;

int main()
{
    BST tree;

    tree.insertItem(8);
    tree.insertItem(4);
    tree.insertItem(13);
    tree.insertItem(3);
    tree.insertItem(1);

    tree.insertItem(2);
    tree.insertItem(6);
    tree.insertItem(5);

    tree.insertItem(12);
    tree.insertItem(10);
    tree.insertItem(15);
    tree.insertItem(14);


  cout<<"Tree and the inputs are same with the ones in the homework but other cases are also tested."<<endl;
    int * ar = new int[6];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    tree.containsSequence(ar, 6);
    delete[] ar;
   cout<<"first trial finished"<<endl;
   cout<<" " <<endl;

    int * ar2 = new int[4];
    ar2[0] = 10;
    ar2[1] = 12;
    ar2[2] = 13;
    ar2[3] = 15;
    tree.containsSequence(ar2, 4);
     delete[] ar2;
    cout<<"second trial finished"<<endl;
    cout<<" " <<endl;

    int * ar3 = new int[3];
    ar3[0] = 10;
    ar3[1] = 11;
    ar3[2] = 12;
    tree.containsSequence(ar3, 3);
     delete[] ar3;
    cout<<"third trial finished"<<endl;
    cout<<" " <<endl;

    int k = tree.countNodesDeeperThan(0);
    k = tree.countNodesDeeperThan(1);
    k = tree.countNodesDeeperThan(2);
    k = tree.countNodesDeeperThan(3);
    k = tree.countNodesDeeperThan(4);
    k = tree.countNodesDeeperThan(5);
    k = tree.countNodesDeeperThan(6);
    cout<<"fourth trial finished"<<endl;
    cout<<" " <<endl;

    tree.maxBalancedHeight();
    cout<<"fifth trial finished"<<endl;
    cout<<" " <<endl;

    cout<<"trial of inorderTraversal"<<endl;
    int len = 0;
    int * ar5 = tree.inorderTraversal(len);
    cout<<"sixth trial finished"<<endl;
    cout<<" " <<endl;

    cout<<"trial of delete 13, inorder used to print"<<endl;
    tree.deleteItem(13);
    tree.inorderTraversal(len);
    cout<<"end,thank you"<<endl;


    return 0;
}
