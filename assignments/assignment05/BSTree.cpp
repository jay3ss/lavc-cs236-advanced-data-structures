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
        tree = removeNode(tree);
    }

    return tree;
}

BTreeNode* BST::removeNode(BTreeNode*& tree)
{
    // 3 cases for removing the value from the node
    // 1. node is a leaf
    // 2. node has one child
    // 3. node has two children
    BTreeNode *toDelete = tree;
    if (tree->left == nullptr) // 1. node is a leaf or 2. has a right child
    {
        tree = tree->right; // move the right subtree "up" one position
    }
    else if (tree->right == nullptr) // 2. has a left child
    {
        tree = tree->left; // move the left subtree "up" one position
    }
    else // 3. node has two children
    {
        // 1. find the logical predecessor (the maximum value in the
        //    left subtree)
        // 2. replace the current node's value with the logical
        //    predecessor's
        // 3. delete the logical predecessor
        toDelete = getmax(tree->left); // logical predecessor
        tree->value = toDelete->value;
        tree->left = deletemax(tree->left);
    }
    delete toDelete;
    toDelete = nullptr;

    return tree;
}

BTreeNode* BST::getmax(BTreeNode*& tree)
{
    // continue traversing the right subtree until the
    // maxium value is found (can't continue)
    if (tree->right == nullptr)
    {
        return tree;
    }
    else
    {
        return getmax(tree->right);
    }
}

BTreeNode* BST::deletemax(BTreeNode*& tree)
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
        tree->right = deletemax(tree->right);
        return tree;
    }
}
