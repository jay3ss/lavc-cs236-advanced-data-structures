/** @file main.cpp
CS 236
Joshua Saunders
Assignment 8 - Quicksort
Write a program to sort an array of 100,000 random elements using quicksort as
follows:

1. Sort the arrays using pivot as the middle element of the array
2. Sort the arrays using pivot as the median of the first, last, and middle
   elements of the array
3. Sort the arrays using pivot as the middle element of the array. However, when
   the size of any sub-list reduces to less than 20, sort the sub-list using
   insertion sort.
4. Sort the array using pivot as the median of the first, last and middle
   elements of the array. When the size of any sub-list reduces to less than 20,
   sort the sub-list using insertion sort.
4. Calculate and display the CPU time for each of the preceding four steps.

Example of the median of the first, last and middle elements:

1 2 3 4 5 6 7 8 0 (median of 1, 5, 0 is 1)

8 0 1 2 3 4 5 6 7 (median of 8, 3, 7 is 7)

To calculate the CPU time, use the header <ctime>, and clock_t type. Depends on
the CPU of your computer, your number would not be the same as in the sample
output below.

Array size = 100000
Quick sort time, with pivot middle element: 37
Quick sort time, with pivot median element: 35
Quick sort and insertion time, with pivot middle element: 37
Quick sort and insertion time, with pivot middle median: 36

Array size = 300000
Quick sort time, with pivot middle element: 115
Quick sort time, with pivot median element: 115
Quick sort and insertion time, with pivot middle element: 110
Quick sort and insertion time, with pivot middle median: 110
*/
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iostream>
#include <random>
#include "Sorters.h"

using namespace std;

// typedef the function pointer so that we can have a clear parameter list for
// the timing function
typedef void (*Callback)(int array[], const int first, const int last, Pivot pivot);

void randomArray(int array[], const int size, const int start, const int stop);
void copyArray(const int orig[], int copy[], const int length);
int timeQuickSort(int array[], const int size, const Pivot pivot, const Callback cb);
void timeAllQuickSorts(int array[], const int size);
double clocksToMilli(const int clocks);

uint32_t SEED = time(0);
// uint32_t SEED = NULL;
mt19937 RNG;

int main()
{
    const int ARRAY_SIZE = 100000;
    const int LARGE_ARRAY_SIZE = ARRAY_SIZE * 3;

    const int START = -10000;
    const int END = 10000;


    int array1[ARRAY_SIZE];
    int array2[LARGE_ARRAY_SIZE];

    int numClocks = 0;

    RNG.seed(SEED);
    randomArray(array1, ARRAY_SIZE, START, END);
    randomArray(array2, LARGE_ARRAY_SIZE, START, END);

    timeAllQuickSorts(array1, ARRAY_SIZE);
    cout << endl;
    timeAllQuickSorts(array2, LARGE_ARRAY_SIZE);

    return 0;
}

void randomArray(int array[], const int size, const int start, const int stop)
{
    uniform_int_distribution<int> dist(start, stop);

    for (int i = 0; i < size; i++)
    {
        array[i] = dist(RNG);
    }
}

void copyArray(const int orig[], int copy[], const int length)
{
    for (int i = 0; i < length; i++)
        copy[i] = orig[i];
}

int timeQuickSort(int array[], const int size, const Pivot pivot, const Callback cb)
{
    clock_t startTime = clock();
    cb(array, 0, size, pivot);
    clock_t endTime = clock();

    return endTime - startTime;
}

void timeAllQuickSorts(int array[], const int size)
{
    int arraycopy[size];

    // Copy the array so that we can keep running the different sorting
    // implementations
    copyArray(array, arraycopy, size);

    cout << "Array size: " << size << endl;

    // Time the quick sort using the middle element as the pivot point
    cout << "Quick sort time, with pivot middle element: ";
    int numClocks = timeQuickSort(array, size, Pivot::MIDDLE, quickSort);
    cout << clocksToMilli(numClocks) << " ms\n";

    // Time the quick sort using the median element as the pivot point
    copyArray(arraycopy, array, size);
    numClocks = timeQuickSort(array, size, Pivot::MEDIAN, quickSort);
    cout << "Quick sort time, with pivot median element: ";
    cout << clocksToMilli(numClocks) << " ms\n";

    // Time the combination quick and insertion sort using the middle element
    // as the pivot point
    cout << "Quick sort and insertion time, with pivot middle element: ";
    copyArray(arraycopy, array, size);
    numClocks = timeQuickSort(array, size, Pivot::MIDDLE, quickInsertionSort);
    cout << clocksToMilli(numClocks) << " ms\n";

    // Time the combination quick and insertion sort using the median element
    // as the pivot point
    cout << "Quick sort and insertion time, with pivot middle median: ";
    copyArray(arraycopy, array, size);
    numClocks = timeQuickSort(array, size, Pivot::MEDIAN, quickInsertionSort);
    cout << clocksToMilli(numClocks) << " ms\n";
}

double clocksToMilli(const int clocks)
{
    return static_cast<double>(1000.0 * clocks / CLOCKS_PER_SEC);
}
