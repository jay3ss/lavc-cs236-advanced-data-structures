/** @file Sorters.cpp
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
#include "Sorters.h"

// Implements the insertion sort algorithm
template <class T>
void insertion(T array[], const int first, const int last)
{
    // go through each element and insert it into the correct location
    for (int i = first; i <= last; i++)
    {
        int location = i;
        T item = array[location];

        while ((location > 0) && (array[location - 1] > item))
        {
            swap(array[location - 1], array[location]);
            location--;
        }
        array[location] = item;
    }
}

// Implements the quick sort algorithm
template <class T>
void quickSort(T array[], const int first, const int last, const Pivot pivot)
{
    int pivotPoint;

    if (first < last)
    {
        switch (pivot)
        {
        case Pivot::MEDIAN:
            pivotPoint = partitionMedian(array, first, last);
            break;
        // Pivot::MIDDLE
        default:
            pivotPoint = partitionMiddle(array, first, last);
            break;
        }
        quickSort(array, first, pivotPoint, pivot);
        quickSort(array, pivotPoint + 1, last, pivot);
    }
}

// Implements the quick sort algorithm
template <class T>
void quickInsertionSort(T array[], const int first, const int last, Pivot pivot)
{
    int pivotPoint;

    if (first < last)
    {
        // if the size of the subarray is less than or equal to 20, then use
        // insertion sort to sort the array. otherwise, keep using the quicksort
        // algorithm
        if (last - first <= 20)
        {
            insertion(array, first, last);
        }
        else
        {
            switch (pivot)
            {
            case Pivot::MEDIAN:
                pivotPoint = partitionMedian(array, first, last);
                break;
            // Pivot::MIDDLE
            default:
                pivotPoint = partitionMiddle(array, first, last);
                break;
            }
            quickSort(array, first, pivotPoint, pivot);
            quickSort(array, pivotPoint + 1, last, pivot);
        }
    }
}

// Finds the pivot point of a subarray using the median of the first, middle, &
// last values
template <class T>
T partitionMedian(T array[], const int first, const int last)
{
    // To guard against overflow
    const int middle = first + (last - first) / 2;

    const T firstValue = array[first];
    const T middleValue = array[middle];
    const T lastValue = array[last-1];

    // criteria for choosing a median value
    // first:   middle < first < last OR last < first < middle
    // middle:  first < middle < last OR last < middle < first
    // last:    first < last < middle OR middle < last < first

    int pivotIndex;
    T pivotValue;
    if ((middleValue < firstValue && firstValue < lastValue) || // first is median
        (lastValue < firstValue && firstValue < middleValue))
    {
        pivotIndex = first;
    }
    else if ((firstValue < middleValue && middleValue < lastValue) || // middle is median
             (lastValue < middleValue && middleValue < firstValue))
    {
        pivotIndex = middle;
    }
    else // last is median
    {
        pivotIndex = last - 1;
    }

    // return the index of the pivot
    return partition(array, first, last, pivotIndex);
}

// Finds the pivot point of an array using the middle value of the subarray
template <class T>
T partitionMiddle(T array[], const int first, const int last)
{
    // to guard against overflow don't add two potentially very large numbers
    const int middle = first + (last - first) / 2;

    // return the index of the pivot
    return partition(array, first, last, middle);
}

// Partitions the elements in the subarray (elements less than the pivot value
// go to the left of the pivot value & elements greater than go to the right)
template <class T>
int partition(T array[], const int first, const int last, const int pivotIndex)
{
    // use the value at the middle of the array as the pivot
    const T pivotValue = array[pivotIndex];

    // 1. swap the first element of the array with the pivot (middle) value
    // 2. then move it back while putting smaller values ahead of it
    swap(array[first], array[pivotIndex]);
    int index = first;

    // we're not trying to sort the array, just move values less than the pivot
    // value to the left and values greater than the pivot value to the right
    for (int i = first + 1; i <= last; i++)
    {
        if (array[i] < pivotValue)
        {
            index++;
            swap(array[i], array[index]);
        }
    }
    swap(array[first], array[index]);

    return index;
}

// Swaps the contents of two variables
template <class T>
void swap(T& item1, T& item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}
