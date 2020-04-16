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

    // returns the maximum value in the heap
    T max() const;

    // removes the root from the heap and maintain the max-heap property
    T remove();

    // returns the number of elements in the heap
    int size() const;

private:
    std::vector<T> tree;    // to hold the heap items

    // corrects a violation of the max-heap property caused by removing the root
    void heapifyDown(int index);

    // corrects a violation of the max-heap property caused by adding an element
    void heapifyUp(int index);

    // returns true if the node is a leaf, false if not
    bool isLeaf(const int index) const;

    // returns the index of the left child of the node at the given index
    static int leftChild(const int index);

    // returns the index of the parent of the node at the given index
    static int parent(const int index);

    // returns the index of the child node with the largest value
    static int largestChild(const int index);

    // returns the index of the right child of the node at the given index
    static int rightChild(const int index);

    // swaps the contents of two items
    void swap(T& item1, T& item2);
};

template <class T>
Heap<T>::Heap() {}

template <class T>
Heap<T>::Heap(const T elements[], const int arraySize)
{

}

template <class T>
Heap<T>::~Heap() {}

template <class T>
void Heap<T>::add(const T& element)
{

}

template <class T>
T Heap<T>::remove()
{

}

template <class T>
int Heap<T>::size() const
{
    return tree.size();
}

template <class T>
T Heap<T>::max() const
{
    return tree[0];
}

// corrects a single violation of the max-heap property in subtree at its root
template <class T>
void Heap<T>::heapifyUp(const int index)
{
    int l = leftChild(index);
    int r = rightChild(index);

    // determine if the node's children are larger
    // if the calculated children indices are within the tree's bounds and
    int largest = ((l < size() && tree[l] > tree[index]) ? l : index);
    largest = ((r < size() && tree[r] > tree[largest]) ? largest = r : largest);

    // if the index of the largest isn't the current index, swap the values at
    // keep on the two indices and keep on heapifying
    if (largest != index)
    {
        swap(tree[index], tree[largest]);
        heapify(largest);
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

// returns the index of the child node with the largest value
template <class T>
int Heap<T>::largestChild(const int index)
{
    // determine if the node's children are larger
    // if the calculated children indices are within the tree's bounds and
    int largest = ((l < size() && tree[l] > tree[index]) ? l : index);
    largest = ((r < size() && tree[r] > tree[largest]) ? largest = r : largest);
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

// Exception class to indicate an empty heap
class EmptyHeap {};

#endif // HEAP_H
