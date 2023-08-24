#ifndef __TESTS__
#define __TESTS__

/**
    \brief Function compares two floating point numbers
    \param x1, x2 numbers to compare
    \return 0 - if the numbers are not equal
        1 - if the numbers are equal
*/
bool CheckEquality(double x1, double x2);

/**
    \brief Function checks whether the SolveQuadraticEquation function is working correctly
    \details Function compares the reference roots of several quadratic equations with the roots of the equation obtained using the SolveQuadraticEquation function
    \param void
    \return void
*/
void Test();

#endif
