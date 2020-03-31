#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace recursive
{
int factorial(const int number);
int combinations(const int group, const int members);
};


namespace iterative
{
int factorial(const int number);
};

// Exception for invalid input
class InvalidInput {};

#endif // FUNCTIONS_H
