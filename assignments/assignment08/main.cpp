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

void randomArray(int array[], const int size, const int start, const int stop);
template <class T>
void copyArray(const T orig[], T copy[], const int length);

uint32_t SEED = time(0);
// uint32_t SEED = NULL;
mt19937 RNG;

int main()
{
    const int ARRAY_SIZE = 100000;
    const int LARGE_ARRAY_SIZE = ARRAY_SIZE * 3;

    const int START = -10000;
    const int END = 10000;

    clock_t startTime;
    clock_t endTime;

    RNG.seed(SEED);

    int array1[ARRAY_SIZE];
    int array1copy[ARRAY_SIZE];
    int array2[LARGE_ARRAY_SIZE];
    int array2copy[LARGE_ARRAY_SIZE];

    randomArray(array1, ARRAY_SIZE, START, END);
    copyArray(array1, array1copy, ARRAY_SIZE);

    randomArray(array2, LARGE_ARRAY_SIZE, START, END);
    copyArray(array2, array2copy, LARGE_ARRAY_SIZE);

    cout << "Array size: " << ARRAY_SIZE << endl;

    startTime = clock();
    quickSort(array1, 0, ARRAY_SIZE, Pivot::MIDDLE);
    endTime = clock();
    cout << "Quick sort time, with pivot middle element: ";
    cout << static_cast<double>(1000.0 * (endTime - startTime) / CLOCKS_PER_SEC) << "ms";
    cout << endl;

    copyArray(array1copy, array1, ARRAY_SIZE);
    startTime = clock();
    quickSort(array1, 0, ARRAY_SIZE); // Use the median value as pivot
    endTime = clock();

    cout << "Quick sort time, with pivot median element: ";
    cout << static_cast<double>(1000.0 * (endTime - startTime) / CLOCKS_PER_SEC) << "ms";
    cout << endl;
    cout << "Quick sort and insertion time, with pivot middle element: ";
    cout << endl;
    cout <<"Quick sort and insertion time, with pivot middle median: ";
    cout << endl << endl;

    cout << "Array size: " << LARGE_ARRAY_SIZE << endl;
    startTime = clock();
    quickSort(array2, 0, LARGE_ARRAY_SIZE); // Use the median value as pivot
    endTime = clock();
    cout << "Quick sort time, with pivot middle element: ";
    cout << static_cast<double>(1000.0 * (endTime - startTime) / CLOCKS_PER_SEC) << "ms";
    cout << endl;
    cout << "Quick sort time, with pivot median element: ";
    copyArray(array2copy, array2, LARGE_ARRAY_SIZE);
    startTime = clock();
    quickSort(array2, 0, LARGE_ARRAY_SIZE, Pivot::MEDIAN); // Use the median value as pivot
    endTime = clock();
    cout << static_cast<double>(1000.0 * (endTime - startTime) / CLOCKS_PER_SEC) << "ms";
    cout << endl;
    cout << "Quick sort and insertion time, with pivot middle element: ";
    cout << endl;
    cout << "Quick sort and insertion time, with pivot middle median: ";
    cout << endl;

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

template <class T>
void copyArray(const T orig[], T copy[], const int length)
{
    for (int i = 0; i < length; i++)
        copy[i] = orig[i];
}
