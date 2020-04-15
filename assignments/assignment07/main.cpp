#include <iostream>
#include "Heap.h"

using namespace std;

template <class T>
void heapSort(T list[], int arraySize)
{

}

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
