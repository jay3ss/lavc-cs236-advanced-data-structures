template <class E>
ArrayList<E>::ArrayList(int size) : maxSize(size), listSize(0)
{
    listArray = new E[maxSize];
}
