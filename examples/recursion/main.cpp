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
}
