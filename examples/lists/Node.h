#ifndef NODE_H
#define NODE_H

template <class E>
class Node
{
public:
    E element;
    Node *next;

    // Constructors
    Node(const E& elemVal, Node* nextVal=nullptr)
    { element = elemVal; next = nextVal; }

    Node(Node* nextVal = nullptr) { next = nextVal; }
};

#endif // NODE_H
