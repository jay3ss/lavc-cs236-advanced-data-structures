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
