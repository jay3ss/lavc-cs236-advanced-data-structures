#include "FloatingQueue.h"

// Constructor
template <class T>
FloatingQueue<T>::FloatingQueue(const int maxSize)
{
    // keep a space reserved for the position preceding the front
    queue = new T[maxSize + 1];
}

// Destructor
template <class T>
FloatingQueue<T>::~FloatingQueue()
{
    delete[] queue;
    queue = nullptr;
}

// Determines if the queue is empty
template <class T>
bool FloatingQueue<T>::isEmpty() const
{
    return false;
}

// Adds a new entry to the back of the queue
template <class T>
bool FloatingQueue<T>::enqueue(const T &newEntry)
{
    return false;
}

// Removes the entry at the front of the queue
template <class T>
bool FloatingQueue<T>::dequeue()
{
    return false;
}

// Returns the front of the queue
template <class T>
T FloatingQueue<T>::peek() const
{
    return queue[0];
}

// Determines if the queue is full
template <class T>
bool FloatingQueue<T>::isFull() const
{
    return false;
}

// Removes all items from the queue
template <class T>
void FloatingQueue<T>::clear()
{

}

// Returns the number of items in the queue
template <class T>
int FloatingQueue<T>::length() const
{
    return -1;
}
