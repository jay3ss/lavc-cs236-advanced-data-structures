#include "ArrayStack.h"

// Constructor
template<class T>
ArrayStack<T>::ArrayStack(const int maxNumItems) : maxSize(maxNumItems), top(-1)
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
