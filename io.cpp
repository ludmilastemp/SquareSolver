#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "io.h"
#include "print_equation.h"
#include "struct.h"

#define GREEN             "\033[102;1m"
#define CLEANER           "\033[0m"

ScanReturn ScanCoeff(struct Coeffs* coeffs)
{
    assert(coeffs);

    int nVarsEntered = scanf("%lg%lg%lg", &coeffs->a, &coeffs->b, &coeffs->c);

    int restOfLine = getchar();

    if (nVarsEntered == 3     && restOfLine == '\n')
    {
        PrintEquation(coeffs);
        return SCAN_CORRECT;
    }
    if (nVarsEntered == EOF   || restOfLine == EOF)
    {
        printf("The meowfficients are entered incorrectly!\n");
        return SCAN_TERMINATE;
    }

    while (restOfLine != '\n' && restOfLine != EOF)
    {
        restOfLine = getchar();
    }

    if (restOfLine == '\n')
    {
        printf("The meowfficients are entered incorrectly! Try again\n");
    }
    else
    {
        printf("The meowfficients are entered incorrectly!\n");
        return SCAN_TERMINATE;
    }

    return SCAN_INCORRECT;
}

void PrintRoots(const struct Roots* roots)
{
    assert(roots);

    switch (roots->rootsCount)
    {
        case ROOTS_ZERO:
            printf(GREEN "\n\t\tno roots" CLEANER);
            break;
        case ROOTS_ONE:
            printf(GREEN "\n\t\tx = %.6g" CLEANER, roots->x1);
            break;
        case ROOTS_TWO:
            printf(GREEN "\n\t\tx = %.6g" CLEANER, roots->x1);
            printf(GREEN "\n\t\tx = %.6g" CLEANER,   roots->x2);
            break;
        case ROOTS_INFINIK:
            printf(GREEN "\n\t\tx = any real number" CLEANER);
            break;
        default:
            printf(GREEN "\n\t\tInvalid error! rootsCount = %d" CLEANER, roots->rootsCount);
            break;
    }
}

