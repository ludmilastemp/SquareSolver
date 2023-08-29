#include <stdio.h>
#include <math.h>

#include "print_equation.h"
#include "struct.h"

bool IsEqual(double x1, double x2)
{
    const double EPS = 1e-9;
    return fabs(x1 - x2) < EPS;
}

void PrintEquation(const struct Coeffs* coeffs)
{
    printf(RED "\t ");

    if (IsEqual(coeffs->a, 0))
    {
        if (IsEqual(coeffs->b, 0))
        {
            printf("0 ");                    // 0
        }
        else if (IsEqual(coeffs->b, -1))
        {
            printf("-x ");                   // -x
        }
        else if (IsEqual(coeffs->b, 1))
        {
            printf("x ");                    // x
        }
        else
        {
            printf("%gx ", coeffs->b);      // bx
        }

        printf("= %g " CLEANER, -coeffs->c);     // = -c

        return;
    }
    else if (IsEqual(coeffs->a, -1))
    {
        printf("-x^2 ");                     // -x^2
    }
    else if (IsEqual(coeffs->a, 1))
    {
        printf("x^2 ");                      // x^2
    }
    else
    {
        printf("%gx^2 ", coeffs->a);        // ax^2
    }

    if (IsEqual(coeffs->b, 0))
    {
    }
    else if (IsEqual(coeffs->b, -1))
    {
        printf("- x ");                      // - x
    }
    else if (IsEqual(coeffs->b, 1))
    {
        printf("+ x ");                      // + x
    }
    else
    {
        if (coeffs->b > 0)
        {
            printf("+ ");                    // + bx
        }
        else
        {
            printf("- ");                    // - bx
        }
        printf("%gx ", fabs(coeffs->b));
    }

    printf("= %g " CLEANER, -coeffs->c);     // = -c
}
