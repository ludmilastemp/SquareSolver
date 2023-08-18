#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

struct Coeffs
{
    double a;
    double b;
    double c;
};

void QuadraticEquation(const struct Coeffs* coeffs);
bool CompareEpsilon(double x);
bool CheckLinearEquation(double x);
void CountingRoot(const struct Coeffs* coeffs);
double Discriminant(const struct Coeffs* coeffs);
void CountingRoots(const struct Coeffs* coeffs, double discrim);

int main()
{
    struct Coeffs coeffs = { 0 };

    scanf("%lf", &coeffs.a);
    scanf("%lf", &coeffs.b);
    scanf("%lf", &coeffs.c);

    QuadraticEquation(&coeffs);

    return 0;
}

void QuadraticEquation(const struct Coeffs* coeffs)
{
    if (CheckLinearEquation(coeffs->a))
    {
        CountingRoot(coeffs);
    }

    else
    {
        double discrim = Discriminant(coeffs);

        CountingRoots(coeffs, discrim);
    }
}

bool CompareEpsilon(double x)
{
    return fabs(x) < EPS;
}

bool CheckLinearEquation(double a)
{
    return CompareEpsilon(a);
}

void CountingRoot(const struct Coeffs* coeffs)
{
    if (CompareEpsilon(coeffs->b))
    {
        if (CompareEpsilon(coeffs->c))
        {
            printf("x = any real");
        }

        else
        {
            printf("no roots");
        }
    }

    else
    {
        double x1 = - coeffs->c / coeffs->b;

        if (CompareEpsilon(x1))
        {
            x1 = fabs(x1);
        }

        printf("x = %.8lf", x1);
    }
}

double Discriminant(const struct Coeffs* coeffs)
{
    return coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;
}

void CountingRoots(const struct Coeffs* coeffs, double discrim)
{
    if (discrim < 0)
    {
        printf("no roots");

        return;
    }

    if (discrim < EPS)
    {
        double x1 = - coeffs->b / (2 * coeffs->a);

        if (CompareEpsilon(x1))
        {
            x1 = fabs(x1);
        }

        printf("x = %.8lf", x1);

        return;
    }

    double x1 = (- coeffs->b - sqrt(discrim)) / (2 * coeffs->a);
    double x2 = (- coeffs->b + sqrt(discrim)) / (2 * coeffs->a);

    if (CompareEpsilon(x1))
    {
        x1 = fabs(x1);
    }
    if (CompareEpsilon(x2))
    {
        x2 = fabs(x2);
    }

    printf("x = %.8lf\nx = %.8lf", x1, x2);
}
