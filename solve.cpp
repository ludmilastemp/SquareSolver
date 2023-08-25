#include <math.h>
#include <assert.h>

#include "solve.h"

bool IsZero(double x)
{
    const double EPS = 1e-9;
    return fabs(x) < EPS;
}

void SolveQuadraticEquation(const struct Coeffs* coeffs, struct Roots* roots)
{
    assert(coeffs);
    assert(roots);

    if (IsZero(coeffs->a))
    {
        SolveLinearEquation(coeffs, roots);
    }
    else
    {
        double discrim = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c; // function
                    // = discriminant(coeffs);

        if (IsZero(discrim))
        {
            roots->count_roots = ROOTS_ONE;

            roots->x1 = -coeffs->b / (2 * coeffs->a);

            if (IsZero(roots->x1))// copy-pasta konkretnaya
            {
                roots->x1 = fabs(roots->x1);// copy-pasta konkretnaya
            }// copy-pasta konkretnaya

            return;
        }

        if (discrim < 0)
        {
            roots->count_roots = ROOTS_ZERO;

            return;
        }

        roots->count_roots = ROOTS_TWO;

        double sqrt_discrim = sqrt(discrim);

        roots->x1 = (-coeffs->b - sqrt_discrim) / (2 * coeffs->a);
        roots->x2 = (-coeffs->b + sqrt_discrim) / (2 * coeffs->a);

        if (IsZero(roots->x1)) // copy-pasta konkretnaya
        {
            roots->x1 = fabs(roots->x1);// copy-pasta konkretnaya
        }
        if (IsZero(roots->x2))// copy-pasta konkretnaya
        {
            roots->x2 = fabs(roots->x2);// copy-pasta konkretnaya
        }
    }
}

void SolveLinearEquation(const struct Coeffs* coeffs, struct Roots* roots)
{
    assert(coeffs);
    assert(roots);

    if (IsZero(coeffs->b))
    {
        if (IsZero(coeffs->c))
        {
            roots->count_roots = ROOTS_INFINI;
        }
        else
        {
            roots->count_roots = ROOTS_ZERO;
        }
    }
    else
    {
        roots->count_roots = ROOTS_ONE;
        roots->x1 = - coeffs->c / coeffs->b;
// copy-pasta konkretnaya
        if (IsZero(roots->x1))// copy-pasta konkretnaya// copy-pasta konkretnaya
        {// copy-pasta konkretnaya
            roots->x1 = fabs(roots->x1);// copy-pasta konkretnaya
        }// copy-pasta konkretnaya// copy-pasta konkretnaya// copy-pasta konkretnaya
    }// copy-pasta konkretnaya
}

