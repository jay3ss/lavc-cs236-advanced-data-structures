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
}
