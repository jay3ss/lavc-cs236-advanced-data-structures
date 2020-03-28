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
        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
}

bool BST::insert(double x)
{
    BTreeNode* newNode = new BTreeNode(x);
    root = insert(root, newNode);
    return true;
}

BTreeNode* BST::insert(BTreeNode* subTree, BTreeNode* newNode)
{
    // Using the convention that new values
    // - less than or equal to the current node's value -> left
    // - greater than the current node's value -> right
    // We know that we've hit the insertion point when subTree is null
    if (subTree == nullptr)
    {
        return newNode;
    }
    else if (newNode->value <= subTree->value)
    {
        return insert(subTree->left, newNode);
    }
    else
    {
        return insert(subTree->right, newNode);
    }
}

void BST::inorder(vector<double>& vect)
{

}

void BST::inorder(vector<double>& tlist, BTreeNode* tree)
{

}

int BST::leafCounter() const
{
    return leafCounter(root);
}

int BST::leafCounter(BTreeNode* tree) const
{
    if (tree == nullptr)
    {
        return 0;
    }
    else if (tree->isLeaf())
    {
        return 1 + leafCounter(tree->left) + leafCounter(tree->right);
    }
}

bool BST::isEmpty() const
{
    return root == nullptr;
}

bool BST::remove(const double val)
{
    bool isInTree = find(root, val);

    if (isInTree)
    {
        root = remove(root, val);
    }

    return isInTree;
}

BTreeNode* BST::remove(BTreeNode* subTree, double val)
{
    if (subTree == nullptr)
    {
        return nullptr;
    }

    // 1. find the value, then remove it
    // 2. check the child nodes
    //    a. 0 children: set node to null
    //    b. 1 child: set node to child of node
    //    c. 2 children: set node to logical predecessor
    if (subTree->value < val)
    {
        subTree->left = remove(subTree->left, val);
    }
    else if (subTree->value > val)
    {
        subTree->right = remove(subTree->right, val);
    }
    else
    {
        if (subTree->isLeaf())
        {
            delete subTree;
            subTree = nullptr;
        }
        else if (subTree->left != nullptr)
        {

        }
        else if (subTree->right != nullptr)
        {
            BTreeNode* rightChild = subTree->right;

        }
        else
        {

        }
    }

    return subTree;
}

bool BST::contains(const double val) const
{
    return find(root, val);
}

void BST::clear()
{

}

double BST::entry(const double val) const
{
    return entry(root, val);
}

double BST::entry(BTreeNode* subTree, const double val) const
{
    // We know that the entry isn't in the tree when subTree is null
    // Using the convention that new values
    // - less than to the current node's value -> left
    // - greater than the current node's value -> right
    // - otherwise, we've reached the entry
    if (subTree == nullptr)
    {
        // TODO: throw an exception here
        return -3.14159;
    }
    else if (subTree->value < val)
    {
        return entry(subTree->left, val);
    }
    else if (subTree->value > val)
    {
        return entry(subTree->right, val);
    }
    else
    {
        return subTree->value;
    }

}

bool BST::find(BTreeNode* subTree, double val) const
{
    // We know that the entry isn't in the tree when subTree is null
    // Using the convention that new values
    // - less than to the current node's value -> left
    // - greater than the current node's value -> right
    // - otherwise, we've reached the entry
    if (subTree == nullptr)
    {
        return false;
    }
    else if (subTree->value < val)
    {
        return find(subTree->left, val);
    }
    else if (subTree->value > val)
    {
        return find(subTree->right, val);
    }
    else
    {
        return true;
    }
}

BTreeNode* BST::getmax(BTreeNode* subTree)
{
    // find the node with the maximum value in a subtree
    // keep going down the right of the subtree until the
    // right child is null
    return (subTree->right == nullptr) ? subTree : getmax(subTree->right);
}
