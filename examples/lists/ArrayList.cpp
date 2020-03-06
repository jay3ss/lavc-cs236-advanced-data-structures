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
