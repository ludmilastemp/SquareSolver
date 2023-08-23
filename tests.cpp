#include "header.h"
#include "io.h"
#include "solve.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>

bool CheckEquality(double x1, double x2);

bool CheckEquality(double x1, double x2)
{
    const double EPS = 1e-9;
    return fabs(x1 - x2) < EPS;
}

void Test()
{
    int tests_passed = 0;
    int tests_all = 0;

    FILE *fp = fopen("tests.txt", "r");

    struct Coeffs coeffs = {};
    struct Roots rootsRef = {};
    struct Roots roots = {};
    int count_rootsRef = 0;

    for (int i = 0; i < 10; ++i)
    {
        ++tests_all;

        fscanf(fp, "%lg", &coeffs.a);
        fscanf(fp, "%lg", &coeffs.b);
        fscanf(fp, "%lg", &coeffs.c);
        fscanf(fp, "%lg", &rootsRef.x1);
        fscanf(fp, "%lg", &rootsRef.x2);
        fscanf(fp, "%d", &count_rootsRef);

        SolveQuadraticEquation(&coeffs, &roots);

        if( CheckEquality(roots.x1, rootsRef.x1) &&
            CheckEquality(roots.x2, rootsRef.x2) &&
            CheckEquality(count_rootsRef, roots.count_roots) )
        {
            ++tests_passed;
        }
        else
        {
            printf("ERROR!   x1 = %lg, x2 = %lg, count_roots = %d\n", roots.x1, roots.x2, roots.count_roots);
            printf("expected x1 = %lg, x2 = %lg, count_roots = %d\n", rootsRef.x1, rootsRef.x2, count_rootsRef);
        }
    }

    printf("\nPassed %d tests out of %d!\n", tests_passed, tests_all);
    //const char[] color_red = "";
    //printf("\dfsdfsd" "mHello\033[0m");
}
