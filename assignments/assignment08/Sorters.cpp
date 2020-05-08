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
void swap(T &item1, T &item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}
