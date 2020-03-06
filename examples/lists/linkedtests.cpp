#include <cassert>
#include <iostream>
#include "LinkedList.h"

int main()
{
    const int LENGTH = 10;
    LinkedList<int> list(LENGTH);

    // The list's current position should start at 0
    assert(list.currPos() == 0);

    // Append 10 numbers to the list
    for (int i = 0; i < LENGTH; i++)
    {
        list.append(i * i - i);
    }

    // The list's current position should stil be at 0
    assert(list.currPos() == 0);

    // Calling next should move the list's current position to 1
    list.next();
    assert(list.currPos() == 1);

    // Calling moveToEnd should move the list's current position to LENGTH -1
    list.moveToEnd();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == LENGTH - 1);

    // Calling moveToStart should move the list's current position to 0
    list.moveToStart();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 0);

    // Calling moveToPos(3) should move the list's current position to 3
    list.moveToPos(3);
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 3);

    // Calling moveToPos(LENGTH-1) should move the list's current position LENGTH - 1
    list.moveToPos(LENGTH - 1);
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == LENGTH - 1);

    // Calling moveToPos(0) should move the list's current position 0
    list.moveToPos(0);
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 0);

    // Calling prev should'nt move the list's current position from 0
    list.prev();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == 0);

    // Calling next should'nt move the list's current position from LENGTH - 1
    list.moveToEnd();
    list.next();
    std::cout << "Current position is: " << list.currPos() << std::endl;
    assert(list.currPos() == LENGTH - 1);

    // Traverse the list and print out its contents
    for (list.moveToStart(); list.currPos() < list.length() - 1; list.next())
    {
        std::cout << list.getValue() << ", ";
    }
    std::cout << list.getValue() << std::endl;

    return 0;
}
