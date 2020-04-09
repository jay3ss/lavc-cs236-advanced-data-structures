#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <functional>
#include <iostream>

template <class T>
class AVLNode
{
public:
    AVLNode(AVLNode* leftPtr = nullptr, AVLNode* rightPtr = nullptr)
        : left(leftPtr), right(rightPtr) {}
    AVLNode(T value, AVLNode* leftPtr = nullptr, AVLNode* rightPtr = nullptr)
        : left(leftPtr), right(rightPtr), info(value) {}
private:
    T info;
    int bfactor;
    AVLNode* left;
    AVLNode* right;
    friend class AVLTreetype;
};

template <class T>
class AVLTreeType
{
public:
    /** Constructor */
    AVLTreeType();

    /** Destructor */
    ~AVLTreeType();

    /** Clears the AVL tree of all items
    @post: the tree will be completely empty */
    void clear();

    /** Determines if a value is in the AVL tree
    @param: value a reference to the value to search for
    @return: true if the the value is found, false otherwise */
    bool contains(const T& value) const;

    /** Traverses the AVL tree and prints the items in inorder
    @post: the value of the items in the AVL tree will printed to the terminal
        in preorder */
    void inorderTraversal() const;

    /** Inserts an item into the ALV tree
    @param: newItem the item to be inserted
    @return: true if the item was inserted, false otherwise
    @post: the item will be inserted into the AVL tree */
    bool insert(const T& newItem);

    /** Traverses the AVL tree and prints the items in preorder
    @post: the value of the items in the AVL tree will printed to the terminal
        in inorder */
    void preorderTraversal() const;

    /** Removes an item from the AVL tree
    @param: removeItem the item to be removed
    @return: true if the item was found and removed, false otherwise
    @post: the item will no longer be in the AVL tree  */
    bool remove(const T& removeItem);

    /** Retrieves a value from the tree
    @param: value the value to search for
    @return: returns the value from the tree if it is found, NULL otherwise */
    T retrieve(const T& value);
private:
    AVLNode<T>* root;

    /** Balances the AVL tree, if necessary. If a node's balance factor is
        greater than 1, it is unbalanced and will balanced. Otherwise, nothing
        will change
    @pre: the subtree is not empty
    @param: tree the subtree to balance
    @return: pointer to the balanced tree
    @post: the subtree will be balanced */
    AVLNode<T>* balance(AVLNode<T>*& tree);

    /** Balances a subtree from the left, if necessary
    @pre: the subtree is not empty
    @param: tree the subtree to balance
    @return: pointer to the balanced tree
    @post: the subtree will be balanced */
    AVLNode<T>* balanceFromLeft(AVLNode<T>*& tree);

    /** Balances a subtree from the right, if necessary
    @pre: the subtree is not empty
    @param: tree the subtree to balance
    @return: pointer to the balanced tree
    @post: the subtree will be balanced */
    AVLNode<T>* balanceFromRight(AVLNode<T>*& tree);

    /** Clears a subtree of all its contents
    @param: tree a pointer to the subtree to clear
    @post: the subtree content's will be removed */
    void clear(AVLNode<T>*& tree);

    /** Deletes a node from a subtree
    @param: node a reference to a pointer to the node to be deleted
    @return: pointer to the node that takes the place of the deleted node
    @post: the node will be deleted and, if possible, replaced with a new
        node */
    AVLNode<T>* deleteNode(AVLNode<T>*& tree);

    /** Calculates the difference between the heights of the left and right
        subtrees rooted at the given node
    @pre: the given subtree is not empty
    @param: tree pointer to the subtree
    @return: the height of the subtree */
    int difference(const AVLNode<T>* tree) const;

    /** Finds a value in a subtree
    @param: tree the subtree to search
    @param: value the value to find in the subtree
    @return: pointer to the location of the node in the subtree that holds
        value */
    AVLNode<T>* find(AVLNode<T>* tree, const T& value) const;

