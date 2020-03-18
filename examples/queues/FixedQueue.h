#ifndef FIXED_QUEUE_H
#define FIXED_QUEUE_H

#include "QueueInterface.h"

template <class T>
class FixedQueue : QueueInterface<T>
{
public:
    // Constructor
    FixedQueue(const int maxNumEntries = 5);

    // Destructor
    ~FixedQueue();

    // Determines if the queue is empty
    bool isEmpty() const;

    // Adds a new entry to the back of the queue
    bool enqueue(const T& newEntry);

    // Removes the entry at the front of the queue
    bool dequeue();

    // Returns the front of the queue
    T peek() const;

    // Determines if the queue is full
    bool isFull() const;

    // Removes all items from the queue
    void clear();

    // Returns the number of items in the queue
    int length() const;
private:
    T* queue;       // array to store the entries
    int read;       // keep track of the rear of the queue
    int maxSize;    // maximum number of items allowable (array length)
};

#include "FixedQueue.cpp"

#endif // FIXED_QUEUE_H
