#include <cassert>
#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
    BST bst;

    assert(bst.isEmpty() && "FAILED: New tree isn't empty\n");
    cout << "A new tree should be empty: PASSED\n\n";
}
