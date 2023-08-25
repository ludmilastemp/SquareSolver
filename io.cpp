#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "io.h"

ScanReturn ScanCoeff(struct Coeffs* coeffs)
{
    assert(coeffs);

    int nVarsEntered = scanf("%lg%lg%lg", &coeffs->a, &coeffs->b, &coeffs->c);

    int restOfLine = getchar();

    if (nVarsEntered == 3   && restOfLine == '\n')  return OK;
    if (nVarsEntered == EOF || restOfLine == EOF)
    {
        printf("The coefficients are entered incorrectly!\n");
        return TERMINATE;
    }

    while (restOfLine != '\n' && restOfLine != EOF)
    {
        restOfLine = getchar();
    }

    if (restOfLine == '\n')
    {
        printf("The coefficients are entered incorrectly! Try again\n");

    }
    else
    {
        printf("The coefficients are entered incorrectly!\n");
        return TERMINATE;
    }

    return UNCOR;
}

void PrintRoots(const struct Roots* roots)
{
    assert(roots);

    switch (roots->rootsCount)
    {
        case ROOTS_ZERO:
            printf("no roots\n");
            break;
        case ROOTS_ONE:
            printf("x = %.6g\n", roots->x1);
            break;
        case ROOTS_TWO:
            printf("x = %.6g\n", roots->x1);
            printf("x = %.6g\n", roots->x2);
            break;
        case ROOTS_INFINIK:
            printf("x = any real number\n");
            break;
        default:
            printf("Invalid error! rootsCount = %d\n", roots->rootsCount);
            break;
    }
}

