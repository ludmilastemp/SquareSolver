#include <math.h>
//#include "solve.h"
#include "header.h"

void SolveQuadraticEquation(const struct Coeffs* coeffs, struct Roots* roots);


bool CompareZero(double x);
void SolveLinearEquation(const struct Coeffs* coeffs, struct Roots* roots);

bool CompareZero(double x)
{
    const double EPS = 1e-9;
    return fabs(x) < EPS;
}

void SolveQuadraticEquation(const struct Coeffs* coeffs, struct Roots* roots)
{
    if (CompareZero(coeffs->a))
    {
        SolveLinearEquation(coeffs, roots);
    }
    else
    {
        double discrim = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

        if (CompareZero(discrim))
        {
            roots->count_roots = ONE;

            roots->x1 = -coeffs->b / (2 * coeffs->a);

            if (CompareZero(roots->x1))
            {
                roots->x1 = fabs(roots->x1);
            }

            return;
        }

        if (discrim < 0)
        {
            roots->count_roots = ZERO;

            return;
        }

        roots->count_roots = TWO;

        double sqrt_discrim = sqrt(discrim);

        roots->x1 = (-coeffs->b - sqrt_discrim) / (2 * coeffs->a);
        roots->x2 = (-coeffs->b + sqrt_discrim) / (2 * coeffs->a);

        if (CompareZero(roots->x1))
        {
            roots->x1 = fabs(roots->x1);
        }
        if (CompareZero(roots->x2))
        {
            roots->x2 = fabs(roots->x2);
        }
    }
}

void SolveLinearEquation(const struct Coeffs* coeffs, struct Roots* roots)
{
    if (CompareZero(coeffs->b))
    {
        if (CompareZero(coeffs->c))
        {
            roots->count_roots = INFINI;
        }
        else
        {
            roots->count_roots = ZERO;
        }
    }
    else
    {
        roots->count_roots = ONE;
        roots->x1 = - coeffs->c / coeffs->b;

        if (CompareZero(roots->x1))
        {
            roots->x1 = fabs(roots->x1);
        }
    }
}

