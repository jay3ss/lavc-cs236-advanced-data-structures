#include "sort.h"

namespace sort
{
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

}

template <class T>
void insertion()
{

}

template <class T>
void merge()
{

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
