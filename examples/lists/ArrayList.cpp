#include "ArrayList.h"

template <class E>
ArrayList<E>::ArrayList(int size) : maxSize(size), listSize(0), curr(0)
{
    listArray = new E[maxSize];
}

template <class E>
ArrayList<E>::~ArrayList()
{
    delete[] listArray;
    listArray = nullptr;
}

template <class E>
void ArrayList<E>::clear()
{
    // Delete the list and create a new one and set the list size and current
    // position to zero
    delete[] listArray;
    listArray = new E[maxSize];
    listSize = 0;
    curr = 0;
}

template <class E>
void ArrayList<E>::insert(const E& it)
{
    // Assert the precondition that the list isn't full
    assert(listSize < maxSize);

    // Move all the elements up one space, insert the new item into the current
    // position, and then increment the list size
    for (int i = listSize; i > curr; i--)
    {
        listArray[i] = listArray[i-1];
    }
    listArray[curr] = it;
    listSize++;
}

template <class E>
void ArrayList<E>::append(const E& it)
{
    // Assert the precondition that the list isn't full
    assert(listSize < maxSize);

    listArray[listSize] = it;
    listSize++;
}

template <class E>
E ArrayList<E>::remove()
{
    // Assert precondition that the list isn't empty
    assert(listSize > 0);

    // Get the item that's being removed, move all list items down one
    // position, decrease the list size, and then return the item
    E toRemove = listArray[curr];
    for (int i = curr; i < listSize-1; i++)
    {
        listArray[i] = listArray[i+1];
    }
    listSize--;
    return toRemove;
}

template <class E>
void ArrayList<E>::moveToStart()
{
    curr = 0;
}

template <class E>
void ArrayList<E>::moveToEnd()
{
    curr = listSize - 1;
}

template <class E>
void ArrayList<E>::moveToPos(int pos)
{
    // Assert precondition that the new position must be within the
    // bounds of the list
    assert(0 <= pos && pos < listSize);
    curr = pos;
}

template <class E>
void ArrayList<E>::next()
{
    // Enforce the boundaries of the underlying array. Don't go beyond
    // the length of the array
    if (curr < listSize - 1)
    {
        curr++;
    }
}

template <class E>
void ArrayList<E>::prev()
{
    if (curr > 0)
    {
        curr--;
    }
}

template <class E>
int ArrayList<E>::length() const
{
    return listSize;
}

template <class E>
int ArrayList<E>::currPos() const
{
    return curr;
}

template <class E>
const E& ArrayList<E>::getValue() const
{
    // Assert precondition that the list isn't empty
    assert(listSize > 0);
    return listArray[curr];
}

template <class E>
bool ArrayList<E>::isAtEnd() const
{
    return curr == listSize;
}

template <class E>
bool ArrayList<E>::isEmpty() const
{
    return false;
}
