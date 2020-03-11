// file: ADTStackLList.cpp
// CS 236
// Joshua Saunders
// Assignment 3: ADT Stack Using Singly Linked List
//

// Objective : To understand the basic concept of linear structure “Stack” and
// its basic operations in Data Structures using a singly linked list.
//
// Description : A Stack is a collection of data items in which new elements may
// be inserted and deleted at one end called the “TOP” of stack
//
// To implement stack using linked list we need to define a node which in turn
// consist of data of pointer to the next node.The advantage of representing
// stack using linked lists is that we can decide which end should be top of a
// stack. And since the array size is fixed, in the array (linear)
// representation of stack, only fixed number of elements can be pushed onto
// the stack.If in a program the number of elements to be pushed exceeds the
// size of the array, the program may terminate in an error.We must overcome
// these problems.
//
// By using linked lists, we can dynamically organize data(such as an ordered
// list). Therefore, logically the stack is never full.The stack is full only
// if we run out of memory space.In this assignment, we select front end as
// top if stack in which we can add or remove data. Write a C++ program to
// implement basic Stack ADT operations using a singly linked list.You are
// given class template definition below.Your tasks are to write a complete
// header file ADTStackLList.h and the driver program ADTStackLList.cpp to

#include "ADTStackLList.h"

int main()
{
    stack<int> intStack;
}