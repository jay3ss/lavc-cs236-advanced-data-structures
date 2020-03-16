#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template <class T>
class StackInterface
{
public:
    /** Constructor */
    StackInterface();

    /** Destructor */
    virtual ~StackInterface();

    /** Determines if the stack is empty
    @return true if the stack is empty, false otherwise */
    virtual bool isEmpty() const = 0;

    /** Determines if the stack is full
    @return true if the stack is full, false otherwise */
    virtual bool isFull() const = 0;

    /** Removes the top item from the stack
    @pre the stack is not empty
    @post the top item will be removed from the stack
    @return true if the item has been successfully removed, false otherwise */
    virtual bool pop() = 0;

    /** Adds an item to the top of the stack
    @pre the stack is not full
    @post the item will be added to the top of the stack
    @param item the item to be added
    @return true if the item has been successfully added, false otherwise */
    virtual bool push(const T& item) = 0;

    /** Returns the top item from the stack without modifying the stack
    @pre the stack is not empty
    @return a copy of the item at the top of the stack */
    virtual const T& top() const = 0;

private:
    // Protect the copy constructor and assignment operator
    /** Copy constructor */
    StackInterface(const StackInterface& stack) {}

    /** Assignment operator */
    void operator =(const StackInterface& stack) {}
};

#endif // STACK_INTERFACE_H
