#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

template <class T>
class QueueInterface
{
public:
    // Constructor
    QueueInterface() {}

    // Destructor
    virtual ~QueueInterface() {}

    /** Determines if the queue is empty
    @return true if the queue is empty, false otherwise */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the back of the queue
    @post if the operation was successful, newEntry will be at the back of the
    queue
    @param newEntry the object to be added as a new entry
    @return true if the addition was successful, false otherwise */
    virtual bool enqueue(const T& newEntry) = 0;

    /** Removes the entry at the front of the queue
    @pre the queue is not empty
    @post the front entry will be removed if the operation is successful
    @return true if the removal was successful, false otherwise */
    virtual bool dequeue() = 0;

    /** Returns the front of the queue
    @pre the queue is not empty
    @return the front of the queue */
    virtual T peek() const = 0;
private:
    // Copy constructor
    QueueInterface(const QueueInterface&);

    // Assignment operator
    void operator =(const QueueInterface&);
};

#endif // QUEUE_INTERFACE_H
