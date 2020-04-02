#include "BSTree.h"

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    clear();
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

    // Traverse both subtrees and then find the greater of the two
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

bool BST::insert(const double x)
{
    BTreeNode* newNode = new BTreeNode(x);
    root = insert(root, newNode);
    return true;
}

BTreeNode* BST::insert(BTreeNode*& tree, BTreeNode*& newNode)
{
    // Using the convention that new values
    // - less than or equal to the current node's value -> left
    // - greater than the current node's value -> right
    // We know that we've hit the insertion point when tree is null
    if (tree == nullptr)
    {
        return newNode;
    }
    else if (newNode->value <= tree->value)
    {
        tree->left = insert(tree->left, newNode);
    }
    else
    {
        tree->right = insert(tree->right, newNode);
    }

    return tree;
}

void BST::inorder(vector<double>& vect)
{

}

void BST::inorder(vector<double>& tlist, BTreeNode*& tree)
{

}

int BST::leafCounter() const
{
    return leafCounter(root);
}

int BST::leafCounter(const BTreeNode* tree) const
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
    bool isRemoved = false;

    root = remove(root, val, isRemoved);

    return isRemoved;
}

BTreeNode* BST::remove(BTreeNode*& tree, const double val, bool& flag)
{
    if (tree == nullptr)
    {
        flag = false;
        return nullptr;
    }
    else if (tree->value < val)
    {
        tree->right = remove(tree->right, val, flag);
    }
    else if (tree->value > val)
    {
        tree->left = remove(tree->left, val, flag);
    }
    else
    {
        // 1. find the value, then remove it
        // 2. check the child nodes
        //    a. 0 children: set node to null
        //    b. 1 child: set node to child of node
        //    c. 2 children: set node to logical predecessor
        flag = true;
        BTreeNode *toDelete = tree;
        if (tree->left == nullptr)
        {
            // toDelete = tree;
            tree = tree->right;
        }
        else if (tree->right == nullptr)
        {
            // toDelete = tree;
            tree = tree->left;
        }
        else
        {
            toDelete = getmax(tree->left);
            toDelete->left = tree->left;
            tree->value = toDelete->value;
            tree->left = deletemax(tree->left);
        }
        delete toDelete;
        toDelete = nullptr;
    }

    return tree;
}

BTreeNode* BST::deletemax(BTreeNode*& tree)
{
    if (tree->right == nullptr)
    {
        return tree->left;
    }

    // traverse the tree until we find the maximum node
    tree->right = deletemax(tree->right);
    return tree;
}

bool BST::contains(const double val) const
{
    return find(root, val) != nullptr;
}

void BST::clear()
{

}

double BST::entry(const double val) const
{
    return entry(root, val);
}

double BST::entry(BTreeNode* tree, const double val) const
{
    // We know that the entry isn't in the tree when tree is null
    // Using the convention that new values
    // - less than to the current node's value -> left
    // - greater than the current node's value -> right
    // - otherwise, we've reached the entry
    if (tree == nullptr)
    {
        // TODO: throw an exception here
        return -3.14159;
    }
    else if (tree->value < val)
    {
        return entry(tree->left, val);
    }
    else if (tree->value > val)
    {
        return entry(tree->right, val);
    }
    else
    {
        return tree->value;
    }

}

BTreeNode* BST::find(BTreeNode* tree, double val) const
{
    // We know that the entry isn't in the tree when tree is null
    // Using the convention that new values
    // - less than to the current node's value -> left
    // - greater than the current node's value -> right
    // - otherwise, we've reached the entry
    if (tree == nullptr)
    {
        return nullptr;
    }
    else if (tree->value < val)
    {
        return find(tree->right, val);
    }
    else if (tree->value > val)
    {
        return find(tree->left, val);
    }
    else
    {
        return tree;
    }
}

BTreeNode* BST::getmax(BTreeNode*& tree)
{
    // find the node with the maximum value in a subtree
    // keep going down the right of the subtree until the
    // right child is null
    // return (tree->right == nullptr) ? tree : getmax(tree->right);
    if (tree->right == nullptr)
    {
        return tree;
    }

    return getmax(tree->right);
}
