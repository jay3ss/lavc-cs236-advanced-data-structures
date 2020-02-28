// file name: arrayListType.h
// Spring 2020

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

	// your code here
	// your code here

} // end print function

// find minimum value of the list
template <class elemType>
elemType arrayListType<elemType>::min() const
{

	// your code here
	// your code here

} // end min function

 // insertAt function definition
template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{

	// your code here
	// your code here


} //end insertAt function

// removeAt function definition
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{

	// your code here
	// your code here

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
}

#endif

