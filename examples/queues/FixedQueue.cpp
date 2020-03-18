#include "FixedQueue.h"

// Constructor
template <class T>
FixedQueue<T>::FixedQueue(const int maxNumEntries) :
    maxSize(maxNumEntries), rear(0)
{
    queue = new T[maxSize];
}

// Destructor
template <class T>
FixedQueue<T>::~FixedQueue()
{
    delete[] queue;
    queue = nullptr;
}

// Determines if the queue is empty
template <class T>
bool FixedQueue<T>::isEmpty() const
{
    return false;
}

// Adds a new entry to the back of the queue
template <class T>
bool FixedQueue<T>::enqueue(const T& newEntry)
{
    return false;
}

// Removes the entry at the front of the queue
template <class T>
bool FixedQueue<T>::dequeue()
{
    return false;
}

// Returns the front of the queue
template <class T>
T FixedQueue<T>::peek() const
{
    return queue[0];
}

// Determines if the queue is full
template <class T>
bool FixedQueue<T>::isFull() const
{
    return false;
}

// Removes all items from the queue
template <class T>
void FixedQueue<T>::clear()
{

}

// Returns the number of items in the queue
template <class T>
int FixedQueue<T>::length() const
{
    return -1;
}
