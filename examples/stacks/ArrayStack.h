#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "StackInterface.h"

template <class T>
class ArrayStack : StackInterface<T>
{
public:
    ArrayStack(const int maxNumItems = 5);
    ~ArrayStack();

    // Determines if the stack is empty
    bool isEmpty() const;

    // Determines if the stack is full
    bool isFull() const;

    // Removes the top item from the stack
    bool pop();

    // Adds an item to the top of the stack
    bool push(const T& item);

    // Returns the top item from the stack without modifying the stack
    const T& top() const;

    // Returns the number of items currently in the stack
    const int length() const;

    // Returns the stack to its inital state - empty
    void clear();
private:
    int maxSize;    // maximum number of items in stack
    int topItem;    // points to top of stack
    T* items;       // array to hold items in stack

    // Copy constructor
    ArrayStack(const ArrayStack& stack);

    // Assignment operator
    void operator=(const ArrayStack& stack);
};

#include "ArrayStack.cpp"
#endif // ARRAY_STACK_H
