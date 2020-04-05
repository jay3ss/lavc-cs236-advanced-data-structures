/** file: BSTree.h
You are given two classes for implementing a simple binary tree of capable of
storing number, count the number of leaves and computes the height of a
binary tree.

You can add on additional parameters or functions as you wish, but the
program must apply the chapter objectives. */
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

    /** determines if a node is a leaf
    @return: true if node is a leaf, false otherwise */
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
    /** constructor */
    BST();

    /** destructor */
    ~BST();

    /** returns the height of the tree
    @return: the height of the tree */
    int height() const;

    /** inserts a number into the binary tree
    @return: true if insertion was successful */
    bool insert(const double x);

    /** appends all nodes in a the tree to a vector inorder
    @param: vect a vector to store the values of the nodes in the tree
    @post: vect will have the values of the tree stored in it inorder */
    void inorder(vector<double>& vect);

    /** counts the number of leaves in the tree
    @return: the number of leaves in the tree */
    int leafCounter() const;

    /** tests if the tree is empty
    @return: true if the tree is empty, false otherwise */
    bool isEmpty() const;

    /** removes a value from the tree
    @param: val the value to remove
    @return: true if the value is found and removal is successful, false
        otherwise */
    bool remove(const double val);

    /** determines if a value is in the tree
    @param: val the value to search for
    @return: true if the the value is found, false otherwise */
    bool contains(const double val) const;

    /** clears the tree of all items
    @post: the tree will be completely empty */
    void clear();

    /** prints the values in the tree to the terminal inorder
    @post: the terminal will have the values in the tree printed to it
        inorder */
    void print() const;

    /** retrieves a value from the tree
    @param: val the value to search for
    @return: returns the value from the tree if it is found, NULL otherwise */
    double retrieve(double val);
private:
    BTreeNode *root;    // pointer to the root node of the tree

    /** appends all nodes in a subtree to a vector inorder
    @param: tlist the vector to append the values of the nodes to
    @param: tree reference to the pointer of the subtree
    @post: tlist will have the values of the subtree appended to it inorder */
    void inorder(vector<double>& tlist, BTreeNode*& tree) const;

    /** counts the number of leaves in a subtree
    @param: tree pointer to the subtree
    @return: the number of leaves in the subtree */
    int leafCounter(const BTreeNode* tree) const;

    /** calculates the height of a subtree
    @param: tree pointer to the subtree
    @return: the height of the subtree */
    static int height(const BTreeNode* tree);

    /** inserts a new node into a subtree
    @param: tree the subtree to insert the new node into
    @param: newNode the node to insert into the subtree
    @return: pointer to the new node locatoin */
    BTreeNode* insert(BTreeNode*& tree, BTreeNode*& newNode);

    /** finds a value in a subtree
    @param: tree the subtree to search
    @param: val the value to insert into the subtree
    @return: pointer to the location of the node in the subtree that holds
        value */
    BTreeNode* find(BTreeNode* tree, double val) const;

    /** removes a value from a subtree
    @param: tree the subtree to remove the value from
    @param: val the value to remove
    @param: flag a flag to signal whether or not the value was found and removed
        or not
    @post: if found, the value will be removed from the subtree. the structure
        or shape of the tree may change as well
           flag will be set to true if the value is found and removed, false
           otherwise*/
    BTreeNode* remove(BTreeNode*& tree, const double val, bool& flag);

    /** finds the node with the maximum value in a subtree
    @param: tree a reference to a pointer to the subtree to search
    @return: pointer to the node with the maximum value in a subtree */
    BTreeNode* getmax(BTreeNode*& tree);

    /** removes (not delete!) the node with the maximum value in a subtree
        pointer to it
    @param: tree a reference to a pointer to the subtree to search
    @return: a pointer to the node with the maximum value in the subtree
    @post: the node with the maximum value in the subtree will be removed from
        the subtree but not deleted */
    BTreeNode* removemax(BTreeNode*& node);

    /** deletes a node from a subtree
    @param: node a reference to a pointer to the node to be deleted
    @return: pointer to the node that takes the place of the deleted node
    @post: the node will be deleted and, if possible, replaced with a new
        node */
    BTreeNode* deleteNode(BTreeNode*& tree);

    /** prints the contents of a subtree to the terminal inorder
    @param: tree pointer to the subtree to print
    @post: the terminal will have the subtree's contents printed to it
        inorder */
    void print(const BTreeNode* tree) const;

    /** clears a subtree of all its contents
    @param: tree a pointer to the subtree to clear
    @post: the subtree content's will be removed */
    void clear(BTreeNode* tree);

    /** retrieves an item from a subtree
    @param: tree the subtree to search
    @param: val the value to search for
    @param: flag flag a flag to signal whether or not the value was found and
        removed or not
    @post: flag will be true if the value is found, false otherwise
           val will hold the value if found, NULL otherwise */
    void retrieve(const BTreeNode* tree, double val, bool& flag);
};
#endif // B_S_TREE_H
