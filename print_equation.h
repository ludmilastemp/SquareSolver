#ifndef __PRINT_EQUATION__
#define __PRINT_EQUATION__

#define RED_UNDER_LINE    "\033[41;1;4m"
#define GREEN_UNDER_LINE  "\033[102;1;4m"
#define RED               "\033[41;1m"
#define GREEN             "\033[102;1m"
#define YELLOW            "\033[30;103;1m"
#define CLEANER           "\033[0m"

/**
    \brief Function compares two floating point numbers
    \param x1, x2 numbers to compare
    \return true  - if the numbers are equal
            false - otherwise

*/
bool IsEqual(double x1, double x2);


void PrintEquation(const struct Coeffs* coeffs);

#endif
