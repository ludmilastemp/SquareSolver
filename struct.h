#ifndef __STRUCT__
#define __STRUCT__

///Set of possible number of roots
enum RootsCount
{
    ROOTS_ZERO,             ///< no roots
    ROOTS_ONE,              ///< one root
    ROOTS_TWO,              ///< two roots
    ROOTS_INFINIK           ///< root - any real number
};

/// Set of possible scan states
enum ScanReturn
{
    SCAN_EOF,               ///< end of file
    SCAN_INCORRECT,         ///< incorrect input
    SCAN_CORRECT,           ///< all coefficients were calculated correctly
    SCAN_TERMINATE          ///< the terminal has fallen off
};

//const char* StringRootsCount[4] = {"ROOTS_ZERO", "ROOTS_ONE", "ROOTS_TWO", "ROOTS_INFINIK"};

///Structure combining the coefficients of a quadratic equation
struct Coeffs
{
    double a;               ///< coefficients for the second degree of the unknown
    double b;               ///< coefficient at the first degree of the unknown
    double c;               ///< free coefficient
};

///Structure combining the roots of a quadratic equation
struct Roots
{
    double x1, x2;          ///< roots of the quadratic equation
    RootsCount rootsCount;  ///< number of roots of the quadratic equation
};

#endif
