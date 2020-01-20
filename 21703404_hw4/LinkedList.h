#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;
#include <iostream>
#include <string>
#include "Node.h"

struct ItemNode
{
    Node data;
    ItemNode * next;
};
class LinkedList
{
    public:
        LinkedList();
        void insert(string name,int amount);
        void deleteI(string name);
        Node  search2(string name, int & comparison,bool & found);
        bool comp(string s1,string s2);
        void print();
        bool isEmpty();
        void eq(ItemNode * n1, ItemNode * n2);
        virtual ~LinkedList();

    protected:

    private:
        ItemNode * root;
        ItemNode * tail;

        int size;
};

#endif // LINKEDLIST_H
