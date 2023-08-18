#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

void QuadraticEquation(double a, double b, double c, double* x1, double* x2);
bool CompareEpsilon(double x);
bool CheckLinearEquation(double a);
void CountingRoot(double b, double c, double* x1);
double Discriminant(double a, double b, double c);
void CountingRoots(double a, double b, double discrim, double* x1, double* x2);

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    QuadraticEquation(a, b, c, &x1, &x2);

    return 0;
}

void QuadraticEquation(double a, double b, double c, double* x1, double* x2)
{
    if (CheckLinearEquation(a))
    {
        CountingRoot(b, c, x1);
    }

    else
    {
        double discrim = Discriminant(a, b, c);

        CountingRoots(a, b, discrim, x1, x2);
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

void CountingRoot(double b, double c, double* x1)
{
    if (CompareEpsilon(b))
    {
        if (CompareEpsilon(c))
        {
            printf("x = any real");
        }

        else
        {
            printf("no roots");
        }

        return;
    }

    else
    {
        *x1 = -c/b;

        if (CompareEpsilon(*x1))
        {
            *x1 = fabs(*x1);
        }

    }

    printf("x = %.8lf", *x1);
}

double Discriminant(double a, double b, double c)
{
    return b*b-4*a*c;
}

void CountingRoots(double a, double b, double discrim, double* x1, double* x2)
{
    if (discrim < 0)
    {
        printf("no roots");

        return;
    }

    if (discrim < EPS)
    {
        *x1 = -b/(2*a);

        if (CompareEpsilon(*x1))
        {
            *x1 = fabs(*x1);
        }

        printf("x = %.8lf", *x1);

        return;
    }

    *x1 = (-b-sqrt(discrim))/(2*a);
    *x2 = (-b+sqrt(discrim))/(2*a);

    if (CompareEpsilon(*x1))
    {
        *x1 = fabs(*x1);
    }
    if (CompareEpsilon(*x2))
    {
        *x2 = fabs(*x2);
    }

    printf("x = %.8lf\nx = %.8lf", *x1, *x2);
}
