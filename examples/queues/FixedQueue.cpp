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
    return rear == 0;
}

// Adds a new entry to the back of the queue
template <class T>
bool FixedQueue<T>::enqueue(const T& newEntry)
{
    bool canEnqueue = !isFull();

    if (canEnqueue)
    {
        queue[rear] = newEntry;
        rear++;
    }

    return canEnqueue;
}

// Removes the entry at the front of the queue
template <class T>
bool FixedQueue<T>::dequeue()
{
    bool canDequeue = !isEmpty();

    if (canDequeue)
    {
        // move every entry after the front of the queue
        // up one position
        for (int i = rear; i < 0; i--)
        {
            queue[rear - 1] = queue[rear];
        }
        rear--;
    }

    return canDequeue;
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
    return rear == maxSize;
}

// Removes all items from the queue
template <class T>
void FixedQueue<T>::clear()
{
    rear = 0;
}

// Returns the number of items in the queue
template <class T>
int FixedQueue<T>::length() const
{
    return rear;
}
