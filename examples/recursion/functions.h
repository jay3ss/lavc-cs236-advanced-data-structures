#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace recursive
{
int factorial(const int number);
int combinations(const int group, const int members);
template <class T>
int binarySearch(const T array[], const T value, const int start, const int end);
template <class T>
void quickSort(T array[], const int first, const int last);
template <class T>
int split(T array[], const int first, const int last);
};


namespace iterative
{
int factorial(const int number);
};

// Exception for invalid input
class InvalidInput {};

namespace helper
{
template <class T>
void swap(T& a, T& b);
template <class T>
void printArray(const T array[], const int length);
};

#include "functions.cpp"
#endif // FUNCTIONS_H
