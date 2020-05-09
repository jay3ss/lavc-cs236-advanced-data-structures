#include "Sorters.h"

template <class T>
void insertion(T array[], const int length)
{
    for (int i = 1; i < length; i++)
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

template <class T>
T partitionMedian(T array[], const int first, const int last)
{
    // To guard against overflow
    const int middle = first + (last - first) / 2;

    T firstValue = array[first];
    T middleValue = array[middle];
    T lastValue = array[last-1];

    // criteria for choosing a median value
    // first:   middle < first < last OR last < first < middle
    // middle:  first < middle < last OR last < middle < first
    // last:    first < last < middle OR middle < last < first

    int pivotIndex = first;
    int swapIndex;
    T pivotValue;
    if ((middleValue < firstValue && firstValue < lastValue) || // first is median
        (lastValue < firstValue && firstValue < middleValue))
    {
        pivotValue = firstValue;
        swapIndex = first;
    }
    else if ((firstValue < middleValue && middleValue < lastValue) || // middle is median
             (lastValue < middleValue && middleValue < firstValue))
    {
        pivotValue = middleValue;
        swapIndex = middle;
    }
    else // last is median
    {
        pivotValue = lastValue;
        swapIndex = last - 1;
    }

    // 1. swap the first element of the array with the pivot value
    // 2. then move it back while putting smaller values ahead of it
    swap(array[first], array[swapIndex]);

    // we're not trying to sort the array, just move values less than the pivot
    // value to the left and values greater than the pivot value to the right
    for (int i = first + 1; i <= last; i++)
    {
        if (array[i] < pivotValue)
        {
            pivotIndex++;
            swap(array[i], array[pivotIndex]);
        }
    }
    swap(array[first], array[pivotIndex]);

    // return the index of the pivot
    return pivotIndex;
}

template <class T>
T partitionMiddle(T array[], const int first, const int last)
{
    // to guard against overflow don't add two potentially very large numbers
    const int middle = first + (last - first) / 2;

    // use the value at the middle of the array as the pivot
    const T pivotValue = array[middle];

    // 1. swap the first element of the array with the pivot (middle) value
    // 2. then move it back while putting smaller values ahead of it
    swap(array[first], array[middle]);
    int pivotIndex = first;

    // we're not trying to sort the array, just move values less than the pivot
    // value to the left and values greater than the pivot value to the right
    for (int i = first + 1; i <= last; i++)
    {
        if (array[i] < pivotValue)
        {
            pivotIndex++;
            swap(array[i], array[pivotIndex]);
        }
    }
    swap(array[first], array[pivotIndex]);

    // return the index of the pivot
    return pivotIndex;
}

template <class T>
void swap(T& item1, T& item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}
