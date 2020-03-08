#include <cassert>
#include <iostream>
#include "LinkedList.h"

int main()
{
    const int LENGTH = 10;
    LinkedList<int> list;

    // The list's current position should start at 0
    std::cout << "Current position is: " << list.currPos() << "\n";
    assert(list.currPos() == 0);

    // A new list should be empty
    std::cout << "New list is empty: " << list.isEmpty() << "\n";
    assert(list.isEmpty());

    // A new list's current position should be at the end
    std::cout << "Current position is at the end: " << list.isAtEnd() << "\n";
    assert(list.isAtEnd());

    // Append 10 numbers to the list
    for (int i = 0; i < LENGTH; i++)
    {
        list.append(i * i - i);
    }

    // The list's current position should still be at 0
    assert(list.currPos() == 0);

    // Calling next should move the list's current position to 1
    list.next();
    assert(list.currPos() == 1);

    // Calling moveToEnd should move the list's current position to LENGTH
    list.moveToEnd();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == LENGTH);

    // Calling moveToStart should move the list's current position to 0
    list.moveToStart();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 0);

    // Calling moveToPos(3) should move the list's current position to 3
    list.moveToPos(3);
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 3);

    // Calling moveToPos(LENGTH) should move the list's current position LENGTH
    list.moveToPos(LENGTH);
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == LENGTH);

    // Calling moveToPos(0) should move the list's current position 0
    list.moveToPos(0);
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 0);

    // Calling prev shouldn't move the list's current position from 0
    list.prev();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 0);

    // Calling next shouldn't move the list's current position from LENGTH
    list.moveToEnd();
    list.next();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == LENGTH);

    // Traverse the list and print out its contents
    for (list.moveToStart(); list.currPos() < list.length() - 1; list.next())
    {
        std::cout << list.getValue() << ", ";
    }
    std::cout << list.getValue() << std::endl;

    // Removing an item should return the correct item
    int toRemove = 5;
    int value = toRemove * toRemove - toRemove;
    list.moveToPos(toRemove);
    int removed = list.remove();
    assert(removed == value);
    std::cout << value << " has been removed from the list\n";
    for (list.moveToStart(); list.currPos() < list.length() - 1; list.next())
    {
        std::cout << list.getValue() << ", ";
    }
    std::cout << list.getValue() << std::endl;

    return 0;
}
