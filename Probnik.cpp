#include <stdio.h>
#include <math.h>                            // never nester
#include <assert.h>

enum RootsCount
{
    ZERO,
    ONE,
    TWO,
    INFINI
};

struct Coeffs
{
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots
{
    double x1 = 0, x2 = 0;
    RootsCount count_roots = ZERO;
};

void ScanCoeffs(struct Coeffs* coeffs);
void CheckScan(double x);
void SolveQuadraticEquation(const struct Coeffs* coeffs, struct Roots* roots);
bool CompareZero(double x);
void SolveLinearEquation(const struct Coeffs* coeffs, struct Roots* roots);
void PrintRoots(const struct Roots* roots);

int main()
{
    struct Coeffs coeffs = { };
    struct Roots roots = { };

    ScanCoeffs(&coeffs);
    SolveQuadraticEquation(&coeffs, &roots);
    PrintRoots(&roots);

    return 0;
}

void ScanCoeffs(struct Coeffs* coeffs)
{
    scanf("%lf", &coeffs->a);     // cppref scanf Return
    scanf("%lf", &coeffs->b);
    scanf("%lf", &coeffs->c);

    CheckScan(coeffs->a);
    CheckScan(coeffs->b);
    CheckScan(coeffs->c);
}

void CheckScan(double x)
{
    assert (isfinite (x)); //
}

bool CompareZero(double x) //
{
    const double EPS = 1e-9;
    return fabs(x) < EPS;
}

void
SolveQuadraticEquation(const struct Coeffs* coeffs, //
                       struct Roots* roots)         // [out] afadfasdfasdasdfasdf
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
            printf("хрень");
            break;
    }
}
