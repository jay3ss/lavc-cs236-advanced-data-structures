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
    // How to insert a new item
    // 1. Create a new node
    // 2. Set curr's data to the new node's data
    // 3. Set the new node's next pointer to curr's next pointer
    // 4. Have curr point to the new node
    // 5. Update the number of nodes
    // 6. Update the tail, if necessary
    Node<E>* newNode = new Node<E>(curr->element, curr->next);
    curr->next = newNode;
    curr->element = item;

    if(tail == curr)
    {
        tail = curr->next;
    }

    count++;
}

template <class E>
void LinkedList<E>::append(const E &item)
{
    // To append, we simply need to
    // 1. Create a new node
    // 2. Store the item in the tail node
    // 3.

    Node<E> *newTail = new Node<E>;
    tail->next = newTail;
    tail->element = item;
    tail = tail->next;

    count++;
}

template <class E>
E LinkedList<E>::remove()
{
    // Assert precondition that the list isn't empty
    assert(curr != tail);

    E item = curr->element;
    Node<E> *nextNode = curr->next;
    curr->element = nextNode->element;
    curr->next = nextNode->next;

    delete nextNode;
    nextNode = nullptr;

    if (curr->next == tail)
    {
        tail = curr;
    }

    count--;

    return item;
}

template <class E>
void LinkedList<E>::moveToStart()
{
    curr = head->next;
}

template <class E>
void LinkedList<E>::moveToEnd()
{
    curr = tail;
}

template <class E>
void LinkedList<E>::prev()
{
    // If we're at the head of the list then we don't need to
    // go anywhere
    if (curr != head->next)
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
    Node<E> *temp = head->next;
    int position;

    for (position = 0; curr != temp; position++)
    {
        temp = temp->next;
    }

    return position;
}

template <class E>
void LinkedList<E>::moveToPos(int pos)
{
    if (pos == 0)
    {
        moveToStart();
    }
    else if (pos == count)
    {
        moveToEnd();
    }
    else
    {
        curr = head->next->next;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
    }
}

template <class E>
const E &LinkedList<E>::getValue() const
{
    return curr->element;
}

template <class E>
bool LinkedList<E>::isAtEnd() const
{
    return curr == tail;
}

template <class E>
bool LinkedList<E>::isEmpty() const
{
    return count == 0;
}

// Private methods
template <class E>
void LinkedList<E>::init()
{
    // Start out with a dummy Node so that we can simplify
    // insertion and removal operations later
    curr = new Node<E>;
    tail = curr;
    head = new Node<E>(tail);

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
