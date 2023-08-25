#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "io.h"

ScanReturn ScanCoeff(struct Coeffs* coeffs)
{
    assert(coeffs); // != nullptr

    int n_vars_entered = scanf("%lg%lg%lg", &coeffs->a, &coeffs->b, &coeffs->c);

    int rest_line = getchar(); // pizdec

    if (n_vars_entered == EOF) return TERMIN; // po matanu termin ; +ate
    if (rest_line == '\n') return OK; // getchar() may return EOF

    printf("rest_line = %d\n", rest_line);

    printf("The coefficients are entered incorrectly! Try again\n");
    while (rest_line != '\n')
    {
        rest_line = getchar();
    }

    return UNCOR;
}

void PrintRoots(const struct Roots* roots)
{
    assert(roots);

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
            printf("x = any real"); // number epta blya
            break;
        default:
            printf("error"); // ???
            // invalid error, count_roots = %d\n
            break;
    }
}

