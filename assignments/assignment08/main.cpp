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

// Populates an array with random values from a uniform distribution within the
// range of <start, stop>
void randomArray(int array[], const int size, const int start, const int stop);

// Copies the contents of one array into another
void copyArray(const int orig[], int copy[], const int length);

// Times the runtime of a function (in clock cycles)
int timeQuickSort(int array[], const int size, const Pivot pivot, const Callback cb);

// Times the amount of time it takes for the various quick sort methods to run
void timeAllQuickSorts(int array[], const int size);

// Converts the number of clock cycles into milliseconds
double clocksToMilli(const int clocks);

uint32_t SEED = time(0);
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

/** Populates an array with random values from a uniform distribution within the
range of <start, stop>
@pre: start < stop
@param: array the array to populate with random values
@param: size the size of the array
@param: start the start of the range of the random values
@param: end the end of the range of the random values
@post: any values in the array will be overwritten */
void randomArray(int array[], const int size, const int start, const int stop)
{
    uniform_int_distribution<int> dist(start, stop);

    for (int i = 0; i < size; i++)
    {
        array[i] = dist(RNG);
    }
}

/** Copies the contents of one array into another
@pre: the length of copy >= the length of orig
@param: orig the array to be copied
@param: copy the array that will have the values copied into
@param: length the length of the array
@post: any values in the array will be overwritten */
void copyArray(const int orig[], int copy[], const int length)
{
    for (int i = 0; i < length; i++)
        copy[i] = orig[i];
}

/** Times the runtime of a function (in clock cycles)
@param: array the array
@param: size the size of the array
@param: pivot the enum to determine which pivot to use (middle, or median)
@param: cb the callback function to time
@return: the amount of time (in clock cycles) */
int timeQuickSort(int array[], const int size, const Pivot pivot, const Callback cb)
{
    clock_t startTime = clock();
    cb(array, 0, size, pivot);
    clock_t endTime = clock();

    return endTime - startTime;
}

/** Sorts a copy of the using the following methods

- quick sort with the middle index as the pivot
- quick sort with the index of the median of the first, middle, & last values
  as the pivot
- quick sort with the middle index as the pivot and using insertion sort for
  subarrays with a length <= 20
- quick sort with the index of the median of the first, middle, & last values
  as the pivot and using insertion sort for subarrays with a length <= 20

and times the run time for the execution of each method of sorting and displays
the amount of time it takes in milliseconds. The display will be similar to

Array size: 100000
Quick sort time, with pivot middle element: 19.755 ms
Quick sort time, with pivot median element: 20.811 ms
Quick sort and insertion time, with pivot middle element: 19.835 ms
Quick sort and insertion time, with pivot middle median: 21.315 ms

@pre: the array should not be empty
@param: array the array to be sorted
@param: size the size of the array
@post: the statistics of the run time will be displayed in the terminal */
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

/** Converts the number of clock cycles into milliseconds
@param: clocks the number of clock cycles
@return: the number of milliseconds */
double clocksToMilli(const int clocks)
{
    return static_cast<double>(1000.0 * clocks / CLOCKS_PER_SEC);
}
