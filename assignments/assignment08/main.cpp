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
#include <iostream>
#include <random>
#include "Sorters.h"

using namespace std;

void randomArray(int array[], const int size, const int start, const int stop);

uint32_t SEED = time(0);
// uint32_t SEED = NULL;
mt19937 RNG;

int main()
{
    // const int ARRAY_SIZE = 100000;
    const int ARRAY_SIZE = 10;

    const int START = -10000;
    const int END = 10000;

    clock_t startTime;
    clock_t endTime;

    RNG.seed(SEED);

    int array1[ARRAY_SIZE];
    int array2[3 * ARRAY_SIZE];

    randomArray(array1, ARRAY_SIZE, START, END);
    randomArray(array2, 3 * ARRAY_SIZE, START, END);

    quickSort(array1, 0, ARRAY_SIZE, Pivot::MIDDLE);

    cout << "Array size: " << ARRAY_SIZE << endl;
    cout << "Quick sort time, with pivot middle element: ";
    cout << endl;
    cout <<"Quick sort time, with pivot median element: ";
    cout << endl;
    cout << "Quick sort and insertion time, with pivot middle element: ";
    cout << endl;
    cout <<"Quick sort and insertion time, with pivot middle median: ";
    cout << endl << endl;

    cout << "Array size: " << 3 * ARRAY_SIZE << endl;
    cout << "Quick sort time, with pivot middle element: ";
    cout << endl;
    cout << "Quick sort time, with pivot median element: ";
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
