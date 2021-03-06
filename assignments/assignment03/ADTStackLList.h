// file: ADTStackLList.h
// CS 236
// Joshua Saunders
// Assignment 3: ADT Stack Using Singly Linked List
//
//
// Objective : To understand the basic concept of linear structure “Stack” and
// its basic operations in Data Structures using a singly linked list.
//
// Description : A Stack is a collection of data items in which new elements may
// be inserted and deleted at one end called the “TOP” of stack
//
// To implement stack using linked list we need to define a node which in turn
// consist of data of pointer to the next node. The advantage of representing
// stack using linked lists is that we can decide which end should be top of a
// stack. And since the array size is fixed, in the array (linear)
// representation of stack, only fixed number of elements can be pushed onto
// the stack. If in a program the number of elements to be pushed exceeds the
// size of the array, the program may terminate in an error. We must overcome
// these problems.
//
// By using linked lists, we can dynamically organize data (such as an ordered
// list). Therefore, logically the stack is never full. The stack is full only
// if we run out of memory space. In this assignment, we select front end as
// top if stack in which we can add or remove data. Write a C++ program to
// implement basic Stack ADT operations using a singly linked list. You are
// given class template definition below. Your tasks are to write a complete
// header file ADTStackLList.h and the driver program ADTStackLList.cpp to
// test your functions.

#ifndef ADT_STACK_LL_H
#define ADT_STACK_LL_H

#include <cassert>
#include <iostream>

using namespace std;

// to implement a stack using a linked list
template <class T>
class node
{
public:
    node(T &item, node<T> *nextPtr) : data(item), next(nextPtr) {}
    node(T &item) : data(item), next(nullptr) {}
    node() {}
    T data;
    node<T> *next;
};

template <class T>
class stack
{
public:
    /** constructor */
    stack()
    {
        top = nullptr;
    }

    /** destructor */
    ~stack()
    {
        // keep popping until the stack is empty
        while (!isEmpty())
        {
            pop();
        }
    }

    /** copy constructor */
    stack(const stack &obj)
    {
        // If the obj is empty, then there's nothing copy
        if (obj.isEmpty())
        {
            top = nullptr;
        }
        else {
            // 1. Copy the object's first node
            // 2. Point to the first node in the chain
            // 3. Copy the remaining nodes
            node<T> *objNodePtr = obj.top;

            top = new node<T>;
            top->data = objNodePtr->data;
            node<T> *newChainPtr = top;

            while (objNodePtr->next != nullptr)
            {
                // 1. Advance the object's chain pointer
                // 2. Get the next item from the object
                // 3. Create a new node containing the item
                // 4. Link new node to end of new chain
                // 5. Advance pointer to new last node
                objNodePtr = objNodePtr->next;
                node<T>* newNodePtr = new node<T>(objNodePtr->data);
                newChainPtr->next = newNodePtr;
                newChainPtr = newChainPtr->next;
            }
            // Now mark the end of the chain
            newChainPtr = nullptr;
        }
    }

    /** to insert an item on to the stack
    @post if successful, the new entry will be added to the top of the stack
    @param it the item to be added to the top of the stack */
    void push(const T &it)
    {
        node<T> *newItem = new node<T>;
        newItem->data = it;
        newItem->next = top;
        top = newItem;
    }

    /** to remove an item from the stack
    @post if the stack isn't empty, the top of the stack will have been
    removed */
    void pop()
    {
        // only attempt to remove items if the stack isn't empty
        if (!isEmpty())
        {
            // copy the top pointer & advance the original to the next
            // item in the chain
            node<T> *toDelete = top;
            top = top->next;

            // delete the pointer and set it to nullptr to prevent having a
            // dangling pointer
            delete toDelete;
            toDelete = nullptr;
        }
    }

    /** to display the stack elements on screen
    @post the contents of the stack will be printed to the terminal */
    void display()
    {
        node<T> *temp = top;
        while (temp != nullptr)
        {
            cout << "|" << temp->data << "|\n";
            if (temp->next != nullptr)
            {
                cout << endl;
            }
            temp = temp->next;
        }
    }

    /** returns the item at the top of the stack
    @pre the stack is not empty
    @return the item at the top of the stack */
    T getTop() const
    {
        // Assert the precondition that the stack is not empty
        assert(!isEmpty() && "Error, stack is empty");
        return top->data;
    }

    /** determines if the stack is empty
    @return true if the stack is empty, false otherwise */
    bool isEmpty() const
    {
        return top == nullptr;
    }

private:
    node<T> *top;   // keep track of the first item in the stack
};

#endif // ADT_STACK_LL_H
