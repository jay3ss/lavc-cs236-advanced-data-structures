#include <cassert>
#include <iostream>
#include "ArrayStack.h"

int main()
{
    ArrayStack<int> stack;

    assert(stack.length() == 0);
    std::cout << "1.\tAn empty stack should have no items in it: PASSED\n";

    assert(stack.isEmpty());
    std::cout << "2.\tAn empty stack should be empty: PASSED\n";

    assert(!stack.isFull());
    std::cout << "3.\tAn empty stack should not be full: PASSED\n";

    return 0;
}
