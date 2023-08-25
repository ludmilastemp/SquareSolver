#include "io.h"
#include "solve.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>

bool IsEqual(double x1, double x2)
{
    const double EPS = 1e-9;
    return fabs(x1 - x2) < EPS;
}

// camelCaseCodeStyle

// snake_case_code_style

// DedCaseCodeStyle

//["", "", "", ""]     - index == enum

void Test()
{
    int tests_passed = 0;
    int tests_all = 0;
    const int N_TESTS = 10; // ???
    // hardcoded
    // test

    const char color_red []      = "\033[41;1;4m";
    const char color_green []    = "\033[102;1;4m"; // regular
    const char color_red_1 []    = "\033[41;1m"; // underlined
    const char color_yellow_1 [] = "\033[30;103;1m";
    const char cleaner []        = "\033[0m";

    FILE *fp = fopen("tests.txt", "r");
    // what if file was not found?

    struct Coeffs coeffs = {}; // ???
    struct Roots rootsRef = {};
    struct Roots roots = {};
    int count_rootsRef = 0;  // use rootsRef.count_roots

    for (int i = 0; i < N_TESTS; ++i)
    {
        ++tests_all;

        roots.x1 = 0;
        roots.x2 = 0;

        fscanf(fp, "%lg", &coeffs.a);
        fscanf(fp, "%lg", &coeffs.b);
        fscanf(fp, "%lg", &coeffs.c);
        fscanf(fp, "%lg", &rootsRef.x1);
        fscanf(fp, "%lg", &rootsRef.x2);
        // tmp variable to read int, then assign to

        fscanf(fp, "%d", &count_rootsRef); // (int *) rootsRef.rootsCount

        // rootsCount
        // numberOfRoots

        // not fucking count_rootsRef with mixed code-style

        SolveQuadraticEquation(&coeffs, &roots); // a - 1e-200

        // delay
        // a -> 1e-200 5e-200 6e-200 -> -2 -3

        // x^2+5=0
        // -x^2+x=0
        if( IsEqual(roots.x1, rootsRef.x1) &&
            IsEqual(roots.x2, rootsRef.x2) &&
            IsEqual(count_rootsRef, roots.count_roots) )
        {
            ++tests_passed;
            printf("%s" "\nTest %2d OK" "%s", color_green, tests_all, cleaner);
        }
        else
        {
            // printfColored(colorYellow, "%f = %f\n");
            //printf(RED("\nTest %2d !ERROR!"), tests_all);   K&R macros
            printf("%s" "\nTest %2d !ERROR!" "%s", color_red, tests_all, cleaner);
            printf("%s" "   x1 = %lg, x2 = %lg, count_roots = %d" "%s", color_red_1, roots.x1, roots.x2, roots.count_roots, cleaner);
            printf("%s\n        " "expected" "%s", color_red_1, cleaner);
            printf("%s" "  x1 = %lg, x2 = %lg, count_roots = %d" "%s", color_red_1, rootsRef.x1, rootsRef.x2, count_rootsRef, cleaner);
        }                                                        //
    }

    printf("\n%s" "\nPassed %d tests out of %d!" "%s\n", color_yellow_1, tests_passed, tests_all, cleaner);

}
