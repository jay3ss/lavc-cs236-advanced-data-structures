#ifndef HEAP_H
#define HEAP_H

#include <vector>

enum class Heapify { MAX, MIN };

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

    // produces a max-heap from an unordered array
    void buildHeap(const T elements[], const int arraySize);

    // corrects a single violation of the max-heap property in subtree at its root
    void heapify(std::vector<T>& subtree, const int index);

    // returns true if the node is a leaf, false if not
    bool isLeaf(const int index) const;

    // returns the index of the left child of the node at the given index
    static int left(const int index);

    // returns the index of the parent of the node at the given index
    static int parent(const int index);

    // returns the index of the right child of the node at the given index
    static int right(const int index);
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
    // put the element in the leaf that's furthest to the right (end of the
    // vector) and then ensure that it doesn't violate the max-heap property
    tree.push_back(element);
    heapify(tree, 0);
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

#endif // HEAP_H
