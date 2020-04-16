#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    Heap<int> heap;

    const int SIZE = 9;
    int list[] = {1, 7, 3, 4, 9, 11, 3, 1, 2};

    for (int i = 0; i < SIZE; i++)
        heap.add(list[i]);
}
