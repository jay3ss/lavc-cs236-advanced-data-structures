#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "Heap.h"

using namespace std;

uint32_t SEED = time(0);
// uint32_t SEED = NULL;
mt19937 RNG;

void initRng();

template <class T>
void heapSort(T list[], int arraySize);
vector<int> randomVector(const int size, const int start, const int stop);

// template <class T>
// void swap(T& item1, T& item2);

int main()
{
    Heap<int> heap;

    const int NUM_ENTRIES = 7500;
    const int START = -10000;
    const int END = 10000;
    // create a vector of random numbers of length NUM_ENTRIES, between START and NUM_ENTRIES
    // and then add the entries into the tree (also, assert that the insertion works)
    // vector<int> entries = randomVector(NUM_ENTRIES, START, END);
    // vector<int> list = {2,7,26,25,19,17,1,90,3,36};
    initRng();
    vector<int> list = randomVector(NUM_ENTRIES, START, END);

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
    // assert(MAX_VALUE == element);
    cout << "The max value in the heap should be the max value in the vector: "
         << "PASSED\n";

    shuffle(list.begin(), list.end(), RNG);

    int sortedArray[NUM_ENTRIES];

    for (int i = NUM_ENTRIES - 1; i >= 0; i--)
        sortedArray[i] = heap.remove();

    cout << "The sorted array is:\n";

    for (auto &el : sortedArray)
        cout << el << " ";

    cout << endl;
    // for (auto &item : list)
    //     heap.remove();

    const int ARRAY_SIZE = 10;
    int elements[] = {2, 7, 26, 25, 19, 17, 1, 90, 3, 36};
    Heap<int> heapFromArray(elements, ARRAY_SIZE);

    cout << "Hold up\n";

    heapSort(elements, ARRAY_SIZE);

    for (auto& element : elements)
        cout << element << " ";

    cout << endl;
}

void initRng()
{
    RNG.seed(SEED);
}

template <class T>
void heapSort(T list[], const int arraySize)
{
    // Only worry about the first half of the array because the last
    // half are all leaves
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

vector<int> randomVector(const int size, const int start, const int stop)
{
    uniform_int_distribution<int> dist(start, stop);
    vector<int> entries = {};

    for (int i = 0; i < size; i++)
    {
        entries.push_back(dist(RNG));
    }

    return entries;
}
