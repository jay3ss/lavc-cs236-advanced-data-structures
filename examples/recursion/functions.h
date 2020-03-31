#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace recursive
{
int factorial(const int number);
int combinations(const int group, const int members);
template <class T>
int binarySearch(const T array[], const T value, const int start, const int end);
};


namespace iterative
{
int factorial(const int number);
};

// Exception for invalid input
class InvalidInput {};

#include "functions.cpp"
#endif // FUNCTIONS_H
