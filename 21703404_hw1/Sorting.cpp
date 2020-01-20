#include "Sorting.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
/**
* Title : Algorithm Efficiency and Sorting
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 1
* Description :swap functions here.
*/

Sorting::Sorting()
{
}
void Sorting::swap(int &x, int &y) {
  int temp = x;
   x = y;
   y = temp;
}
void Sorting:: bubbleSort(int *arr, int size, int &compCount, int &moveCount)
{
bool sorted = false;
 for (int pass = 1; (pass < size) && !sorted; ++pass) {
      sorted = true;
      for (int index = 0; index < size-pass; ++index) {
         int nextIndex = index + 1;
         compCount++;
         if (arr[index] > arr[nextIndex]) {
            moveCount = moveCount + 2;
            swap(arr[index], arr[nextIndex]);
            sorted = false; // signal exchange
         }
      }
   }

}

void Sorting:: printArray(int * arr, int size)
{
    cout<<""<<endl;
    for(int i = 0; i < size;i++)
    cout<<arr[i]<< " ";
    cout<<""<<endl;
}

void Sorting:: quickSort(int *arr, int first,int last, int &compCount, int &moveCount)
{

    int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(arr, first, last,compCount,moveCount,pivotIndex);

      // sort regions S1 and S2
      quickSort(arr, first,pivotIndex-1,compCount,moveCount);
      quickSort(arr, pivotIndex+1,last,compCount,moveCount);
   }
}

 int Sorting:: partition(int theArray[], int first, int last,int &compCount, int &moveCount,int &pivotIndex){
  int pivot = theArray[first]; // copy pivot
         // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      compCount++;
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
		  moveCount = moveCount + 2;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   moveCount = moveCount + 2;
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;

  return lastS1;

}


int Sorting::myPow(int x, int p) {
    int result = 1;
  if(p == 0)
    return 1;
  for( int i = 0;i < p;i++)
  {
      result = result * x;
  }
  return result;
}

int Sorting::getMax(int * arr,int size)
{
    int maxx = -999;
    for(int i = 0;i < size;i++)
    {
        if(maxx < arr[i])
            maxx = arr[i];
    }
    return maxx;
}
int getDigits(int max)
{
    if(max < 10)
        return 1;
    else
        return 1 + getDigits(max/10);
}

void Sorting::radixSort(int *arr, int size)
{

    int n = size;
    int max = getMax(arr,size);
    int d = getDigits(max);


    for(int j = 1; j<=d;j++)
    {

        int counts[10][size];

        for( int y = 0;y < 10;y++)
            for( int e = 0;e<size;e++)
        {
            counts[y][e] = 0;
        }

        int counters[10];
        for(int t = 0; t <10;t++)
            counters[t] = 0;

        for(int i = 0;i < n;i++)
        {
            int g = 0;
            if(j == 1 )
                g = arr[i]%10;
            else {

                g = arr[i]/myPow(10,j-1);
                g = g%myPow(10,j-1);
            }

            if (g > 9){
                counts[0][counters[0]] = arr[i];
                counters[0] += 1;
            }
            else{
                counts[g][counters[g]] = arr[i];
                counters[g] += 1;
            }
        }
        int index = 0;
         for(int i = 0; i <10;i++){

             for(int j = 0; j <counters[i];j++){

                 arr[index] = counts[i][j];
                 index++;
             }
         }
    }


}
void Sorting:: mergeSort( int * theArray, int first, int last,int &compCount, int &moveCount)
 {
if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergeSort(theArray, first, mid, compCount,  moveCount);


      mergeSort(theArray, mid+1, last,compCount, moveCount);

      // merge the two halves
      merge(theArray, first, mid, last,compCount,moveCount);

   }

   return;
 }
