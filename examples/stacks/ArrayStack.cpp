#include "ArrayStack.h"

// Constructor
template <class T>
ArrayStack<T>::ArrayStack(const int maxNumItems) : maxSize(maxNumItems), topItem(-1)
{
    items = new T[maxSize];
}

// Destructor
template<class T>
ArrayStack<T>::~ArrayStack()
{
    delete[] items;
    items = nullptr;
}

// Determines if the stack is empty
template <class T>
bool ArrayStack<T>::isEmpty() const
{
    return topItem == -1;
}

// Determines if the stack is full
template <class T>
bool ArrayStack<T>::isFull() const
{
    return topItem + 1 == maxSize;
}

// Removes the top item from the stack
template <class T>
bool ArrayStack<T>::pop()
{
    bool canPop = !isEmpty();

    if (canPop)
    {
        topItem--;
    }

    return canPop;
}

// Adds an item to the top of the stack
template <class T>
bool ArrayStack<T>::push(const T &item)
{
    bool canPush = !isFull();

    if (canPush)
    {
        topItem++;
        items[topItem] = item;
    }

    return canPush;
}

// Returns the top item from the stack without modifying the stack
template <class T>
const T& ArrayStack<T>::top() const
{
    return items[topItem];
}

// Returns the number of items currently in the stack
template <class T>
const int ArrayStack<T>::length() const
{
    return topItem + 1;
}

// Returns the stack to its inital state - empty
template <class T>
void ArrayStack<T>::clear()
{
    topItem = -1;
}

// Copy constructor
template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack &stack)
{

}

// Assignment operator
template <class T>
void ArrayStack<T>::operator=(const ArrayStack &stack)
{

}
