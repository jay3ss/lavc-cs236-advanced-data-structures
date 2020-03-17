#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
    Node(T newData, Node* nextPtr = nullptr);
    Node();

    const T& data() const;
    void data(const T& newData);

    const Node* next() const;
    void next(const Node* newNextPtr);
private:
    T data_;
    Node* next_;
};

#include "Node.cpp"

#endif // NODE_H
