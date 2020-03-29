#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#include "BSTree.h"

using namespace std;

uint32_t SEED = time(0);
mt19937 RNG;

void initRng();
vector<double> randomVector(const int size, const int start, const int stop);

    int main()
{
    BST bst;

    assert(bst.isEmpty() && "FAILED: New tree isn't empty\n");
    cout << "A new tree should be empty: PASSED\n";

    assert(bst.height() == 0 && "FAILED: New tree height isn't 0\n");
    cout << "A new tree's height is zero: PASSED\n";

    assert(bst.leafCounter() == 0 && "FAILED: New tree should have no leaves\n");
    cout << "A new tree should have no leaves: PASSED\n";

    double entry = 137;
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
    cout << "Should be able to remove an entry: PASSED\n";

    assert(!bst.contains(entry) && "FAILED: Should be able see if the tree doesn't contain a removed item\n");
    cout << "Should be able to see if the tree contains an item: PASSED\n";

    // Add many numbers to the tree randomly
    initRng();
    const int NUM_ENTRIES = 100;
    const int START = 0;
    // create a vector of random numbers of length NUM_ENTRIES, between START and NUM_ENTRIES
    // and then add the entries into the tree (also, assert that the insertion works)
    vector<double> entries = randomVector(NUM_ENTRIES, START, NUM_ENTRIES);

    for (auto& entry : entries)
    {
        assert(bst.insert(entry) && "FAILED: Should be able to insert entry\n");
    }
    cout << "Insert many entries into the tree: PASSED\n";

    for (auto& entry : entries)
    {
        assert(bst.contains(static_cast<double>(entry)) && "FAILED: Should have found entry\n");
    }
    cout << "Should be able to find several entries: PASSED\n";

}

void initRng()
{
    RNG.seed(SEED);
}

vector<double> randomVector(const int size, const int start, const int stop)
{
    uniform_int_distribution<int> dist(start, stop);
    vector<double> entries = {};

    for (int i = 0; i < 100; i++)
    {
        entries.push_back(dist(RNG));
    }

    return entries;
}
