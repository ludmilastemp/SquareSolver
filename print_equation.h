#ifndef __PRINT_EQUATION__
#define __PRINT_EQUATION__

/**
    \brief Function compares two floating point numbers
    \param x1, x2 numbers to compare
    \return true  - if the numbers are equal
            false - otherwise
*/
bool IsEqual(double x1, double x2);

/**
    \brief Function outputs a quadratic equation to the console
    \details The function outputs a quadratic equation of the form ax^2 + bx = -c to the console
    \param coeffs pointer to the structure in which the variables being read are stored
    \return void
*/
void PrintEquation(const struct Coeffs* coeffs);

#endif
