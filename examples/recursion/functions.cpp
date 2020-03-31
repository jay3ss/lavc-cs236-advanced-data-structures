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