void Sorting:: merge( int * theArray, int first, int mid, int last,int &compCount, int &moveCount) {

	int tempArray[30000]; 	// temporary array

    int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
      if (theArray[first1] < theArray[first2]) {
          moveCount++;
         tempArray[index] = theArray[first1];
         ++first1;
      }
      else {
          moveCount++;
          tempArray[index] = theArray[first2];
          ++first2;
      }
   }
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
   {
       moveCount++;
      tempArray[index] = theArray[first1];
   }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
   {
       moveCount++;
      tempArray[index] = theArray[first2];
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
   {
       moveCount++;
      theArray[index] = tempArray[index];
   }

}
void Sorting::performanceAnalysis()
{
    int max = 2000;
    srand(time(NULL));

    int arr1[max];
    int arr2[max];
    int arr3[max];
    int arr4[max];

   for( int i = 0;i < max;i++)
   {
      int element = rand() % 1000;
      arr1[i] = element;
      arr2[i] = element;
      arr3[i] = element;
      arr4[i] = element;
   }

    int max2 = 6000;

    int arr5[max2];
    int arr6[max2];
    int arr7[max2];
    int arr8[max2];

   for( int i = 0;i < max2;i++)
   {
      int element = rand() % 1000;
      arr5[i] = element;
      arr6[i] = element;
      arr7[i] = element;
      arr8[i] = element;
   }
    int max3 = 10000;

    int arr9[max3];
    int arr10[max3];
    int arr11[max3];
    int arr12[max3];

   for( int i = 0;i < max3;i++)
   {
      int element = rand() % 1000;
      arr9[i] = element;
      arr10[i] = element;
      arr11[i] = element;
      arr12[i] = element;
   }

      int max4 = 14000;

    int arr13[max4];
    int arr14[max4];
    int arr15[max4];
    int arr16[max4];

   for( int i = 0;i < max4;i++)
   {
      int element = rand() % 1000;
      arr13[i] = element;
      arr14[i] = element;
      arr15[i] = element;
      arr16[i] = element;
   }
      int max5 = 18000;

    int arr17[max5];
    int arr18[max5];
    int arr19[max5];
    int arr20[max5];

   for( int i = 0;i < max5;i++)
   {
      int element = rand() % 1000;
      arr17[i] = element;
      arr18[i] = element;
      arr19[i] = element;
      arr20[i] = element;
   }
   int max6 = 22000;

    int arr21[max6];
    int arr22[max6];
    int arr23[max6];
    int arr24[max6];

   for( int i = 0;i < max6;i++)
   {
      int element = rand() % 1000;
      arr21[i] = element;
      arr22[i] = element;
      arr23[i] = element;
      arr24[i] = element;
   }
 int max7 = 26000;

    int arr25[max7];
    int arr26[max7];
    int arr27[max7];
    int arr28[max7];

   for( int i = 0;i < max7;i++)
   {
      int element = rand() % 1000;
      arr25[i] = element;
      arr26[i] = element;
      arr27[i] = element;
      arr28[i] = element;
   }
    int max8 = 30000;

    int arr29[max8];
    int arr30[max8];
    int arr31[max8];
    int arr32[max8];

   for( int i = 0;i < max8;i++)
   {
      int element = rand() % 1000;
      arr29[i] = element;
      arr30[i] = element;
      arr31[i] = element;
      arr32[i] = element;
   }

cout<<"------------------------"<<endl;
cout<<" part c time analysis of radix sort\n"<<endl;
cout<<"Array Size\tTime Elapsed\t"<<endl;
timeRadix(arr2,max);
timeRadix(arr6,max2);
timeRadix(arr9,max3);
timeRadix(arr13,max4);
timeRadix(arr17,max5);
timeRadix(arr21,max6);
timeRadix(arr25,max7);
timeRadix(arr29,max8);

cout<<"------------------------"<<endl;
cout<<" part c time analysis of bubble sort\n"<<endl;
cout<<"Array Size\tTime Elapsed\tCompCount\tMoveCount\t\n"<<endl;
timeBubble(arr1,max);
timeBubble(arr5,max2);
timeBubble(arr10,max3);
timeBubble(arr14,max4);
timeBubble(arr18,max5);
timeBubble(arr22,max6);
timeBubble(arr26,max7);
timeBubble(arr30,max8);

cout<<"------------------------"<<endl;
cout<<" part c time analysis of quick sort\n"<<endl;
cout<<"Array Size\tTime Elapsed\tCompCount\tMoveCount\t\n"<<endl;
timeQuick(arr4,max);
timeQuick(arr8,max2);
timeQuick(arr12,max3);
timeQuick(arr16,max4);
timeQuick(arr20,max5);
timeQuick(arr24,max6);
timeQuick(arr28,max7);
timeQuick(arr32,max8);


cout<<"------------------------"<<endl;
cout<<" part c time analysis of merge sort\n"<<endl;
cout<<"Array Size\tTime Elapsed\tCompCount\tMoveCount\t\n"<<endl;
timeMerge(arr3,max);
timeMerge(arr7,max2);
timeMerge(arr11,max3);
timeMerge(arr15,max4);
timeMerge(arr19,max5);
timeMerge(arr23,max6);
timeMerge(arr27,max7);
timeMerge(arr31,max8);
}
void Sorting::timeMerge(int * arr,int size)
{
 int f = 0;
 int l = size -1;
 int comp = 0;
 int mov = 0;

    //Declare necessary variables
std::chrono::time_point< std::chrono::system_clock > startTime;
std::chrono::duration< double, milli > elapsedTime;
//Store the starting time
startTime = std::chrono::system_clock::now();
//Code block

for(int i = 0; i< 5;i++)
{
 f = 0;
 l = size -1;
 comp = 0;
 mov = 0;
 mergeSort(arr,f,l,comp,mov);
}
//Compute the number of seconds that passed since the starting time
elapsedTime = std::chrono::system_clock::now() - startTime;
//*********
cout<<size<<"      \t"<<elapsedTime.count()/5<<"     \t"<<comp<<"   \t"<<mov<<endl;
}
void Sorting::timeBubble(int * arr,int size)
{
    //Declare necessary variables
std::chrono::time_point< std::chrono::system_clock > startTime;
std::chrono::duration< double, milli > elapsedTime;
//Store the starting time
startTime = std::chrono::system_clock::now();
//Code block
int comp = 0;
int mov = 0;
for(int i = 0; i< 10;i++)
bubbleSort(arr,size,comp,mov);
//Compute the number of seconds that passed since the starting time
elapsedTime = std::chrono::system_clock::now() - startTime;


//cout << "Execution for it " <<  n << " took " << elapsedTime.count()/100 << " milliseconds." << endl;
cout<<size<<"      \t"<<elapsedTime.count()/10<<"     \t"<<comp<<"   \t"<<mov<<endl;
}
void Sorting::timeRadix(int * arr,int size)
{
    //Declare necessary variables
std::chrono::time_point< std::chrono::system_clock > startTime;
std::chrono::duration< double, milli > elapsedTime;
//Store the starting time
startTime = std::chrono::system_clock::now();
//Code block
for(int i = 0; i< 100;i++)
radixSort(arr,size);
//Compute the number of seconds that passed since the starting time
elapsedTime = std::chrono::system_clock::now() - startTime;
cout<<size<<"      \t"<<elapsedTime.count()/100<<"     \t"<<endl;
}

void Sorting::timeQuick(int * arr,int size)
{
 int f = 0;
int l = size -1;
int comp = 0;
int mov = 0;
    //Declare necessary variables
std::chrono::time_point< std::chrono::system_clock > startTime;
std::chrono::duration< double, milli > elapsedTime;
//Store the starting time
startTime = std::chrono::system_clock::now();
//Code block
for(int i = 0; i< 5;i++)
{
 f = 0;
 l = size -1;
 comp = 0;
 mov = 0;
 quickSort(arr,f,l,comp,mov);
}
//Compute the number of seconds that passed since the starting time
elapsedTime = std::chrono::system_clock::now() - startTime;
cout<<size<<"      \t"<<elapsedTime.count()/5<<"     \t"<<comp<<"   \t"<<mov<<endl;
}

