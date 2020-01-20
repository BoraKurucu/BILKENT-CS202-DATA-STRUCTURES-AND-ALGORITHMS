#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sorting.h"
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
* Description : main file
*/


using namespace std;

int main()
{

    Sorting sort;

    int comp = 0;
    int move = 0;

    int arr[] =  {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,14, 2, 8, 10, 5};
    int arr2[] =  {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,14, 2, 8, 10, 5};
    int arr3[] =  {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,14, 2, 8, 10, 5};
    int arr4[] =  {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,14, 2, 8, 10, 5};
    int size = 16;

    int first1 = 0;
    int last1 = size - 1;
    int first2 = 0;
    int last2 = size - 1;

    sort.bubbleSort(arr,size,comp,move);
    sort.printArray(arr,size);

    sort.quickSort(arr2,first1,last1,comp,move);
    sort.printArray(arr2,size);

    sort.mergeSort(arr3,first2,last2,comp,move);
    sort.printArray(arr3,size);

    sort.radixSort(arr4,size);
    sort.printArray(arr4,size);

    sort.performanceAnalysis();



    return 0;
}
