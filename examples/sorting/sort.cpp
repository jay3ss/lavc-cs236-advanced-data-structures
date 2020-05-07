#include "sort.h"

namespace sort
{
const int MAX_ARRAY_SIZE = 100000;

template <class T>
void selection(T array[], const int length)
{
    // 1. Set "current" to the first index of the array
    // 2. Find the smallest value in the array
    // 3. Swap the smallest value with the value in current
    // 4. Increment current and repeat steps 2 to 4 until the
    //    end of the array is reached
    for (int i = 0; i < length; i++)
    {
        int smallest = min(array, i, length);
        swap(array[smallest], array[i]);
    }
}

template <class T>
void bubble(T array[], const int length)
{
    // 1. Set "current" to the first index of the array
    // 2. For every index from the start of the list to then end minus 1, swap
    //    adjacent pairs of elements that are out of order
    // 3. Increment current and repeat steps 2 and 3
    // 4. Stop when current is at the end of the array
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }
}

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
void merge(T array[], const int start, const int end)
{
    if (start < end)
    {
        // Use this formula to account for any overflow
        const int middle = start + (end - start) / 2;

        // 1. Sort the left half of the array
        // 2. Sort the right half of the array
        // 3. Merge the two sorted halves
        merge(array, start, middle);
        merge(array, middle + 1, end);
        mergeArrays(array, start, middle, end);
    }
}

template <class T>
void mergeArrays(T array[], const int start, const int middle , const int end)
{
    T tempArray[MAX_ARRAY_SIZE];
    // T tempArray[end * 2];
    int firstLeft = start;
    int lastLeft = middle;

    int firstRight = middle + 1;
    int lastRight = end;

    // while both subarrays are not empty, copy the smaller item into the
    // temporary array
    int index = firstLeft;
    while ((firstLeft <= lastLeft) && (firstRight <= lastRight))
    {
        if (array[firstLeft] <= array[firstRight])
        {
            tempArray[index] = array[firstLeft];
            firstLeft++;
        }
        else
        {
            tempArray[index] = array[firstRight];
            firstRight++;
        }
        index++;
    }

    // copy the remaining elements into the temp array
    while (firstLeft <= lastLeft)
    {
        tempArray[index] = array[firstLeft];
        firstLeft++;
        index++;
    }

    while (firstRight <= lastRight)
    {
        tempArray[index] = array[firstRight];
        firstRight++;
        index++;
    }

    // copy the merged temp array back into the array
    for (int i = start; i <= end; i++)
        array[i] = tempArray[i];
}

template <class T>
void quick()
{

}

template <class T>
void radix()
{

}

template <class T>
void parallelMerge()
{

}

template <class T>
int pivot(T array[], int left, int right)
{
    return -1;
}

template <class T>
void swap(T& item1, T& item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}

// Finds the smallest value in the array (starting at the given starting index
// and ending at the given end index) and returns its index
template <class T>
int min(T array[], const int start, const int end)
{
    int smallest = start;

    for (int i = start + 1; i < end; i++)
    {
        if (array[i] < array[smallest])
        {
            smallest = i;
        }
    }

    return smallest;
}
} // namespace sort
