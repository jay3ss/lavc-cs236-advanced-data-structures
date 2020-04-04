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
// returns the height of the tree
int BST::height() const
{
    return height(root);
}

// inserts a number into the binary tree
bool BST::insert(const double val)
{
    BTreeNode *newNode = new BTreeNode(val);
    root = insert(root, newNode);
    return true;
}

// appends all nodes in the tree to a vector inorder
void BST::inorder(vector<double>& vect)
{
    inorder(vect, root);
}

// counts the number of leaves in the tree
int BST::leafCounter() const
{
    return leafCounter(root);
}

// tests if the tree is empty
bool BST::isEmpty() const
{
    return root == nullptr;
}

// removes a value from the tree
bool BST::remove(const double val)
{
    bool isRemoved = false;
    root = remove(root, val, isRemoved);
    return isRemoved;
}

// determines if a value is in the tree
bool BST::contains(const double val) const
{
    return nullptr != find(root, val);
}

// clears the tree of all items
void BST::clear()
{
    clear(root);
}

// prints the values in the tree to the terminal in order
void BST::print() const
{
    print(root);
}

// Private methods
// appends all nodes in a subtree to a vector inorder
void BST::inorder(vector<double>& tlist, BTreeNode*& tree) const
{
    if (tree != nullptr)
    {
        inorder(tlist, tree->left);
        tlist.push_back(tree->value);
        inorder(tlist, tree->right);
    }
}

// counts the number of leaves in a subtree
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

// calculates the height of a subtree
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

// inserts a new node into a subtree
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

// finds an value in a subtree
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

// removes a value from a subtree
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

// deletes a node from a subtree
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

// finds the node with the maximum value in a subtree
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

// removes (not delete!) the node with the maximum value in a subtree
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

// prints the contents of a subtree in inorder
void BST::print(const BTreeNode* tree) const
{
    if (tree != nullptr)
    {
        print(tree->left);
        cout << tree->value << " ";
        print(tree->right);
    }
}

// clears a subtree of all its contentes
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
