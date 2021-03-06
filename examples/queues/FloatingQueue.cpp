#include "FloatingQueue.h"

// Constructor
template <class T>
FloatingQueue<T>::FloatingQueue(const int maxSize) :
    front(0), rear(0), count(0), MAX_SIZE(maxSize + 1)
{
    queue = new T[MAX_SIZE];
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
    return count == 0;
}

// Adds a new entry to the back of the queue
template <class T>
bool FloatingQueue<T>::enqueue(const T &newEntry)
{
    bool canEnqueue = !isFull();

    if (canEnqueue)
    {
        // Add the entry to it and increment the rear position
        // Increment the count of entries in the queue
        queue[rear] = newEntry;
        rear  = (rear + 1) % MAX_SIZE;
        count++;
    }

    return canEnqueue;
}

// Removes the entry at the front of the queue
template <class T>
bool FloatingQueue<T>::dequeue()
{
    bool canDequeue = !isEmpty();

    if (canDequeue)
    {
        front = (front + 1) % MAX_SIZE;
        count--;
    }

    return canDequeue;
}

// Returns the front of the queue
template <class T>
T FloatingQueue<T>::peek() const
{
    return queue[front];
}

// Determines if the queue is full
template <class T>
bool FloatingQueue<T>::isFull() const
{
    return count == MAX_SIZE - 1;
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
    return count;
}
