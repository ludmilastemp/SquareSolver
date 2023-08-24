#include "io.h"
#include "solve.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>

bool CheckEquality(double x1, double x2)
{
    const double EPS = 1e-9;
    return fabs(x1 - x2) < EPS;
}

void Test()
{
    int tests_passed = 0;
    int tests_all = 0;

    const char color_red [] =       "\033[41;1;4m";
    const char color_green [] =     "\033[102;1;4m";
    const char color_red_1 [] =     "\033[41;1m";
    const char color_yellow_1 [] =  "\033[30;103;1m";
    const char cleaner [] =         "\033[0m";

    FILE *fp = fopen("tests.txt", "r");

    struct Coeffs coeffs = {};
    struct Roots rootsRef = {};
    struct Roots roots = {};
    int count_rootsRef = 0;

    for (int i = 0; i < 10; ++i)
    {
        ++tests_all;

        roots.x1 = 0;
        roots.x2 = 0;

        fscanf(fp, "%lg", &coeffs.a);
        fscanf(fp, "%lg", &coeffs.b);
        fscanf(fp, "%lg", &coeffs.c);
        fscanf(fp, "%lg", &rootsRef.x1);
        fscanf(fp, "%lg", &rootsRef.x2);
        fscanf(fp, "%d", &count_rootsRef);
        //fscanf(fp, "%d", &rootsRef.count_roots);

        SolveQuadraticEquation(&coeffs, &roots);

        if( CheckEquality(roots.x1, rootsRef.x1) &&
            CheckEquality(roots.x2, rootsRef.x2) &&
            CheckEquality(count_rootsRef, roots.count_roots) )
            //CheckEquality(rootsRef.count_roots, roots.count_roots) )
        {
            ++tests_passed;
            printf("%s" "\nTest %2d OK" "%s", color_green, tests_all, cleaner);

        }
        else
        {
            printf("%s" "\nTest %2d !ERROR!" "%s", color_red, tests_all, cleaner);
            printf("%s" "   x1 = %lg, x2 = %lg, count_roots = %d" "%s", color_red_1, roots.x1, roots.x2, roots.count_roots, cleaner);
            printf("%s\n        " "expected" "%s", color_red_1, cleaner);
            printf("%s" "  x1 = %lg, x2 = %lg, count_roots = %d" "%s", color_red_1, rootsRef.x1, rootsRef.x2, count_rootsRef, cleaner);
        }
    }

    printf("\n%s" "\nPassed %d tests out of %d!" "%s\n", color_yellow_1, tests_passed, tests_all, cleaner);

}
