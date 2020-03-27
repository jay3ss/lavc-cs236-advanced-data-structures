// You are given two classes for implementing a simple binary tree of capable of
// storing number, count the number of leaves and computes the height of a
// binary tree.
//
// You can add on additional parameters or functions as you wish, but the
// program must apply the chapter objectives.
#ifndef B_S_TREE_H
#define B_S_TREE_H

#include <vector>
using namespace std;

// Node for the binary tree items
class BTreeNode
{
public:
    BTreeNode(double x, BTreeNode *leftp = nullptr, BTreeNode *rightp = nullptr)
        : value(x), left(leftp), right(rightp) {}
private:
    double value;
    BTreeNode *left, *right;
    friend class BST;
};

// Binary tree class itself
class BST
{
public:
    int height() const;                                     // return the tree height
    void insert(double x);                                  // insert numbers into the binary tree
    void inorder(vector<double>& vect);                     // appends all nodes in subtree
    int leafCounter() const;                                // count the number of leaves
    BST();
    ~BST();
private:
    BTreeNode *root;

    void inorder(vector<double>& tlist, BTreeNode* tree);   // storing nodes in subtree
    int leafCounter(BTreeNode* tree) const;                 // count the number of leaves
    static int height(BTreeNode* tree);                     // calculate the height of the tree
};
#endif // B_S_TREE_H
