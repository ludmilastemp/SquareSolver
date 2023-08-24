#ifndef __SOLVE__
#define __SOLVE__

///Set of possible number of roots
enum RootsCount
{
    ROOTS_ZERO,   ///< no roots
    ROOTS_ONE,    ///< one root
    ROOTS_TWO,    ///< two roots
    ROOTS_INFINI  ///< root - any real number
};

///Structure combining the coefficients of a quadratic equation
struct Coeffs
{
    double a;     ///< coefficients for the second degree of the unknown
    double b;     ///< coefficient at the first degree of the unknown
    double c;     ///< free coefficient
};

///Structure combining the roots of a quadratic equation
struct Roots
{
    double x1, x2;            ///< roots of the quadratic equation
    RootsCount count_roots;   ///< number of roots of the quadratic equation
};

/**
    \brief Function compares a floating point number with zero
    \param x the number to compare
    \return 0 - if the number is not close to zero
        1 - if the number is close to zero
*/
bool CompareZero(double x);

/**
    \brief Function solves a linear equation
    \details The function finds solutions to a linear equation with real coefficients
    \param coeffs pointer to the structure in which the coefficients of the linear equation are stored
    \param roots pointer to the structure where the roots are stored
    \return void
*/
void SolveLinearEquation(const struct Coeffs* coeffs, struct Roots* roots);

/**
    \brief Function solves the quadratic equation
    \details The function finds solutions to a quadratic equation with real coefficients
    \param coeffs pointer to the structure in which the coefficients of the quadratic equation are stored
    \param roots pointer to the structure where the roots are stored
    \return void
*/
void SolveQuadraticEquation(const struct Coeffs* coeffs, struct Roots* roots);

#endif
