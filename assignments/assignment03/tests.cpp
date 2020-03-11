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
}
