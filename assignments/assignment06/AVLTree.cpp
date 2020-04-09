#include "AVLTree.h"

// Constructor
template <class T>
AVLTreeType<T>::AVLTreeType()
{
    root = nullptr;
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

}

// Determines if a value is in the AVL tree
template <class T>
bool AVLTreeType<T>::contains(const T& value) const
{
    return false;
}

// Returns the height of the tree
template <class T>
int AVLTreeType<T>::height() const
{
    return -1;
}

// Traverses the AVL tree and prints the items in it in inorder
template <class T>
void AVLTreeType<T>::inorderTraversal() const
{

}

// Inserts an item into the ALV tree
template <class T>
bool AVLTreeType<T>::insert(const T& value)
{
    return false;
}

// Tests if the tree is empty
template <class T>
bool AVLTreeType<T>::isEmpty() const
{
    return false;
}

// Returns the number of leaves in the AVL tree
template <class T>
int AVLTreeType<T>::leaves() const
{
    return -1;
}

// Returns the length (number of nodes) in the AVL tree
template <class T>
int AVLTreeType<T>::length() const
{
    return -1;
}

// Traverses the AVL tree and prints the items in preorder
template <class T>
void AVLTreeType<T>::preorderTraversal() const
{

}

// Removes an item from the AVL tree
template <class T>
bool AVLTreeType<T>::remove(const T& value)
{
    return false;
}

// Retrieves a value from the tree
template <class T>
T AVLTreeType<T>::retrieve(const T& value)
{
    T item;
    return item;
}

// Private methods
// Balances the AVL tree, if necessary. If a node's balance factor is greater
// than 1, it is unbalanced and will balanced. Otherwise, nothing will change
template <class T>
AVLNode<T> *AVLTreeType<T>::balance(AVLNode<T> *&tree)
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

}

// Deletes a node from a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::deleteNode(AVLNode<T>*& node)
{
    return nullptr;
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
AVLNode<T>* AVLTreeType<T>::find(const AVLNode<T>* tree, const T& value) const
{
    return nullptr;
}

// Finds the node with the maximum value in a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::getmax(AVLNode<T>*& tree)
{
    return nullptr;
}

// Calculates the height of the subtree rooted at the given node
template <class T>
int AVLTreeType<T>::height(const AVLNode<T>* tree) const
{
    return -1;
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
                             const std::function<void(const T &value)> &callback)
{

}

// Inserts a new node into a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::insertIntoAVL(AVLNode<T>*& tree,
                                         AVLNode<T>*& newNode,
                                         bool& isTaller)
{
    return nullptr;
}

// Traverses a subtree in preorder
template <class T>
void AVLTreeType<T>::preorder(AVLNode<T>* tree) const
{

}

// Traverses a subtree in preorder and processes the value using the given
// callback function
template <class T>
void AVLTreeType<T>::preorder(AVLNode<T>* tree,
                             const std::function<void(const T& value)>& callback)
{

}

// Prints the value to the terminal
template <class T>
void AVLTreeType<T>::print(const T& value)
{

}

// Removes a value from a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::remove(AVLNode<T>*& tree, const T& value, bool& flag)
{
    return nullptr;
}

// Removes (not delete!) the node with the maximum value in a subtree pointer
// to it
template <class T>
AVLNode<T>* AVLTreeType<T>::removemax(AVLNode<T>*& tree)
{
    return nullptr;
}

// Retrieves an item from a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::retrieve(const AVLNode<T>* tree, const T& value)
{
    return nullptr;
}

// Performs a left rotation on a subtree
template <class T>
AVLNode<T>* AVLTreeType<T>::rotateLeft(AVLNode<T>*& tree)
{
    return nullptr;
}

// Performs a right rotation on a subtree
template <class T>
AVLNode<T> *AVLTreeType<T>::rotateRight(AVLNode<T> *&tree)
{
    return nullptr;
}

// Performs a left-right rotation on a subtree
template <class T>
AVLNode<T> *AVLTreeType<T>::rotateLeftRight(AVLNode<T> *&tree)
{
    return nullptr;
}

// Performs a right-left rotation on a subtree
template <class T>
AVLNode<T> *AVLTreeType<T>::rotateRightLeft(AVLNode<T> *&tree)
{
    return nullptr;
}
