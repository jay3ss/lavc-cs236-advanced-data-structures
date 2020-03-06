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
