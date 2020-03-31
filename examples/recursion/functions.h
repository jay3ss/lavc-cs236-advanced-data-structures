#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace recursive
{
template <class T>
T factorial(const T& number);
};


namespace iterative
{
template <class T>
T factorial(const T& number);
};

// Exception for invalid input
class InvalidInput {};

#endif // FUNCTIONS_H
