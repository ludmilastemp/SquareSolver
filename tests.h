#ifndef __TESTS__
#define __TESTS__

#include <stdio.h>

/**
    \brief Function compares two floating point numbers
    \param x1, x2 numbers to compare
    \return true  - if the numbers are equal
            false - otherwise

*/
bool IsEqual(double x1, double x2);

void PrintEquation(const struct Coeffs* coeffs);

int MyScan(FILE* fp, double* x);


int FscanCoeffs(FILE* fp, struct Coeffs* coeffs, struct Roots* rootsRef);

/**
    \brief Function checks whether the SolveQuadraticEquation function is working correctly
    \details Function compares the reference roots of several quadratic equations with the roots of the equation obtained using the SolveQuadraticEquation function
    \param void
    \return void
*/
void Test();

#endif
