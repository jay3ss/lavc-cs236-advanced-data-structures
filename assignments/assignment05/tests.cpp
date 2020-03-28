#include <cassert>
#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
    BST bst;

    assert(bst.isEmpty() && "FAILED: New tree isn't empty\n");
    cout << "A new tree should be empty: PASSED\n";

    assert(bst.height() == 0 && "FAILED: New tree height isn't 0\n");
    cout << "A new tree's height is zero: PASSED\n";

    assert(bst.leafCounter() == 0 && "FAILED: New tree should have no leaves\n");
    cout << "A new tree should have no leaves: PASSED\n";

    double entry = 1.37;
    assert(bst.insert(entry) && "FAILED: Should be able to add an entry\n");
    cout << "Should be able to add a new entry to the empty tree: PASSED\n";

    assert(bst.entry(entry) == entry && "FAILED: Should be able to get the item\n");
    cout << "Should be able to get an item from the tree: PASSED\n";

    assert(bst.contains(entry) && "FAILED: Should be able see if the tree contains an added item\n");
    cout << "Should be able to see if the tree contains an added item: PASSED\n";

    assert(bst.height() == 1 && "FAILED: The height of a tree with one entry should be 1\n");
    cout << "The height of a tree with one entry should be one: PASSED\n";

    assert(bst.leafCounter() == 1 && "FAILED: A tree with one entry should have one leaf\n");
    cout << "A tree with one entry should have one leaf: PASSED\n";

    assert(bst.remove(entry) && "FAILED: Should be able to remove an entry\n");
    cout << " Should be able to remove an entry: PASSED\n";

    assert(bst.contains(entry) && "FAILED: Should be able see if the tree doesn't contain a removed item\n");
    cout << "Should be able to see if the tree contains an item: PASSED\n";
}
