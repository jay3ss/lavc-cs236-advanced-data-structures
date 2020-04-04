/** file: BSTree.cpp
You are given two classes for implementing a simple binary tree of capable of
storing number, count the number of leaves and computes the height of a
binary tree.

You can add on additional parameters or functions as you wish, but the
program must apply the chapter objectives. */
#include "BSTree.h"

// Constructor
BST::BST()
{
    root = nullptr;
}

// Destructor
BST::~BST()
{
    clear();
}

// Public methods
// return the tree height
int BST::height() const
{
    return height(root);
}

// insert numbers into the binary tree
bool BST::insert(const double val)
{
    BTreeNode *newNode = new BTreeNode(val);
    root = insert(root, newNode);
    return true;
}

// appends all nodes in subtree inorder
void BST::inorder(vector<double>& vect)
{
    inorder(vect, root);
}

// count the number of leaves
int BST::leafCounter() const
{
    return leafCounter(root);
}

// tests if the tree is empty
bool BST::isEmpty() const
{
    return root == nullptr;
}

// removes data from the tree
bool BST::remove(const double val)
{
    bool isRemoved = false;
    root = remove(root, val, isRemoved);
    return isRemoved;
}

// determines if an item is in the tree
bool BST::contains(const double val) const
{
    return nullptr != find(root, val);
}

// clears the tree of items
void BST::clear()
{
    clear(root);
}

// prints items to the terminal in order
void BST::print() const
{
    print(root);
}

// Private methods
// helper method to store nodes in subtree
void BST::inorder(vector<double>& tlist, BTreeNode*& tree) const
{
    if (tree != nullptr)
    {
        inorder(tlist, tree->left);
        tlist.push_back(tree->value);
        inorder(tlist, tree->right);
    }
}

// helper method to count the number of leaves
int BST::leafCounter(const BTreeNode* tree) const
{
    if (tree == nullptr)
    {
        return 0;
    }

    return (tree->isLeaf() ?
        1 :
        leafCounter(tree->left) + leafCounter(tree->right));
}

// helper method to calculate the height of the tree
int BST::height(const BTreeNode* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }

    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    // return 1 + the greater of the two heights (left vs right subtrees)
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

// helper method to insert items into the tree
BTreeNode* BST::insert(BTreeNode*& tree, BTreeNode*& newNode)
{
    if (tree == nullptr)
    {
        return newNode;
    }

    // uses the convention that values less than or equal to go
    // the left subtree, values greater than go to the right
    // three cases
    // 1. go to the left subtree
    // 2. go to the right subtree
    // 3. we found the insertion point
    if (tree->value >= newNode->value)
    {
        tree->left = insert(tree->left, newNode);
    }
    else if (tree->value < newNode->value)
    {
        tree->right = insert(tree->right, newNode);
    }
    else
    {
        tree = newNode;
    }

    return tree;
}

// helper method to find an item in the tree
BTreeNode* BST::find(BTreeNode* tree, double val) const
{
    // didn't find the value
    if (tree == nullptr)
    {
        return nullptr;
    }

    // three cases
    // 1. go to the left subtree
    // 2. go to the right subtree
    // 3. we found the value, return the pointer to it
    if (tree->value > val)
    {
        return find(tree->left, val);
    }
    else if (tree->value < val)
    {
        return find(tree->right, val);
    }
    else
    {
        return tree;
    }
}

// helper method to remove an item from the tree
BTreeNode* BST::remove(BTreeNode*& tree, const double val, bool& flag)
{
    if (tree == nullptr)
    {
        flag = false;
        return tree;
    }

    // 3 cases of where the value is
    // 1. the value is in the left subtree
    // 2. the value is in the right subtree
    // 3. we found the value
    if (tree->value > val) // 1. go left
    {
        tree->left = remove(tree->left, val, flag);
    }
    else if (tree->value < val) // 2. go right
    {
        tree->right = remove(tree->right, val, flag);
    }
    else // 3. found it
    {
        flag = true;
        tree = deleteNode(tree);
    }

    return tree;
}

// helper method to remove a node
BTreeNode* BST::deleteNode(BTreeNode*& node)
{
    // 3 cases for removing the value from the node
    // 1. node is a leaf
    // 2. node has one child
    // 3. node has two children
    BTreeNode *toDelete = node;
    if (node->left == nullptr) // 1. node is a leaf or 2. has a right child
    {
        node = node->right; // move the right subtree "up" one position
    }
    else if (node->right == nullptr) // 2. has a left child
    {
        node = node->left; // move the left subtree "up" one position
    }
    else // 3. node has two children
    {
        // 1. find the logical predecessor (the maximum value in the
        //    left subtree)
        // 2. replace the current node's value with the logical
        //    predecessor's
        // 3. delete the logical predecessor
        toDelete = getmax(node->left); // logical predecessor
        node->value = toDelete->value;
        node->left = removemax(node->left);
    }
    delete toDelete;
    toDelete = nullptr;

    return node;
}

// helper method to find the node with the max value in a subtree
BTreeNode* BST::getmax(BTreeNode*& tree)
{
    // continue traversing the right subtree until the
    // maximum value is found (can't continue)
    if (tree->right == nullptr)
    {
        return tree;
    }
    else
    {
        return getmax(tree->right);
    }
}

// helper method to remove the node with the maximum value in a subtree
BTreeNode* BST::removemax(BTreeNode*& tree)
{
    // 2 cases
    // 1. found the max
    // 2. haven't found it
    if (tree->right == nullptr)
    {
        return tree->left;
    }
    else
    {
        tree->right = removemax(tree->right);
        return tree;
    }
}

// helper method to print a subtree in inorder
void BST::print(const BTreeNode* tree) const
{
    if (tree != nullptr)
    {
        print(tree->left);
        cout << tree->value << " ";
        print(tree->right);
    }
}

// helper method to clear subtree
void BST::clear(BTreeNode* tree)
{
    if (tree != nullptr)
    {
        if (tree->left)
        {
            clear(tree->left);
        }
        if (tree->right)
        {
            clear(tree->right);
        }

        delete tree;
        tree = nullptr;
    }
}
