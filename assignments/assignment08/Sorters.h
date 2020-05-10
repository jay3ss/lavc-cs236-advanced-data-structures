/** @file Sorters.h
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
#ifndef SORTERS_H
#define SORTERS_H

// Enum used to decide which pivot to use
enum class Pivot {MEDIAN, MIDDLE};

/** Implements the insertion sort algorithm
@param: array the array to be sorted
@param: length the length of the array
@post: the array will be sorted in ascending order */
template <class T>
void insertion(T array[], const int length);

/** Implements the quick sort algorithm
@param: array the array to be sorted
@param: first the starting index of the subarray to sort
@param: last the ending index of the subarray to sort
@param: pivot switch that determines which pivot will be used in the algorithm
        (default is to sort using the median of the first, middle, & last
        values)
@post: the array will be sorted in ascending order */
template <class T>
void quickSort(T array[], const int first, const int last, Pivot pivot = Pivot::MEDIAN);

/** Implements the quick sort algorithm
@param: array the array to be sorted
@param: first the starting index of the subarray to sort
@param: last the ending index of the subarray to sort
@param: pivot switch that determines which pivot will be used in the algorithm
        (default is to sort using the median of the first, middle, & last
        values)
@post: the array will be sorted in ascending order */
template <class T>
void quickInsertionSort(T array[], const int first, const int last, Pivot pivot = Pivot::MEDIAN);

/** Finds the pivot point of a subarray using the median of the first, middle, &
    last values
@pre: the subarray's length should be >= 1
@param: array the subarray to find the pivot in
@param: first the starting index of the subarray to sort
@param: last the ending index of the subarray to sort */
template <class T>
T partitionMedian(T array[], const int first, const int last);

/** Finds the pivot point of an array using the middle value of the subarray
@param: array the array to find the pivot in
@param: first the starting index of the subarray
@param: last the ending index of the subarray */
template <class T>
T partitionMiddle(T array[], const int first, const int last);

/** Partitions the elements in the subarray (elements less than the pivot value
    go to the left of the pivot value & elements greater than go to the right)
@param: array the array to find the pivot in
@param: first the starting index of the subarray
@param: last the ending index of the subarray
@param: pivotIndex the index of the value to use as the pivot value
@post: the subarray will have elements less than the pivot value go to the left
        of the pivot value & elements greater than go to the right */
template <class T>
int partition(T array[], const int first, const int last, const int pivotIndex);

/** Swaps the contents of two variables
@param: item1 the first variable
@param: item2 the second variable
@post: the values of the variables will be swapped
*/
template <class T>
void swap(T &item1, T &item2);

#include "Sorters.cpp"
#endif // SORTERS
