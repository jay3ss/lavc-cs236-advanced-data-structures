#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "Heap.h"

using namespace std;

// uint32_t SEED = time(0);
uint32_t SEED = NULL;
mt19937 RNG;

void initRng();

int main()
{
    Heap<int> heap;

    // const int SIZE = 9;
    // vector<int> list = {1, 7, 3, 4, 9, 11, 3, 1, 2};
    // vector<int> list = {1, 2, 3, 4, 5, 6, 7};
    // vector<int> list = {6, 2, 7, 9, 5, 3, 4, 8, 10, 1};
    vector<int> list = {2,7,26,25,19,17,1,90,3,36};

    int element = 0;
    try
    {
        element = heap.max();
    }
    catch (const Heap<int>::EmptyHeap)
    {
        std::cerr << "ERROR: can't get max value, heap is empty\n";
    }

    try
    {
        heap.remove();
    }
    catch(const Heap<int>::EmptyHeap)
    {
        std::cerr << "ERROR: can't remove max value, heap is empty\n";
    }

    for (auto& item : list)
        heap.add(item);

    int MAX_VALUE = 90;

    try
    {
        element = heap.max();
    }
    catch(const Heap<int>::EmptyHeap)
    {
        std::cerr << "ERROR: heap is empty\n";
    }
    assert(MAX_VALUE == element);
    cout << "The max value in the heap should be the max value in the vector: "
         << "PASSED\n";

    initRng();
    shuffle(list.begin(), list.end(), RNG);

    for (auto &item : list)
        heap.remove();
}

void initRng()
{
    RNG.seed(SEED);
}
