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
    removeall();
    init();
}

template <class E>
void LinkedList<E>::insert(const E &item)
{

}

template <class E>
void LinkedList<E>::append(const E &item)
{
    // To append a new item to the list, we simply create a new
    // Node, add it to the end of the list, and have the tail
    // pointer point to it
    Node<E>* nodeToAppend = new Node<E>(item, nullptr);
    tail->next = nodeToAppend;
    tail = tail->next;
    count++;
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
    // If we're at the head of the list then we don't need to
    // go anywhere
    if (curr != head)
    {
        Node<E>* temp = head;

        // Traverse the list until we get to the Node before the
        // current one
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }
}

template <class E>
void LinkedList<E>::next()
{
    // If we're at the tail of the list then we don't need to
    // go anywhere
    if (curr != tail)
    {
        curr = curr->next;
    }
}

template <class E>
int LinkedList<E>::length() const
{
    return count;
}

template <class E>
int LinkedList<E>::currPos() const
{
    int position = 0;
    Node<E>* temp = head;

    while (curr != temp)
    {
        temp = temp->next;
        position++;
    }

    return position;
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
