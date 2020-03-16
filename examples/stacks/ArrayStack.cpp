#include "ArrayStack.h"

template<class T>
ArrayStack<T>::ArrayStack(const int maxNumItems) :
    maxSize(maxNumItems),
    numItems(0)
{
    items = new T[maxSize];
    numItems = 0;
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    delete[] items;
    items = nullptr;
}
