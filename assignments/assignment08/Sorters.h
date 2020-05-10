#ifndef SORTERS_H
#define SORTERS_H

enum class Pivot {MEDIAN, MIDDLE};

template <class T>
void insertion(T array[], const int length);

template <class T>
void quickSort(T array[], const int first, const int last, Pivot pivot = Pivot::MEDIAN);

template <class T>
void quickInsertionSort(T array[], const int first, const int last, Pivot pivot = Pivot::MEDIAN);

template <class T>
T partitionMedian(T array[], const int first, const int last);

template <class T>
T partitionMiddle(T array[], const int first, const int last);

template <class T>
int partition(T array[], const int first, const int last, const int pivotIndex);

template <class T>
void swap(T &item1, T &item2);

#include "Sorters.cpp"
#endif // SORTERS
