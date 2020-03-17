#include <cassert>
#include <iostream>
#include "ArrayStack.h"

int main()
{
    ArrayStack<int> stack;

    assert(stack.length() == 0);
    std::cout << "An empty stack should have no items in it: PASSED\n\n";

    assert(stack.isEmpty());
    std::cout << "An empty stack should be empty: PASSED\n\n";

    return 0;
}
