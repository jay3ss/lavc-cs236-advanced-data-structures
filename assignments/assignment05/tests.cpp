#include <cassert>
#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
    BST bst;

    assert(bst.isEmpty());
    cout << "A new tree should be empty: PASSED\n\n";
}
