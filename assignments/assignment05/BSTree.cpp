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
    return false;
}

void BST::inorder(vector<double>& vect)
{

}

int BST::leafCounter() const
{
    return -1;
}

bool BST::isEmpty() const
{
    return root == nullptr;
}

bool BST::remove(const double val)
{
    return false;
}

bool BST::contains(const double val) const
{
    return false;
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
    return -1;
}

int BST::height(BTreeNode* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    return -1;
}

BTreeNode* BST::insert(BTreeNode*& tree, BTreeNode*& newNode)
{
    return nullptr;
}

BTreeNode* BST::find(BTreeNode* tree, double val) const
{
    return nullptr;
}

double BST::entry(BTreeNode* tree, const double val) const
{
    return -1000000000;
}

BTreeNode* BST::remove(BTreeNode*& tree, const double val, bool& flag)
{
    return nullptr;
}

BTreeNode* BST::getmax(BTreeNode*& tree)
{
    return nullptr;
}

BTreeNode* deletemax(BTreeNode*& tree)
{
    return nullptr;
}
