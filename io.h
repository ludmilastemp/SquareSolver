#ifndef __IO__
#define __IO__

/// Set of possible scan states
enum ScanReturn
{
    OK,      ///< all coefficients were calculated correctly
    TERMIN,  ///< the terminal has fallen off
    UNCOR,   ///< incorrect input
};

/**
    \brief Function reads the coefficients of the quadratic equation
    \details The function reads from the console the coefficients of the quadratic equation a, b and c
    \param coeffs pointer to the structure in which the coefficients of the quadratic equation are stored
    \return status of the scanf function
*/
ScanReturn ScanCoeff(struct Coeffs* coeffs);

/**
    \brief Function outputs solutions of the quadratic equation to the console
    \details Function outputs no roots - if there are no roots of the equation
        one root - if the quadratic (including linear) equation has one root
        two roots - if the quadratic equation has two roots
        x = any real - if the root is any real number
    \param roots pointer to the structure where the roots are stored
    \return void
*/
void PrintRoots(const struct Roots* roots);

#endif
