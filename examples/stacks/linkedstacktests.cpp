#include <cassert>
#include <iostream>
#include "LinkedStack.h"

int main()
{
    LinkedStack<int> stack;

    // Testing an empty stack
    assert(stack.length() == 0);
    std::cout << "1.\tAn empty stack should have no items in it: PASSED\n";

    assert(stack.isEmpty());
    std::cout << "2.\tAn empty stack should be empty: PASSED\n";

    assert(!stack.isFull());
    std::cout << "3.\tAn empty stack should not be full: PASSED\n";

    assert(!stack.pop());
    std::cout << "4.\tA client should not be able to pop from an empty stack: PASSED\n";

    // Pushing to the empty stack
    int item = 137;
    assert(stack.push(item));
    std::cout << "5.\tPushing an item onto the empty stack should succeed: PASSED\n";

    assert(stack.length() == 1);
    std::cout << "6.\tPushing an item should increase stack's length by 1: PASSED\n";

    assert(stack.top() == item);
    std::cout << "7.\tThe top item should be the most recently added item: PASSED\n";

    assert(!stack.isEmpty());
    std::cout << "8.\tA non-empty stack should not be empty: PASSED\n";

    assert(!stack.isFull());
    std::cout << "9.\tA non-full stack should not be full: PASSED\n";

    // Popping from the stack
    assert(stack.pop());
    std::cout << "10.\tPopping the top item should return true: PASSED\n";

    assert(stack.length() == 0);
    std::cout << "11.\tPopping an item should decrease stack's length by 1: PASSED\n";

    // Filling the stack
    const int numItems = 100;
    for (int i = 0; i < numItems; i++)
    {
        assert(stack.push(i * i - i));
    }

    assert(!stack.isFull());
    std::cout << "12.\tThe stack should not be full: PASSED\n";

    assert(!stack.isEmpty());
    std::cout << "13.\tA full stack should not be empty: PASSED\n";

    // Clearing the stack
    stack.clear();
    assert(stack.isEmpty());
    std::cout << "14.\tClearing the stack should make the stack empty: PASSED\n";

    return 0;
}
