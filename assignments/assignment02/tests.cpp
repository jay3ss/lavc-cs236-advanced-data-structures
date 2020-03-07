#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
    const int maxListSize = 50;
    arrayListType<int> arrList(maxListSize);

    cout << "Printing an empty list: ";
    arrList.print();
    cout << endl;

    cout << "\nInsert data into the empty list\n";
    for (int i = 0; i < 26; i++)
    {
        arrList.insertAt(i, i*i);
    }

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nInserting data into the middle of a list that has data\n";
    arrList.insertAt(17, 1000);

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nInserting data at the end of the list that has data\n";
    arrList.insertAt(27, 54321);

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nInserting data at the beginning of the list that has data\n";
    arrList.insertAt(0, 314159);

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nInserting data that is out of range (negative location: -10)\n";
    arrList.insertAt(-10, 54321);

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nInserting data that is out of range (beyond max size: 10000)\n";
    arrList.insertAt(10000, 54321);

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nFill the list and then insert more data:\n";
    for (int i = 29; i < maxListSize; i++)
    {
        arrList.insertAt(i, i*i);
    }

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "\nInsert data into a full list:\n";
    arrList.insertAt(51, 17);

    cout << "\nFind the smallest item in the list (should be 0):\n";
    cout << "The smallest item in the list is: " << arrList.min();
    cout << endl;

    cout << "\nRemove an item from the middle of the list (location 15, item: 196):\n";
    arrList.removeAt(15);
    arrList.print();
    cout << endl;

    cout << "\nRemove an item from the end of the list (location 48, item: 2304):\n";
    arrList.removeAt(48);
    arrList.print();
    cout << endl;

    cout << "\nAttempt to remove an item from the end of the list (location 48, item: 2304):\n";
    arrList.removeAt(48);
    arrList.print();
    cout << endl;

    cout << "\nRemove an item from the end of the list (location 48, item: 2304):\n";
    arrList.removeAt(48);
    arrList.print();
    cout << endl;

    return 0;
}
