#ifndef FLOATING_QUEUE_H
#define FLOATING_QUEUE_H

#include "QueueInterface.h"

template <class T>
class FloatingQueue : QueueInterface<T>
{
public:
    // Constructor
    FloatingQueue(const int maxNumEntries = 5);

    // Destructor
    ~FloatingQueue();

    // Determines if the queue is empty
    bool isEmpty() const;

    // Adds a new entry to the back of the queue
    bool enqueue(const T &newEntry);

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
    T *queue;   // array to store the entries
    int front;  // keep track of the front of the queue
    int rear;   // keep track of the rear of the queue
    int count;  // number of items currently in the queue
};

#include "FloatingQueue.cpp"

#endif // FLOATING_QUEUE_H
