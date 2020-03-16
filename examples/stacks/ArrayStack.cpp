#include "ArrayStack.h"

template<class T>
ArrayStack<T>::ArrayStack(const int maxNumItems) : maxSize(maxNumItems), top(-1)
{
    items = new T[maxSize];
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    delete[] items;
    items = nullptr;
}
