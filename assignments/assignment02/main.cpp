// file name: main.cpp
// Spring 2020
// Joshua Saunders
// #Array - based List Program(Assignment 2)
#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> intList;
    int int1, int2, int3, int4, int5;

    // Prompt the user to enter five integers, insert them into the list, then
    // display the list
    cout << "Enter 5 integers: ";
    cin >> int1 >> int2 >> int3 >> int4 >> int5;

    intList.insertAt(0, int1);
    intList.insertAt(1, int2);
    intList.insertAt(2, int3);
    intList.insertAt(3, int4);
    intList.insertAt(4, int5);

    cout << "The list you entered is: ";
    intList.print();
    cout << endl;

    // Prompt the user to remove an integer, then display the list
    cout << "\nEnter the position of item to be deleted: ";
    int position;
    cin >> position;
    intList.removeAt(position);

    // Prompt the user to insert an integer, then display the list
    cout << "\nEnter the position and an integer to be inserted: ";
    int toInsert;
    cin >> position >> toInsert;
    intList.insertAt(position, toInsert);

    cout << "Final list: ";
    intList.print();
    cout << endl;

    // Display the smallest integer in the list
    cout << "\nThe smallest element: " << intList.min();
    cout << endl;

    return 0;
}
