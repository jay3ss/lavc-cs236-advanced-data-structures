#include "BSTree.h"

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{

}

// Public methods
int BST::height() const
{
    return height(root);
}

bool BST::insert(const double val)
{
    BTreeNode *newNode = new BTreeNode(val);
    root = insert(root, newNode);
    return true;
}

void BST::inorder(vector<double>& vect)
{

}

int BST::leafCounter() const
{
    return leafCounter(root);
}

bool BST::isEmpty() const
{
    return root == nullptr;
}

bool BST::remove(const double val)
{
    bool isRemoved = false;
    root = remove(root, val, isRemoved);
    return isRemoved;
}

bool BST::contains(const double val) const
{
    return nullptr != find(root, val);
}

void BST::clear()
{

}

double BST::entry(const double val) const
{
    return -10000000;
}

// Private methods
void BST::inorder(vector<double>& tlist, BTreeNode*& tree)
{

}

int BST::leafCounter(const BTreeNode* tree) const
{
    if (tree == nullptr)
    {
        return 0;
    }

    if (tree->isLeaf())
    {
        return 1;
    }
}

int BST::height(BTreeNode* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }

    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    //return 1 + the greater of the two heights (left vs right subtrees)
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

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
    if (tree->value <= newNode->value)
    {
        tree->left = insert(tree->left, newNode);
    }
    else if (tree->value > newNode->value)
    {
        tree->right = insert(tree->right, newNode);
    }
    else
    {
        tree = newNode;
    }

    return tree;
}

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
    if (tree->value < val)
    {
        return find(tree->left, val);
    }
    else if (tree->value > val)
    {
        return find(tree->right, val);
    }
    else
    {
        return tree;
    }
}

double BST::entry(BTreeNode* tree, const double val) const
{
    return -1000000000;
}

BTreeNode* BST::remove(BTreeNode*& tree, const double val, bool& flag)
{
    if (tree == nullptr)
    {
        flag = false;
        return tree;
    }

    // remove the only node from the tree
    if (tree->value == val)
    {
        flag = true;
        delete tree;
        tree = nullptr;
        return nullptr;
    }
}

BTreeNode* BST::getmax(BTreeNode*& tree)
{
    return nullptr;
}

BTreeNode* deletemax(BTreeNode*& tree)
{
    return nullptr;
}
