#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "header.h"
#include "io.h"

//void ScanCoeff(double* x);
//void PrintRoots(const struct Roots* roots);

void ScanCoeff(double* x)
{
    scanf("%lf", x);

    //12dfs //cppref
    assert (isfinite (*x));
}

void PrintRoots(const struct Roots* roots)
{
    switch (roots->count_roots)
    {
        case ZERO:
            printf("no roots");
            break;
        case ONE:
            printf("x = %f\n", roots->x1);
            break;
        case TWO:
            printf("x = %f\n", roots->x1);
            printf("x = %f\n", roots->x2);
            break;
        case INFINI:
            printf("x = any real");
            break;
        default:
            printf("error");
            break;
    }
}

