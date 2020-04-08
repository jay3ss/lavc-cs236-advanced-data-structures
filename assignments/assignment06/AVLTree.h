#ifndef AVL_TREE_H
#define AVL_TREE_H

template <class T>
class AVLNode
{
public:
    AVLNode(AVLNode* leftPtr = nullptr, AVLNode*  rightPtr = nullptr)
        : left(leftPtr), right(rightPtr) {}
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
    void inorderTraversal() const;
    void preorderTraversal() const;
private:
    AVLNode<T>* root;
};

#include "AVLTree.cpp"

#endif // AVL_TREE_H
