#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <cassert>
#include "ListInterface.h"

template <class E>
class ArrayList : public ListInterface<E>
{
private:
    int maxSize;        // Maximum size of the list
    int listSize;       // Number of current list items
    int curr;           // Position of the current element
    E* listArray;       // Array holding list elements
public:
    ArrayList(int size=5);      // Constructor
    ~ArrayList();               // Destructor

    void clear();               // Reinitialize the list
    void insert(const E& it);   // Insert "it" at the current position
    void append(const E& it);   // Append "it"
    E remove();                 // Remove and return the current element
    void moveToStart();         // Reset position
    void moveToEnd();           // Set at end
    void moveToPos(int pos);    // Set current list position to "pos"
    void prev();                // Back up
    void next();                // Next

    int length() const;         // Return list size
    int currPos() const;        // Return current position
    const E& getValue() const;  // Return current element
    bool isAtEnd() const;       // Determine if current position at end
    bool isEmpty() const;       // Determine if list is empty
};

#include "ArrayList.cpp"

#endif // ARRAY_LIST_H
