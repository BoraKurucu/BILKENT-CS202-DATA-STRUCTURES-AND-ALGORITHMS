#ifndef OPENHASHTABLE_H
#define OPENHASHTABLE_H


using namespace std;
#include <iostream>
#include <string>
#include "Node.h"
#include <vector>
#include <numeric>
#include <chrono>

class OpenHashTable
{
    public:
        OpenHashTable();
        virtual ~OpenHashTable();
        int hashF(string name);
        void insert(string name,int amount,double & time,int & collision);
        void search(string name);
        void deleteN(string name);
        void retrieve(string name,int & comparison);
        void print();
        bool comp(string s1,string s2);
        void timeAnalyser(double elapsed,int collision);



    private:
        int tableSize;
        int currentSize;
        Node * ar;
};

#endif // OPENHASHTABLE_H
