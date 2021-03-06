/** file: main.cpp
You are given two classes for implementing a simple binary tree of capable of
storing number, count the number of leaves and computes the height of a
binary tree.

You can add on additional parameters or functions as you wish, but the
program must apply the chapter objectives. */
#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
    BST bst;

    cout << "This program allows you to insert some numbers in a "
         << "binary search tree.\n"
         << "It prints out the numbers in the tree in inorder.\n"
         << "It computes and prints the number of leaves in the tree\n"
         << "and the height of the tree.\n"
         << "Enter 10 numbers:\n";

    double nums[10];

    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4]
        >> nums[5] >> nums[6] >> nums[7] >> nums[8] >> nums[9];

    for (auto num : nums)
    {
        bst.insert(num);
    }

    cout << "\nThe items in the tree inorder are:\n";
    bst.print();
    cout << "\nThe height of the tree is " << bst.height() << "\n\n"
         << "The number of leaves is " << bst.leafCounter() << endl;
}
