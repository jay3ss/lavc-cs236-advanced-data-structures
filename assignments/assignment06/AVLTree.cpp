#include "AVLTree.h"

// Constructor
template <class T>
AVLTreeType<T>::AVLTreeType()
{
    root = nullptr;
    numNodes = 0;
}

// Destructor
template <class T>
AVLTreeType<T>::~AVLTreeType()
{
    clear();
}

// Clears the AVL tree of all items
template <class T>
void AVLTreeType<T>::clear()
{
    clear(root);
    numNodes = 0;
}

// Determines if a value is in the AVL tree
template <class T>
bool AVLTreeType<T>::contains(const T& value)
{
    return nullptr != retrieve(root, value);
}

// Returns the height of the tree
template <class T>
int AVLTreeType<T>::height() const
{
    return height(root);
}

// Traverses the AVL tree and prints the items in it in inorder
template <class T>
void AVLTreeType<T>::inorderTraversal() const
{
    inorder(root, print);
}

// Inserts an item into the ALV tree
template <class T>
bool AVLTreeType<T>::insert(const T& value)
{
    bool isTaller = false;
    AVLNode<T>* newNode = new AVLNode<T>(value);

    // insert the new node and then determine if the tree is still balanced.
    // if it isn't balanced, then balance it
    root = insertIntoAVL(root, newNode, isTaller);
    if (isTaller)
    {
        balance(root);
    }

    return true;
}

// Tests if the tree is empty
template <class T>
bool AVLTreeType<T>::isEmpty() const
{
    return root == nullptr;
}

// Returns the number of leaves in the AVL tree
template <class T>
int AVLTreeType<T>::leaves() const
{
    return leaves(root);
}

// Returns the length (number of nodes) in the AVL tree
template <class T>
int AVLTreeType<T>::length() const
{
    return numNodes;
}

// Traverses the AVL tree and prints the items in preorder
template <class T>
void AVLTreeType<T>::preorderTraversal() const
{
    preorder(root, print);
}

// Removes an item from the AVL tree
template <class T>
bool AVLTreeType<T>::remove(const T& value)
{
    bool isRemoved = false;
    root =  remove(root, value, isRemoved);
    return isRemoved;
}

// Retrieves a value from the tree
template <class T>
T AVLTreeType<T>::retrieve(const T& value)
{
    // Attempt to find the value. If it can't be found (node is nullptr)
    // then throw an error. Otherwise, return the value
    AVLNode<T> *node = retrieve(root, value);
    if (node == nullptr)
    {
        // Enforce the precondition that the value should be in the tree
        throw NoSuchValue();
    }

    return node->info;
}

// Private methods
// Balances the AVL tree, if necessary. If a node's balance factor is greater
// than 1, it is unbalanced and will balanced. Otherwise, nothing will change
template <class T>
AVLNode<T> *AVLTreeType<T>::balance(AVLNode<T>*& tree)
{
    return nullptr;
}

// Balances a subtree from the left, if necessary
template <class T>
AVLNode<T>* AVLTreeType<T>::balanceFromLeft(AVLNode<T>*& tree)
{
    return nullptr;
}

// Balances a subtree from the right, if necessary
template <class T>
AVLNode<T>* AVLTreeType<T>::balanceFromRight(AVLNode<T>*& tree)
{
    return nullptr;
}

// Clears a subtree of all its contents
template <class T>
void AVLTreeType<T>::clear(AVLNode<T>*& tree)
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

// Deletes a node from a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::deleteNode(AVLNode<T>*& node)
{
    // three cases
    // 1. no children
    // 2. one child (left or right)
    // 3. two children
    AVLNode<T>* toDelete = node;
    if (node->left == nullptr)
    {
        node = node->right;
    }
    else if (node->right == nullptr)
    {
        node = node->left;
    }
    else
    {
        // to delete a node with two children
        // 1. find the logical predecessor (largest node of left subtree)
        // 2. replace node that we're deleting with logical predecessor
        // 3. delete the node
        toDelete = getmax(node->left);
        node->info = toDelete->info;
        node->left = removemax(node->left);
    }

    delete toDelete;
    toDelete = nullptr;

    return node;
}

// Calculates the difference between the heights of the left and right subtrees
// rooted at the given node
template <class T>
int AVLTreeType<T>::difference(const AVLNode<T>* tree) const
{
    return -1;
}

// Finds a value in a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::find(AVLNode<T>* tree, const T& value) const
{
    return nullptr;
}

