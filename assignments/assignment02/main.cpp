// file name: main.cpp
// Spring 2020
// Joshua Saunders
// #Array - based List Program(Assignment 2)
#include <iostream>
#include "arrayListType.h"

using namespace std;

// Function prototypes
// Adds five ints to the list
void addFiveInts(arrayListType<int> &list);

// Removes an int from the list and does bounds checking
int removeInt(arrayListType<int> &list, int numInts);

// Adds an int to the list and does bounds checking
int addInt(arrayListType<int> &list, int numInts, const int maxSize);

int main()
{
    arrayListType<int> intList;
    int numInts = 5;
    const int MAX_SIZE = numInts;

    addFiveInts(intList);
    numInts = removeInt(intList, numInts);
    numInts = addInt(intList, numInts, MAX_SIZE);

    // Display the smallest integer in the list
    cout << "\nThe smallest element: " << intList.min();
    cout << endl;

    return 0;
}


void addFiveInts(arrayListType<int> &list)
{
    // Prompt the user to enter five integers, insert them into the list, then
    // display the list
    int int1, int2, int3, int4, int5;
    cout << "Enter 5 integers: ";
    cin >> int1 >> int2 >> int3 >> int4 >> int5;

    list.insertAt(0, int1);
    list.insertAt(1, int2);
    list.insertAt(2, int3);
    list.insertAt(3, int4);
    list.insertAt(4, int5);

    cout << "The list you entered is: ";
    list.print();
    cout << endl;
}

int removeInt(arrayListType<int> &list, int numInts)
{
    // Prompt the user to remove an integer, then display the list
    cout << "\nEnter the position of item to be deleted: ";
    int position;
    cin >> position;

    list.removeAt(position);
    if (position < numInts)
    {

        cout << "After removing the element at position " << position
            << ", the list is: ";
        list.print();
        cout << endl;
        numInts--;
    }
    else
    {
        cout << "The list does not change.\n";
    }


    return numInts;
}

int addInt(arrayListType<int> &list, int numInts, const int maxSize)
{
    // Prompt the user to insert an integer, then display the list
    cout << "\nEnter the position and an integer to be inserted: ";
    int position;
    int toInsert;
    cin >> position >> toInsert;
    list.insertAt(position, toInsert);
    // Only display this if the bounds are correct and the list
    // isn't full
    if ((position < numInts) && (numInts < maxSize))
    {
        numInts++;
    }
    else
    {
        cout << "The list does not change.\n";
    }
    cout << "Final list: ";
    list.print();
    cout << endl;

    return numInts;
}
