#ifndef __HEADER__
#define __HEADER__

enum RootsCount
{
    ZERO,
    ONE,
    TWO,
    INFINI
};

struct Coeffs
{
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots
{
    double x1 = 0, x2 = 0;
    RootsCount count_roots = ZERO;
};

#endif
