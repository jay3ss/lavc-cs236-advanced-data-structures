#include "LinkedStack.h"

template <class T>
LinkedStack<T>::LinkedStack(const int maxNumItems) : topPtr(nullptr)
{
    numItems = 0;
}

template <class T>
LinkedStack<T>::~LinkedStack()
{

}

// Determines if the stack is empty
template <class T>
bool LinkedStack<T>::isEmpty() const
{
    return topPtr == nullptr;
}

// Determines if the stack is full
template <class T>
bool LinkedStack<T>::isFull() const
{
    return false;
}

// Removes the top item from the stack
template <class T>
bool LinkedStack<T>::pop()
{
    bool canPop = !isEmpty();

    if (canPop)
    {
        Node<T> *toDelete = topPtr;
        topPtr = topPtr->next();

        delete toDelete;
        toDelete = nullptr;

        numItems--;
    }

    return canPop;
}

// Adds an item to the top of the stack
template <class T>
bool LinkedStack<T>::push(const T& item)
{
    Node<T>* newNodePtr = new Node<T>(item);
    if (isEmpty())
    {
        topPtr = newNodePtr;
    }
    else
    {
        newNodePtr->next(topPtr);
        topPtr = newNodePtr;
    }

    numItems++;
    return true;
}

// Returns the top item from the stack without modifying the stack
template <class T>
const T& LinkedStack<T>::top() const
{
    return topPtr->data();
}

// Returns the number of items currently in the stack
template <class T>
const int LinkedStack<T>::length() const
{
    return numItems;
}

// Returns the stack to its initial state - empty
template <class T>
void LinkedStack<T>::clear()
{

}
