/** file: main.cpp
In the areas of computer science and telecommunication, interleaving is very
popular method for making data retrieval more efficient by rearranging data in a
noncontiguous manner or creating a specific pattern based on its algorithm e.g.
bar code generator, alternate instruction sets in CPU ... Regardless of any
algorithms people use to develop their products, recursion is a popular strategy
to solve the interleaving problems.  In this assignment, we want to interleave
two strings using the following algorithm:

Picking one letter from string 1 (str1) in each recursive call until there is no
letter remaining in string 1; then keep picking one letter from string 2 (str2)
in each recursive call until there is no letter remaining in string 2.

Example:

(str1 = AB, str2 = MN, interleave ="")

1. Pick one character from str1 and put it in interleave string

(str1 = B, str2 = MN, interleave ="A")

2. Check if there is any character remaining in String 1: Yes, repeat Step 1.

(str1 = , str2 = MN, interleave ="AB")

No more characters remaining in String 1, now repeat Step 1 for String 2 until
is empty.

(str1 =  , str2 = N, interleave ="ABM")
(str1 =  , str2 = , interleave ="ABMN")

The interleave string length became 4 that is str1.length + str2.length; This
is the first interleave string, display it on the screen.

Recursive call will be returned and reach at step where call for character B
will be completed.
(str1 = B, str2 = MN, interleave ="A")
Since call for B is completed, now it will pick a letter from string 2 and next
call will be.

(str1 = B, str2 = N, interleave ="AM") and it continues.

Your task: Write a C++ program to solve the string interleaving problem
recursively using the above algorithm

SAMPLE RUNS:

Sample Run 1:
-------------

Enter the string str1: AB
Enter the string str2: MN

The interleavings are:

ABMN
AMBN
AMNB
MABN
MANB
MNAB

===================

Sample Run 2:
-------------

Enter the string str1: abc
Enter the string str2: 12

The interleavings are:

abc12
ab1c2
ab12c
a1bc2
a1b2c
a12bc
1abc2
1ab2c
1a2bc
12abc */

#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void interleavings(string, string, string);

int main()
{
    string str1, str2;

    cout << "Enter the string str1: ";
    getline(cin, str1);

    cout << "\nEnter the string str2: ";
    getline(cin, str2);

    cout << "\n\nThe interleavings are:\n\n";
    interleavings(str1, str2, "");
}

// Function definitions
void interleavings(string str1, string str2, string interleave)
{

}
