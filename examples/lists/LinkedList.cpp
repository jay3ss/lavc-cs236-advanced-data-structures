#include "LinkedList.h"

template <class E>
LinkedList<E>::LinkedList(int maxSize)
{
    // Ignore the maxSize parameter. It's there only to keep the
    // API the same as the ArrayList class
    init();
}

template <class E>
LinkedList<E>::~LinkedList()
{
    removeall();
}

template <class E>
void LinkedList<E>::clear()
{

}

template <class E>
void LinkedList<E>::insert(const E &item)
{

}

template <class E>
void LinkedList<E>::append(const E &item)
{

}

template <class E>
E LinkedList<E>::remove()
{

}

template <class E>
void LinkedList<E>::moveToStart()
{

}

template <class E>
void LinkedList<E>::moveToEnd()
{

}

template <class E>
void LinkedList<E>::prev()
{

}

template <class E>
void LinkedList<E>::next()
{

}

template <class E>
int LinkedList<E>::length() const
{

}

template <class E>
int LinkedList<E>::currPos() const
{

}

template <class E>
void LinkedList<E>::moveToPos(int pos)
{

}

template <class E>
const E &LinkedList<E>::getValue() const
{

}



// Private methods
template <class E>
void LinkedList<E>::init()
{
    // Start out with a dummy Node so that we can simplify
    // insertion and removal operations later
    curr = new Node<E>;
    tail = curr;
    head = curr;

    count = 0;
}

template <class E>
void LinkedList<E>::removeall()
{
    // Traverse the list and delete each Node
    while (head != nullptr)
    {
        curr = head;
        head = head->next;
        delete curr;
        curr = nullptr;
    }
}
