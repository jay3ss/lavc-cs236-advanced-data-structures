#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "Node.h"
#include "StackInterface.h"

template <class T>
class LinkedStack : StackInterface<T>
{
public:
    LinkedStack(const int maxNumItems = 5);
    ~LinkedStack();

    // Determines if the stack is empty
    bool isEmpty() const;

    // Determines if the stack is full
    bool isFull() const;

    // Removes the top item from the stack
    bool pop();

    // Adds an item to the top of the stack
    bool push(const T &item);

    // Returns the top item from the stack without modifying the stack
    const T &top() const;

    // Returns the number of items currently in the stack
    const int length() const;

    // Returns the stack to its inital state - empty
    void clear();

private:
    Node<T>* topPtr;
    int numItems;

    // Copy constructor
    LinkedStack(const LinkedStack &stack);

    // Assignment operator
    void operator =(const LinkedStack &stack);
};

#include "LinkedStack.cpp"
#endif // LINKED_STACK_H
