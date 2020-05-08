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
T pivotMedian(const T array[], const int first, const int last)
{
    // To guard against overflow
    const int middle = first + (last - first) / 2;
    T values = {array[first], array[middle], array[last]};

    // Sort the array and then the middle value in the sorted
    // array is the median
    insertion(values, 0, 2);

    return values[1];
}

template <class T>
T pivotMiddle(const T array[], const int first, const int last)
{
    // To guard against overflow
    const int middle = first + (last - first) / 2;

    // return the middle element of the array
    return array[middle];
}

template <class T>
void swap(T &item1, T &item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}
