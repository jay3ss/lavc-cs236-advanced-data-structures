#include <iostream>
#include "functions.h"

int main()
{
    std::cout << "Recursive factorial(6) = " << recursive::factorial(6)
              << "\n";
    std::cout << "Iterative factorial(6) = " << iterative::factorial(6)
              << "\n";

    std::cout << std::endl;

    std::cout << "Recursive combinations(4, 3) = " << recursive::combinations(4, 3)
              << "\n";

    std::cout << std::endl;

    const int NUM_ELEMENTS = 100;
    int array[NUM_ELEMENTS];

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        array[i] = i;
    }

    std::cout << "Recursive binarySearch(array, 17, 0, 100) = "
              << recursive::binarySearch(array, 17, 0, NUM_ELEMENTS)
              << "\n";

    std::cout << "Recursive binarySearch(array, -50, 0, 100) = "
              << recursive::binarySearch(array, -50, 0, NUM_ELEMENTS)
              << "\n";

    std::cout << "Recursive binarySearch(array, 150, 0, 100) = "
              << recursive::binarySearch(array, 150, 0, NUM_ELEMENTS)
              << "\n";
    std::cout << "\n";

    const int ARRAY_2_LENGTH = 8;
    int array2[] = {7, 10, 3, 1, 15, 0, 25, 19};

    std::cout << "Unsorted array: ";
    helper::printArray(array2, ARRAY_2_LENGTH);
    std::cout << "\n";

    std::cout << "Recursive quickSort(array2, 0, 7)\n";
    recursive::quickSort(array2, 0, ARRAY_2_LENGTH);
    helper::printArray(array2, ARRAY_2_LENGTH);
    std::cout << "\n";
}
