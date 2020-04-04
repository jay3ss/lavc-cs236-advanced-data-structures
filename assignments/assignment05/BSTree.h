// You are given two classes for implementing a simple binary tree of capable of
// storing number, count the number of leaves and computes the height of a
// binary tree.
//
// You can add on additional parameters or functions as you wish, but the
// program must apply the chapter objectives.
#ifndef B_S_TREE_H
#define B_S_TREE_H

#include <iostream>
#include <vector>

using namespace std;

// Node for the binary tree items
class BTreeNode
{
public:
    BTreeNode(double x, BTreeNode *leftp = nullptr, BTreeNode *rightp = nullptr)
        : value(x), left(leftp), right(rightp) {}

    bool isLeaf() const { return left == nullptr && right == nullptr; }
private:
    double value;
    BTreeNode *left, *right;
    friend class BST;
};

// Binary tree class itself
class BST
{
public:
    BST();
    ~BST();
    int height() const;                                     // return the tree height
    bool insert(const double x);                            // insert numbers into the binary tree
    void inorder(vector<double>& vect);               // appends all nodes in subtree
    int leafCounter() const;                                // count the number of leaves
    bool isEmpty() const;                                   // tests if the tree is empty
    bool remove(const double val);                          // removes data from the tree
    bool contains(const double val) const;                  // determines if an item is in the tree
    void clear();                                           // clears the tree of items
    void print() const;                                     // prints items to the terminal in order
private:
    BTreeNode *root;

    void inorder(vector<double>& tlist, BTreeNode*& tree) const;   // storing nodes in subtree
    int leafCounter(const BTreeNode* tree) const;                 // count the number of leaves
    static int height(BTreeNode* tree);                     // calculate the height of the tree

    BTreeNode* insert(BTreeNode*& tree, BTreeNode*& newNode);  // helper method to insert items into the tree
    BTreeNode* find(BTreeNode* tree, double val) const;            // helper method to find an item in the tree
    BTreeNode* remove(BTreeNode*& tree, const double val, bool& flag);    // helper method to remove an item from the tree
    BTreeNode* getmax(BTreeNode*& tree);                      // helper method to find the node with the max value in a subtree
    BTreeNode* deletemax(BTreeNode*& tree);                 // helper method to remove the node with the maximum value in a subtree
    BTreeNode* removeNode(BTreeNode*& tree);                // helper method to remove a node
    void print(const BTreeNode* tree) const;                // helper method to print a subtree in inorder
    void clear(BTreeNode* tree);                            // helper method to clear subtree
};
#endif // B_S_TREE_H
