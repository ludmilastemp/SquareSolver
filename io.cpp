#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "io.h"
#include "print_equation.h"
#include "draw_cats.h"
#include "struct.h"

ScanReturn ScanCoeff(struct Coeffs* coeffs)
{
    assert(coeffs);

    int nVarsEntered = scanf("%lg%lg%lg", &coeffs->a, &coeffs->b, &coeffs->c);

    int restOfLine = getchar(); //проверять строки
                                //добавить команды

    if (nVarsEntered == 0 && restOfLine == 's')
    {
        restOfLine = getchar();
        if (restOfLine != 'e') return SCAN_INCORRECT;
        restOfLine = getchar();
        if (restOfLine != 'c') return SCAN_INCORRECT;
        restOfLine = getchar();
        if (restOfLine != 'r') return SCAN_INCORRECT;
        restOfLine = getchar();
        if (restOfLine != 'e') return SCAN_INCORRECT;
        restOfLine = getchar();
        if (restOfLine != 't') return SCAN_INCORRECT;
        restOfLine = getchar();
        if (restOfLine == '\n')

        DrawBestCat();

        return SCAN_TERMINATE;
    }

    if (nVarsEntered == 3     && restOfLine == '\n')
    {
        return SCAN_CORRECT;
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

void PrintRoots(const struct Coeffs* coeffs, const struct Roots* roots)
{
    assert(roots);

    DrawCats2(1);

    PrintEquation(coeffs);

    DrawCats2(2);

    switch (roots->rootsCount)
    {
        case ROOTS_ZERO:
            printf(GREEN " no roots " CLEANER "\n");
            break;
        case ROOTS_ONE:
            printf(GREEN " x = %.6g " CLEANER "\n", roots->x1);
            break;
        case ROOTS_TWO:
            printf(GREEN " x = %.6g " CLEANER "\n", roots->x1);
            break;
        case ROOTS_INFINIK:
            printf(GREEN " x = any real number " CLEANER "\n");
            break;
        default:
            printf(GREEN " Invalid error! rootsCount = %d " CLEANER "\n", roots->rootsCount);
            break;
    }

    DrawCats2(3);

    if (roots->rootsCount == ROOTS_TWO)
    {
        printf(GREEN " x = %.6g " CLEANER "\n", roots->x2);
    }
    else
    {
        printf("\n");
    }

    DrawCats2(4);
}

