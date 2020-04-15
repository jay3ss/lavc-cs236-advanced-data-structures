#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <class T>
class Heap
{
public:
    Heap();
    Heap(const T elements[], int arraySize);
    ~Heap();

    // remove the root from the heap and maintain the max-heap property
    T remove();

    // insert element into the heap and maintain the max-heap property
    void add(const T& element);

    // get the number of elements in the heap
    int size() const;

private:
    std::vector<T> vect;
};

template <class T>
Heap<T>::Heap() {}

template <class T>
Heap<T>::~Heap() {}

template <class T>
T Heap<T>::remove()
{

}

template <class T>
void Heap<T>::add(const T& element)
{

}

template <class T>
int Heap<T>::size() const
{
    return -1;
}


#endif // HEAP_H
