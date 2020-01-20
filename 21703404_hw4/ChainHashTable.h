#ifndef CHAINHASHTABLE_H
#define CHAINHASHTABLE_H
using namespace std;
#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
#include <vector>
#include <numeric>
#include <chrono>

class ChainHashTable
{
    public:
        ChainHashTable();
        virtual ~ChainHashTable();
        int hashF(string name);
        void insert(string name,int amount,double & time);
        void search(string name);
        void retrieve(string name,int & comparison);
        void deleteC(string name);
        void timeAnalyser(double elapsed);
        void print();

    protected:

    private:
        int tableSize;
        int currentSize;
        LinkedList * ar;
};

#endif // CHAINHASHTABLE_H
