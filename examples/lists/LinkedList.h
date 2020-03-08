#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"

template <class E>
class LinkedList : public ListInterface<E>
{
private:
    Node<E>* head;  // Points to first element in list
    Node<E>* curr;  // Points to element before the current element
    Node<E>* tail;  // Points to last element in list

    int count;

    void init();
    void removeall();
public:
    LinkedList(int maxSize = 0);    // Default constructor
    ~LinkedList();                  // Base destructor

    // Clear contents from the list, to make it empty
    void clear();

    // Insert an element at the current location
    // item: The element to be inserted
    void insert(const E &item);

    // Append an element at the end of the list
    // item: The element to be inserted
    void append(const E &item);

    // Remove and return the current element
    // Return: The element that was removed
    E remove();

    // Set the current position to the start of the list
    void moveToStart();

    // Set the current position to the end of the list
    void moveToEnd();

    // Move the current position one step left. No change if
    // already at the beginning
    void prev();

    // Move the current position one step right. No change if
    // already at the end
    void next();

    // Return: The number of elements in the list
    int length() const;

    // Return the position of the current element
    int currPos() const;

    // Set the current position
    // pos: The position to make current
    void moveToPos(int pos);

    // Return: The current element
    const E &getValue() const;

    bool isAtEnd() const; // Determine if current position at end
    bool isEmpyt() const; // Determine if list is empty
};

#include "LinkedList.cpp"

#endif // LINKED_LIST_H
