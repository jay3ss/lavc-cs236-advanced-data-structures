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
