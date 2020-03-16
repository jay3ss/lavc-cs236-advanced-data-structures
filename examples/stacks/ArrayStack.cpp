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
    return top == -1;
}

// Determines if the stack is full
template <class T>
bool ArrayStack<T>::isFull() const
{
    return false;
}

// Removes the top item from the stack
template <class T>
bool ArrayStack<T>::pop()
{
    return false;
}

// Adds an item to the top of the stack
template <class T>
bool ArrayStack<T>::push()
{
    return false;
}

// Returns the top item from the stack without modifying the stack
template <class T>
const T& ArrayStack<T>::top() const
{
    T item;
    return item;
}

// Returns the number of items currently in the stack
template <class T>
const int ArrayStack<T>::length() const
{
    return -1;
}

// Returns the stack to its inital state - empty
template <class T>
void ArrayStack<T>::clear()
{

}
