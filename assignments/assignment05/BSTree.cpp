#include "BSTree.h"

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{

}

int BST::height() const
{
    return height(root);
}

int BST::height(BTreeNode* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    else
    {
        // Traverse both subtrees and then find the greater of the two
        int leftHeight = height(tree->left);
        int rightHeight = height(tree->right);
        return 1 + (leftHeight > rightHeight) ? leftHeight : rightHeight;
    }
}

bool BST::insert(double x)
{

    return false;
}

void BST::insert(BTreeNode* subTree, BTreeNode* newNode)
{

}

void BST::inorder(vector<double>& vect)
{

}

void BST::inorder(vector<double>& tlist, BTreeNode* tree)
{

}

int BST::leafCounter() const
{
    return -1;
}

int BST::leafCounter(BTreeNode* tree) const
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
    return -3.14159;
}
