#include <cassert>
#include "ADTStackLList.h"

int main()
{
    stack<int> intStack;
    const auto MAX_ITEMS = 10;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        intStack.push(i*i - i);
    }

    intStack.display();
    cout << endl;

    stack<int> copyStack = intStack;
    copyStack.display();

    while (!intStack.isEmpty())
    {
        int stack1Item = intStack.getTop();
        int stack2Item = copyStack.getTop();

        intStack.pop();
        copyStack.pop();

        assert(stack1Item == stack2Item);
    }
}
