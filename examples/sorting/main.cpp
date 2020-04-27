#include <iostream>
#include "sort.h"

template <class T>
void copyArray(T orig[], T copy[], const int length);

template <class T>
void printArray(T array[], const int length);

int main()
{
    const int listLength = 10;
    int list[] = {2, 7, 26, 25, 19, 17, 1, 90, 3, 36};
    int list2[listLength];
    copyArray(list, list2, listLength);

    printArray(list2, listLength);
    sort::selection(list2, listLength);
    printArray(list2, listLength);
}

template <class T>
void printArray(T array[], const int length)
{
    for (int i = 0; i < length; i++)
        std::cout << array[i] << " ";

    std::cout << "\n";
}

template <class T>
void copyArray(T orig[], T copy[], const int length)
{
    for (int i = 0; i < length; i++)
        copy[i] = orig[i];
}
