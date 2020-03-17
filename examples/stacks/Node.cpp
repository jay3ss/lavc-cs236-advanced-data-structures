#include "Node.h"

template <class T>
Node<T>::Node() : next_(nullptr) {}

template <class T>
Node<T>::Node(T newData, Node* nextPtr) : data_(newData), next_(nextPtr) {}

template <class T>
const T& Node<T>::data() const
{
    return data_;
}

template <class T>
void Node<T>::data(const T& newData)
{
    data_ = newData;
}

template <class T>
const Node<T>* Node<T>::next() const
{
    return next_;
}

template <class T>
void Node<T>::next(const Node<T>* newNextPtr)
{
    next_ = newNextPtr;
}
