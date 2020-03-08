#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

template<class E> class ListInterface
{
private:
    void operator=(const ListInterface&) {} // Protect assignment
    ListInterface(const ListInterface &) {} // Protect copy constructor
public:
    ListInterface() {}          // Default constructor
    virtual ~ListInterface() {} // Base destructor

    // Clear contents from the list, to make it empty
    virtual void clear() = 0;

    // Insert an element at the current location
    // item: The element to be inserted
    virtual void insert(const E& item) = 0;

    // Append an element at the end of the list
    // item: The element to be inserted
    virtual void append(const E& item) = 0;

    // Remove and return the current element
    // Return: The element that was removed
    virtual E remove() = 0;

    // Set the current position to the start of the list
    virtual void moveToStart() = 0;

    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;

    // Move the current position one step left. No change if
    // already at the beginning
    virtual void prev() = 0;

    // Move the current position one step right. No change if
    // already at the end
    virtual void next() = 0;

    // Return: The number of elements in the list
    virtual int length() const = 0;

    // Return the position of the current element
    virtual int currPos() const = 0;

    // Set the current position
    // pos: The position to make current
    virtual void moveToPos(int pos) = 0;

    // Return: The current element
    virtual const E& getValue() const = 0;

    // Return: true if current position is at end of list
    virtual bool isAtEnd() const = 0;

    // Return: true if list is empty
    virtual bool isEmpty() const = 0;
};

#endif // LIST_INTERFACE_H
