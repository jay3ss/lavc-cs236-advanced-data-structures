#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> arrList(5);

    cout << "Printing an empty list: ";
    arrList.print();
    cout << endl;

    cout << "Insert data into the empty list\n";
    for (int i = 0; i < 3; i++)
    {
        arrList.insertAt(i, i*i);
    }

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    cout << "Inserting data into the middle of a list that has data\n";
    arrList.insertAt(1, 1000);

    cout << "Printing the data in the list: ";
    arrList.print();
    cout << endl;

    return 0;
}
