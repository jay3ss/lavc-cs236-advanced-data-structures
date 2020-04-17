#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <class T>
class Heap
{
public:
    Heap();
    Heap(const T elements[], const int arraySize);
    ~Heap();

    // inserts element into the heap and maintain the max-heap property
    void add(const T& element);

    // corrects a violation of the max-heap property caused by removing the root
    void heapifyDown(std::vector<T>& subHeap, const int index);

    static void heapifyDown(T subHeap[], const int index, const int heapSize);

    // returns the maximum value in the heap
    T max() const;

    // removes the root from the heap and maintain the max-heap property
    T remove();

    // returns the number of elements in the heap
    int size() const;

    // Exception class to indicate an empty heap
    class EmptyHeap {};
private:
    std::vector<T> heap;    // to hold the heap items

    // corrects a violation of the max-heap property caused by adding an element
    void heapifyUp(int index);

    // returns true if the node is a leaf, false if not
    bool isLeaf(const int index) const;

    static bool isLeaf(const int index, const int heapSize);

    // returns the index of the left child of the node at the given index
    static int leftChild(const int index);

    // returns the index of the parent of the node at the given index
    static int parent(const int index);

    // returns the index of the child node with the largest value
    int largestChild(const int index);

    static int largestChild(T subHeap[], const int index, const int arraySize);

    // returns the index of the right child of the node at the given index
    static int rightChild(const int index);

    // swaps the contents of two items
    static void swap(T& item1, T& item2);
};

template <class T>
Heap<T>::Heap() {}

template <class T>
Heap<T>::Heap(const T elements[], const int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        add(elements[i]);
}

template <class T>
Heap<T>::~Heap() {}

template <class T>
void Heap<T>::add(const T& element)
{
    heap.push_back(element);
    heapifyUp(size() - 1);
}

template <class T>
void Heap<T>::heapifyDown(std::vector<T>& subHeap, const int index)
{
    int largest = largestChild(index);

    if (subHeap[index] < subHeap[largest])
    {
        swap(subHeap[index], subHeap[largest]);
    }

    // don't need to heapify if we've reached a leaf or neither child
    // is larger than the current node
    if (!isLeaf(largest) && largest != index)
    {
        heapifyDown(subHeap, largest);
    }
}

// static version
template <class T>
void Heap<T>::heapifyDown(T subHeap[], const int index, const int heapSize)
{
    int largest = largestChild(subHeap, index, heapSize);

    if (subHeap[index] < subHeap[largest])
    {
        swap(subHeap[index], subHeap[largest]);
    }

    // don't need to heapify if we've reached a leaf or neither child
    // is larger than the current node
    if (!isLeaf(largest, heapSize) && largest != index)
    {
        heapifyDown(subHeap, largest, heapSize);
    }
}

template <class T>
T Heap<T>::remove()
{
    if (size() == 0)
    {
        throw EmptyHeap();
    }
    // swap the first and last elements
    T first = heap[0];
    T last = heap.back();
    heap[0] = last;

    // remove the last element
    heap.pop_back();

    // heapify down the heap
    heapifyDown(heap, 0);

    return first;
}

template <class T>
int Heap<T>::size() const
{
    return heap.size();
}

template <class T>
T Heap<T>::max() const
{
    if (size() == 0)
    {
        throw EmptyHeap();
    }
    return heap[0];
}

// corrects a single violation of the max-heap property in subtree at its root
template <class T>
void Heap<T>::heapifyUp(const int index)
{
    int parentIndex = parent(index);

    // if the index of the largest isn't the current index, swap the values at
    // keep on the two indices and keep on heapifying
    if (heap[parentIndex] < heap[index])
    {
        swap(heap[index], heap[parentIndex]);
    }

    if (parentIndex != 0)
    {
        heapifyUp(parentIndex);
    }
}

// returns true if the node is a leaf, false if not
template <class T>
bool Heap<T>::isLeaf(const int index) const
{
    // A node is a leaf if the calculated index of its left child is greater
    // than the size of the heap
    return (leftChild(index) > size());
}

template <class T>
bool Heap<T>::isLeaf(const int index, const int heapSize)
{
    // A node is a leaf if the calculated index of its left child is greater
    // than the size of the heap
    return (leftChild(index) > heapSize);
}

// returns the index of the child node with the largest value
template <class T>
int Heap<T>::largestChild(const int index)
{
    int left = leftChild(index);
    int right = rightChild(index);
    // determine which the node's children are larger. if neither is larger than
    // the current index, then the current index is returned
    int largest = ((left < size() && heap[left] > heap[index]) ? left : index);
    largest = ((right < size() && heap[right] > heap[largest]) ? largest = right : largest);
    return largest;
}

template <class T>
int Heap<T>::largestChild(T subHeap[], const int index, const int heapSize)
{
    int left = leftChild(index);
    int right = rightChild(index);
    // determine which the node's children are larger. if neither is larger than
    // the current index, then the current index is returned
    int largest = ((left < heapSize && subHeap[left] > subHeap[index]) ? left : index);
    largest = ((right < heapSize && subHeap[right] > subHeap[largest]) ? largest = right : largest);
    return largest;
}

// returns the index of the left child of the node at the given index
template <class T>
int Heap<T>::leftChild(const int index)
{
    return (2 * index) + 1;
}

// returns the index of the parent of the node at the given index
template <class T>
int Heap<T>::parent(const int index)
{
    return (index - 1) / 2;
}

// returns the index of the right child of the node at the given index
template <class T>
int Heap<T>::rightChild(const int index)
{
    return (2 * index) + 2;
}

// swap two items
template <class T>
void Heap<T>::swap(T& item1, T& item2)
{
    T temporary = item1;
    item1 = item2;
    item2 = temporary;
}

#endif // HEAP_H
