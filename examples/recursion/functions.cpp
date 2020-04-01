#include "functions.h"

namespace recursive
{

int factorial(const int number)
{
    // number must not be negative
    if (number < 0)
    {
        throw InvalidInput();
    }

    if (number == 0)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}

int combinations(const int group, const int members)
{
    if (group <= 0 || members <= 0)
    {
        throw InvalidInput();
    }

    if (members == 1)
    {
        return group;
    }
    else if (members == group)
    {
        return 1;
    }
    else
    {
        return combinations(group - 1, members -1) +
               combinations(group - 1, members);
    }

}

template <class T>
int binarySearch(const T array[], const T value, const int start, const int end)
{
    // We've gone out of bounds and couldn't find the value in the array
    if (start > end)
    {
        return -1;
    }

    int middle = start + (end - start) / 2;

    if (array[middle] == value)
    {
        return middle;
    }
    else if (array[middle] < value)
    {
        return binarySearch(array, value, middle + 1, end);
    }
    else if (array[middle] > value)
    {
        return binarySearch(array, value, start, middle - 1);
    }
    else
    {
        return -1;
    }
}

template <class T>
void quickSort(T array[], const int first, const int last)
{
    if (first < last)
    {
        int splitPoint = split(array, first, last);
        quickSort(array, first, splitPoint - 1);
        quickSort(array, splitPoint + 1, last);
    }
}

template <class T>
int split(T array[], const int first, const int last)
{
    int middle = first + (last - first) / 2;

    helper::swap(array[first], array[middle]);

    int splitPoint = first;
    T splitValue = array[splitPoint];

    for (int scan = first + 1; scan <= last; scan++)
    {
        if (array[scan] < splitValue)
        {
            splitPoint++;
            helper::swap(array[splitPoint], array[scan]);
        }
    }

    helper::swap(array[first], array[splitPoint]);

    return splitPoint;
}
};

namespace iterative
{

int factorial(const int number)
{
    if (number < 0)
    {
        throw InvalidInput();
    }

    int fact = 1;
    for (int n = number; n > 1; n--)
    {
        fact = fact * n;
    }

    return fact;
}
};

namespace helper
{
template <class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void printArray(const T array[], const int length)
{
    std::cout << "{ ";

    for (int i = 0; i < length - 1; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << array[length - 1] << " }";
}
}
