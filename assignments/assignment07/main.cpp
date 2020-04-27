/** @file main.cpp
CS 236
Joshua Saunders
Assignment 7 - Heap sort
Removing the root in a heap – after the root is removed, the tree must be
rebuilt to maintain the heap property.

Adding a new node – to add a new node to the heap, first add it to the end of
the heap and then rebuild the tree.

To test the header file, write the heapSort function and use the given main
program */
#include <iostream>
#include "Heap.h"

using namespace std;

template <class T>
void heapSort(T list[], int arraySize);

int main()
{
    const int SIZE = 9;
    int list[] = { 1, 7, 3, 4, 9, 11, 3, 1, 2 };
    heapSort(list, SIZE);
    cout << "Sorted elements using heap:\n";
    for (int i = 0; i < SIZE; i++)
        cout << list[i] << " ";

    cout << endl;

    return 0;
}

template <class T>
void heapSort(T list[], const int arraySize)
{
    const int middleIndex = arraySize / 2 - 1;
    int index = 0;

    for (index = middleIndex; index >= 0; index--)
        Heap<T>::heapifyDown(list, index, arraySize);

    for (index = arraySize - 1; index > 0; index--)
    {
        swap(list[0], list[index]);
        Heap<T>::heapifyDown(list, 0, index);
    }
}
