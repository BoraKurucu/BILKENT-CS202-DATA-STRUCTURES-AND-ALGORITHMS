#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
/**
* Title : Algorithm Efficiency and Sorting
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 1
* Description :headers
*/


class Sorting
{
    public:
        Sorting();
        void bubbleSort(int *arr, int size, int &compCount, int &moveCount);
        void quickSort(int *arr, int first,int last, int &compCount, int &moveCount);

        void mergeSort( int * theArray, int first, int last,int &compCount, int &moveCount);

        void radixSort(int *arr, int size);
        void performanceAnalysis();

        void merge( int * theArray, int first, int mid, int last,int &compCount, int &moveCount);
        void swap(int &x, int &y);

        void printArray(int * arr, int size);
        int partition(int * theArray, int first, int last,int &compCount, int &moveCount,int & pivotIndex);

        int myPow(int x, int p);
        int getMax(int * arr,int size);
        void timeMerge(int * arr,int size);
        void timeQuick(int * arr,int size);
        void timeBubble(int * arr,int size);
        void timeRadix(int * arr,int size);

    private:
};

#endif // SORTING_H
