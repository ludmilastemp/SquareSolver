#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "io.h"

ScanReturn ScanCoeff(struct Coeffs* coeffs)
{

    //NULL
    //__FILE__ __LINE__

    int n_vars_entered = 0;
    n_vars_entered = scanf("%lg%lg%lg", &coeffs->a, &coeffs->b, &coeffs->c);

    int rest_line = getchar();

    if (n_vars_entered == EOF) return TERMIN;
    if (rest_line == '\n') return OK;

    printf("The coefficients are entered incorrectly! Try again\n");
    while (rest_line != '\n')
    {
        rest_line = getchar();
    }

    return UNCOR;
}

void PrintRoots(const struct Roots* roots)
{
    switch (roots->count_roots)
    {
        case ROOTS_ZERO:
            printf("no roots");
            break;
        case ROOTS_ONE:
            printf("x = %.6lf\n", roots->x1);
            break;
        case ROOTS_TWO:
            printf("x = %.6lf\n", roots->x1);
            printf("x = %.6lf\n", roots->x2);
            break;
        case ROOTS_INFINI:
            printf("x = any real");
            break;
        default:
            printf("error");
            break;
    }
}

