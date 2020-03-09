// file name: arrayListType.h
// Spring 2020
// Joshua Saunders
// #Array - based List Program(Assignment 2)

// ## Objectives

// Insert and delete an item of an unsorted array list.

// ## Description

// 1. Your primary tasks for this exercise are to complete the header file by
// writing the definition of four functions with its description below:

// - `removeAt` function – to remove the item from the list at the position
// specified by location.  Because the list elements are in no particular order
// (unsorted list), you could simply remove the element by swapping the last
// element of the list with the item to be removed and reducing the length of the
// list.

// - `insertAt` function - to insert an item in the list at the position specified
// by location.  The item to be inserted is passed as a parameter to the function.

// - `print` function – to output the elements of the list.

// - `min` function – to output the smallest element of the list

// 2. And demonstrate the class `arrayListType` by write the main program (cpp)
// that asks a user to enter 5 integers. After displaying the entered 5 integers,
// ask the user the position of the item to be deleted and inserted.  Your program
// should include error checking if the position is out of range or array is full,
// display the final list of array and find the minimum value.

#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayListType
{
public:

	void print() const;
	//Function to output the elements of the list
	//Postcondition: Elements of the list are output on the
	//   standard output device.

	void insertAt(int location, const elemType& insertItem);
	//Function to insert an item in the list at the
	//position specified by location. The item to be inserted
	//is passed as a parameter to the function.
	//Postcondition: Starting at location, the elements of the
	//    list are shifted down, list[location] = insertItem;,
	//    and length++;. If the list is full or location is
	//    out of range, an appropriate message is displayed.

	void removeAt(int location);
	//Function to remove the item from the list at the
	//position specified by location
	//Postcondition: The list element at list[location] is removed
	//    and length is decremented by 1. If location is out of
	//    range,an appropriate message is displayed.

	elemType min() const;
	//find the minimum value of the array

	arrayListType(int size = 5);
	//constructor
	//Creates an array of the size specified by the
	//parameter size. The default array size is 5.
	//Postcondition: The list points to the array, length = 0,
	//    and maxSize = size

	~arrayListType();
	//destructor

protected:
	elemType *list;  //array to hold the list elements
	int length;      //to store the length of the list
	int maxSize;     //to store the maximum size of the list
};

/* +++++ Write function definition for the four functions below	++++ */

// print function definition
template <class elemType>
void arrayListType<elemType>::print() const
{
	// If the list is empty, print out an empty string. Otherwise, go through
	// the list element-by-element and print each one separated by a space
	if (length == 0)
	{
		cout << "";
	}
	else
	{
		// Print each element separated by a space except for the last one
		for (int i = 0; i < length - 1; i++)
		{
			cout << list[i] << " ";
		}
		cout << list[length-1];
	}

} // end print function

// find minimum value of the list
template <class elemType>
elemType arrayListType<elemType>::min() const
{
	// Assert that the list isn't empty
	assert(length != 0);

	// Iterate through each element in the list to find the minimum value
	elemType smallest = list[0];

	for (int i = 1; i < length; i++)
	{
		if (smallest > list[i])
		{
			smallest = list[i];
		}
	}

	return smallest;

} // end min function

 // insertAt function definition
template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
	// Check preconditions: 0 <= location <= length and the list isn't full
	if (0 <= location && location <= length + 1 && length < maxSize)
	{
		// If the insertion point is not at the end then we have to move all
		// elements that succeed the insertion point back by one spot
		if (location != length)
		{
			// Go backwards through the list and move each element "up"
			for (int i = length; i > location; i--)
			{
				list[i] = list[i - 1];
			}
		}
		list[location] = insertItem;
		length++;
	}
	// The insertion location is out of range
	else if (location < 0 || length < location)
	{
		cerr << "Position is out of range.\n";
	}
	// If the list is full then we cannot add any more elements to it
	else if (length == maxSize)
	{
		cerr << "The list is full.\n";
	}
} //end insertAt function

// removeAt function definition
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{

	// Check the preconditions: 0 <= location < length
	if (0 <= location && location < length)
	{
		// If the item to be removed is not the last item, then swap it with
		// the last item. Otherwise, we can simply decrease the length of the
		// list to remove the last item
		for (int i = location; i < length; i++)
		{
			list[i] = list[i+1];
		}

		length--;
	}
	// The preconditions have not been met. Print an error message
	else
	{
		cerr << "The location of the item to be removed is out of range.\n";
	}

} //end removeAt function


// ++++ You need the two templates below to avoid errors +++++++

// constructor function
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 5. " << endl;
		maxSize = 5;
	}
	else
		maxSize = size;

	length = 0;
	list = new elemType[maxSize];
	assert(list != NULL);
}

// destructor function
template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete[] list;
	list = nullptr;
}

#endif