    /** Finds the node with the maximum value in a subtree
    @param: tree a reference to a pointer to the subtree to search
    @return: pointer to the node with the maximum value in a subtree */
    AVLNode<T>* getmax(AVLNode<T>*& tree);

    /** Calculates the height of the subtree rooted at the given node
    @param: tree pointer to the subtree
    @return: the height of the subtree */
    int height(const AVLNode<T>* tree) const;

    /** Traverses a subtree in inorder
    @pre: the subtree should not be empty
    @param: tree the subtree to be traversed */
    void inorder(AVLNode<T>* tree) const;

    /** Traverses a subtree in inorder and processes the value using the given
        callback function
    @pre: the subtree should not be empty
    @param: tree the subtree to be traversed
    @param: callback the function used to process the value in the node */
    void inorder(AVLNode<T> *tree,
                const std::function<void(const T& value)>& callback);

    /** Inserts a new node into a subtree
    @param: tree the subtree that the new node will be inserted into
    @param: newNode the node to be inserted into the subtree
    @param: isTaller a flag to indicate if subtree is taller  */
    AVLNode<T>* insertIntoAVL(AVLNode<T>*& tree,
                              AVLNode<T>*& newNode,
                              bool& isTaller);

    /** Traverses a subtree in preorder
    @pre: the subtree should not be empty
    @param: tree the subtree to be traversed */
    void preorder(AVLNode<T> *tree);

    /** Traverses a subtree in preorder
    @pre: the subtree should not be empty
    @param: tree the subtree to be traversed
    @param: callback the function used to process the value in the node */
    void preorder(AVLNode<T> *tree,
                  const std::function<void(const T &value)>& callback);

    /** Prints the value to the terminal
    @param: value reference to the value to be printed
    @post: the terminal will have the value printed to it */
    static void print(const T& value);

    /** Removes a value from a subtree
    @param: tree the subtree to remove the value from
    @param: valuethe value to remove
    @param: flag a flag to signal whether or not the value was found and removed
        or not
    @post: if found, the value will be removed from the subtree. the structure
        or shape of the tree may change as well
           flag will be set to true if the value is found and removed, false
           otherwise*/
    AVLNode<T>* remove(AVLNode<T>*& tree, const T& value, bool& flag);

    /** Removes (not delete!) the node with the maximum value in a subtree
        pointer to it
    @param: tree a reference to a pointer to the subtree to search
    @return: a pointer to the node with the maximum value in the subtree
    @post: the node with the maximum value in the subtree will be removed from
        the subtree but not deleted */
    AVLNode<T>* removemax(AVLNode<T>*& node);

    /** Retrieves an item from a subtree
    @param: tree the subtree to search
    @param: value reference to the value to search for
    @param: flag flag a flag to signal whether or not the value was found and
        removed or not
    @post: flag will be true if the value is found, false otherwise
           value will hold the value if found, NULL otherwise */
    void retrieve(const AVLNode<T>* tree, const T& value, bool& flag);

    /** Performs a left rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be left rotated
    @return: pointer to the left rotated subtree
    @post: the subtree will be left rotated */
    AVLNode<T>* rotateLeft(AVLNode<T>*& tree);

    /** Performs a right rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be right rotated
    @return: pointer to the right rotated subtree
    @post: the subtree will be right rotated */
    AVLNode<T>* rotateRight(AVLNode<T>*& tree);

    /** Performs a left-right rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be left-right rotated
    @return: pointer to the left-right rotated subtree
    @post: the subtree will be left-right rotated */
    AVLNode<T>* rotateLeftRight(AVLNode<T>*& tree);

    /** Performs a right-left rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be right-left rotated
    @return: pointer to the right-left rotated subtree
    @post: the subtree will be right-left rotated */
    AVLNode<T>* rotateRightLeft(AVLNode<T>*& tree);
};

#include "AVLTree.cpp"

#endif // AVL_TREE_H
