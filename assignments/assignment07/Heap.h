/** @file Heap.h
CS 236
Joshua Saunders
Assignment 7 - Heap sort
Removing the root in a heap – after the root is removed, the tree must be
rebuilt to maintain the heap property.

Adding a new node – to add a new node to the heap, first add it to the end of
the heap and then rebuild the tree.

To test the header file, write the heapSort function and use the given main
program */
#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <class T>
class Heap
{
public:
    /** Constructor */
    Heap();

    /** Constructor */
    Heap(const T elements[], const int arraySize);

    /** Destructor */
    ~Heap();

    /** inserts element into the heap and maintain the max-heap property
     * @param element reference to the element to add to the heap
     * @post the element will be added to the heap with the max-heap property
     *      satisfied */
    void add(const T& element);

    /** corrects a violation of the max-heap property of the given subheap
     * @pre each of the children of the given subheap follow the max-heap
     *      property
     * @param subHeap a reference to the subheap to correct
     * @param index the index of the root of the given subheap
     * @post the subheap will have the max-heap property */
    void heapifyDown(std::vector<T>& subHeap, const int index);

    /** corrects a violation of the max-heap property of the given subheap
     * @pre each of the children of the given subheap follow the max-heap
     *      property
     * @param subHeap a reference to the subheap to correct
     * @param index the index of the root of the given subheap
     * @param heapSize the size of the given subheap
     * @post the subheap will have the max-heap property */
    static void heapifyDown(T subHeap[], const int index, const int heapSize);

    /** returns the maximum value in the heap, if the heap is empty then an
     *      EmptyHeap exception is thrown
     * @pre the heap is not empty
     * @returns the maximum value in the heap */
    T max() const;

    /** removes the root from the heap and maintain the max-heap property, if
     *      the heap is empty then an EmptyHeap exception is thrown
     * @pre the heap is not empty
     * @returns the maximum value in the heap
     * @post the maximum value of the heap will be removed */
    T remove();

    /** returns the number of elements in the heap
     * @returns the number of elements in the heap */
    int size() const;

    /** Exception class to indicate an empty heap */
    class EmptyHeap {};
private:
    std::vector<T> heap;    // to hold the heap elements

    /** corrects a violation of the max-heap property caused by adding an
     *      element
     * @pre the subheap rooted at the index is not empty
     * @param index the index of the root of the subheap
     * @post the subheap rooted at the index will have the max-heap property */
    void heapifyUp(const int index);

    /** returns true if the node is a leaf, false if not
     * @param index the index of the node
     * @returns true if the node is a leaf, false if not */
    bool isLeaf(const int index) const;

    /** returns true if the node is a leaf, false if not
     * @param index the index of the node
     * @param heapSize the size of the array/heap
     * @returns true if the node is a leaf, false if not */
    static bool isLeaf(const int index, const int heapSize);

    /** returns the index of the left child of the node at the given index
     * @param index the index of the node
     * @returns the index of the left child of the node if there is a left
     *      child, returns the index if there isn't a left node */
    static int leftChild(const int index);

    /** returns the index of the parent of the node at the given index
     * @param index the index of the node
     * @returns the index of the parent of the node if the node is not the
     *      root, if the node is the root then the root index is returned */
    static int parent(const int index);

    /** returns the index of the child node with the largest value
     * @param index the index of the node
     * @returns the index of the larger of the children nodes. if neither child
     *      is larger than the given node, or if the node is a leaf, then the
     *      node's index is returned */
    int largestChild(const int index);

    /** returns the index of the child node with the largest value
     * @param subHeap the subheap
     * @param index the index of the node
     * @param arraySize the size of the array/subheap
     * @returns the index of the larger of the children nodes. if neither child
     *      is larger than the given node, or if the node is a leaf, then the
     *      node's index is returned */
    static int largestChild(T subHeap[], const int index, const int arraySize);

    /** returns the index of the right child of the node at the given index
     * @param index the index of the node
     * @returns the index of the right child of the node if there is a right
     *      child, returns the index if there isn't a right node */
    static int rightChild(const int index);

    /** swaps the contents of two given items
     * @param item1 the first item
     * @param item2 the second item
     * @post the contents of the two variables will be swapped */
    static void swap(T& item1, T& item2);
};

// Implementation

// Constructor
template <class T>
Heap<T>::Heap() {}

// Constructor
template <class T>
Heap<T>::Heap(const T elements[], const int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        add(elements[i]);
}

// Destructor
template <class T>
Heap<T>::~Heap() {}

// inserts element into the heap and maintain the max-heap property
template <class T>
void Heap<T>::add(const T& element)
{
    heap.push_back(element);
    heapifyUp(size() - 1);
}

// corrects a violation of the max-heap property of the given subheap
template <class T>
void Heap<T>::heapifyDown(std::vector<T>& subHeap, const int index)
{
    // find the largest child and swap if necessary
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

// corrects a violation of the max-heap property of the given subheap
template <class T>
void Heap<T>::heapifyDown(T subHeap[], const int index, const int heapSize)
{
    // find the largest child and swap if necessary
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

// returns the maximum value in the heap, if the heap is empty then an
// EmptyHeap exception is thrown
template <class T>
T Heap<T>::max() const
{
    if (size() == 0)
    {
        throw EmptyHeap();
    }
    return heap[0];
}

// removes the root from the heap and maintain the max-heap property, if
// the heap is empty then an EmptyHeap exception is thrown
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

// returns the number of elements in the heap
template <class T>
int Heap<T>::size() const
{
    return heap.size();
}

// corrects a violation of the max-heap property caused by adding an element
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

    // if we're not at the root node, then keep heapifying up
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

// returns the index of the child node with the largest value
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

// swaps the contents of two given items
template <class T>
void Heap<T>::swap(T& item1, T& item2)
{
    T temporary = item1;
    item1 = item2;
    item2 = temporary;
}

#endif // HEAP_H
