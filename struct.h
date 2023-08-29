#ifndef __STRUCT__
#define __STRUCT__

#define RED_UNDER_LINE    "\033[41;1;4m"
#define GREEN_UNDER_LINE  "\033[102;1;4m"
#define RED               "\033[41;1m"
#define GREEN             "\033[102;1m"
#define YELLOW            "\033[30;103;1m"
#define WHITE             "\033[107;30m"
#define CLEANER           "\033[0m"

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