// Finds the node with the maximum value in a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::getmax(AVLNode<T>*& tree)
{
    // traverse down the right subtree until the right child
    // is null, then we've arrived at the max node
    if (tree->right == nullptr)
    {
        return tree;
    }
    else
    {
        return getmax(tree->right);
    }
}

// Calculates the height of the subtree rooted at the given node
template <class T>
int AVLTreeType<T>::height(const AVLNode<T>* tree) const
{
    // Don't count null nodes
    if (tree == nullptr)
    {
        return 0;
    }

    // Recursively determine the height only using the larger
    // of the two subtrees (left vs right)
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Traverses a subtree in inorder
template <class T>
void AVLTreeType<T>::inorder(AVLNode<T>* tree) const
{

}

// Traverses a subtree in inorder and processes the value using the given
// callback function
template <class T>
void AVLTreeType<T>::inorder(AVLNode<T> *tree,
                             void callback(const T &value)) const
{
    if (tree != nullptr)
    {
        inorder(tree->left, callback);
        (*callback)(tree->info);
        inorder(tree->right, callback);
    }
}

// Inserts a new node into a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::insertIntoAVL(AVLNode<T>*& tree,
                                         AVLNode<T>*& newNode,
                                         bool& isTaller)
{
    // use convention that values less than or equal to the value
    // in a node belong in the left subtree
    if (tree == nullptr)
    {
        tree = newNode;
        numNodes++;
    }
    else if (tree->info >= newNode->info)
    {
        tree->left = insertIntoAVL(tree->left, newNode, isTaller);
    }
    else
    {
        tree->right = insertIntoAVL(tree->right, newNode, isTaller);
    }

    return tree;
}

// Counts the number of leaves in a subtree
template <class T>
int AVLTreeType<T>::leaves(const AVLNode<T>* tree) const
{
    if (tree == nullptr)
    {
        return 0;
    }

    if (tree->isLeaf())
    {
        return 1;
    }
    else
    {
        return leaves(tree->left) + leaves(tree->right);
    }
}

// Traverses a subtree in preorder
template <class T>
void AVLTreeType<T>::preorder(AVLNode<T>* tree) const
{

}

// Traverses a subtree in preorder and processes the value using the given
// callback function
template <class T>
void AVLTreeType<T>::preorder(AVLNode<T> *tree,
                              void callback(const T& value)) const
{
    if (tree != nullptr)
    {
        (*callback)(tree->info);
        preorder(tree->left, callback);
        preorder(tree->right, callback);
    }
}

// Prints the value to the terminal
template <class T>
void AVLTreeType<T>::print(const T& value)
{
    std::cout << value << " ";
}

// Removes a value from a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::remove(AVLNode<T>*& tree, const T& value, bool& flag)
{
    // didn't find the value
    if (tree == nullptr)
    {
        flag = false;
        return tree;
    }

    // keep traversing the subtree until we find the correct node
    if (tree->info < value) // go to the right subtree
    {
        tree->right = remove(tree->right, value, flag);
    }
    else if (tree->info > value) // go to the left subtree
    {
        tree->left = remove(tree->left, value, flag);
    }
    else // found the value, delete it
    {
        flag = true;
        numNodes--;
        tree = deleteNode(tree);
    }

    return tree;
}

// Removes (not delete!) the node with the maximum value in a subtree pointer
// to it
template <class T>
AVLNode<T>* AVLTreeType<T>::removemax(AVLNode<T>*& tree)
{
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

// Retrieves an item from a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::retrieve(AVLNode<T>* tree, const T& value)
{
    // The value is not in the tree
    if (tree == nullptr)
    {
        return nullptr;
    }

    // three cases
    // 1. go right
    // 2. go left
    // 3. found
    if (tree->info < value)
    {
        return retrieve(tree->right, value);
    }
    else if (tree->info > value)
    {
        return retrieve(tree->left, value);
    }
    else
    {
        return tree;
    }
}

// Performs a left rotation on a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::rotateLeft(AVLNode<T>*& tree)
{
    return nullptr;
}

// Performs a right rotation on a subtree
template <class T>
AVLNode<T> *AVLTreeType<T>::rotateRight(AVLNode<T>*& tree)
{
    AVLNode<T>
}

// Performs a left-right rotation on a subtree
template <class T>
AVLNode<T> *AVLTreeType<T>::rotateLeftRight(AVLNode<T>*& tree)
{
    return nullptr;
}

// Performs a right-left rotation on a subtree
template <class T>
AVLNode<T> *AVLTreeType<T>::rotateRightLeft(AVLNode<T>*& tree)
{
    return nullptr;
}
