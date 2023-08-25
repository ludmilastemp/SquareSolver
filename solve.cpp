#include <math.h>
#include <assert.h>

#include "solve.h"

bool IsZero(double x)
{
    const double EPS = 1e-9;
    return fabs(x) < EPS;
}

void FixZero(double* x)
{
    assert(x);

    if (IsZero(*x)){
        *x = 0.0;
    }
}

double Discriminant(const struct Coeffs* coeffs)
{
    return coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;
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
        double discrim = Discriminant(coeffs);

        if (IsZero(discrim))
        {
            roots->rootsCount = ROOTS_ONE;

            roots->x1 = -coeffs->b / (2 * coeffs->a);
            FixZero(&roots->x1);

            return;
        }

        if (discrim < 0)
        {
            roots->rootsCount = ROOTS_ZERO;

            return;
        }

        roots->rootsCount = ROOTS_TWO;

        double sqrt_discrim = sqrt(discrim);

        roots->x1 = (-coeffs->b - sqrt_discrim) / (2 * coeffs->a);
        roots->x2 = (-coeffs->b + sqrt_discrim) / (2 * coeffs->a);

        FixZero(&roots->x1);
        FixZero(&roots->x2);
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
            roots->rootsCount = ROOTS_INFINIK;
        }
        else
        {
            roots->rootsCount = ROOTS_ZERO;
        }
    }
    else
    {
        roots->rootsCount = ROOTS_ONE;

        roots->x1 = - coeffs->c / coeffs->b;
        FixZero(&roots->x1);
    }
}

