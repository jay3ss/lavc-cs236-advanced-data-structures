#ifndef SORT_H
#define SORT_H

namespace sort
{
template <class T>
void selection(T array[], const int length);

template <class T>
void bubble(T array[], const int length);

template <class T>
void insertion(T array[], const int length);

template <class T>
void merge();

template <class T>
void quick();

template <class T>
void radix();

template <class T>
void parallelMerge();

template <class T>
int pivot(T array[], int left, int right);

template <class T>
void swap(T &item1, T &item2);

template <class T>
int min(T array[], const int start, const int end);
} // namespace sort


#include "sort.cpp"
#endif // SORT_H
