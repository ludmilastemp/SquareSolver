#include <math.h>
#include <assert.h>

#include "solve.h"
#include "tests.h"
#include "infile.h"
#include "print_equation.h"
#include "draw_cats.h"
#include "struct.h"

const char* StringRootsCount[4] = {"ROOTS_ZERO", "ROOTS_ONE", "ROOTS_TWO", "ROOTS_INFINIK"};

void Test()
{
    DrawCats3();

    int testsPassed = 0;
    int testsAll = 0;

    FILE *fp = fopen("tests.txt", "r");
    assert(fp);

    Coeffs coeffs = { .a = 0, .b = 0, .c = 0 };
    Roots roots = { .x1 = 0, .x2 = 0, .rootsCount = ROOTS_ZERO };
    Roots rootsRef = { .x1 = 0, .x2 = 0, .rootsCount = ROOTS_ZERO };

    while (true)
    {
        ++testsAll;

        roots.x1 = 0;
        roots.x2 = 0;

        switch((int)FscanCoeffs(fp, &coeffs, &rootsRef))
        {

            case SCAN_EOF:
                printf("\n" YELLOW "\nPassed %d tests out of %d!" CLEANER "\n\n", testsPassed, testsAll);
                return;
            case SCAN_INCORRECT:
                printf(RED_UNDER_LINE "\nTest %2d !ERROR!" CLEANER, testsAll);
                printf(RED " The coefficients are entered incorrectly!" CLEANER);
                break;
            case SCAN_CORRECT:
                SolveQuadraticEquation(&coeffs, &roots);

                if( IsEqual(roots.x1, rootsRef.x1) &&
                    IsEqual(roots.x2, rootsRef.x2) &&
                    rootsRef.rootsCount == roots.rootsCount)
                {
                    ++testsPassed;
                    printf(GREEN_UNDER_LINE "\nTest %2d OK" CLEANER, testsAll);
                }
                else
                {
                    printf(RED_UNDER_LINE "\nTest %2d !ERROR!\n" CLEANER, testsAll);
                    PrintEquation(&coeffs);
                    printf(RED "\n\t received  x1 = %lg, x2 = %lg, rootsCount = %s" CLEANER,
                           roots.x1, roots.x2, StringRootsCount[roots.rootsCount]);
                    printf(RED "\n\t expected  x1 = %lg, x2 = %lg, rootsCount = %s" CLEANER,
                           rootsRef.x1, rootsRef.x2, StringRootsCount[rootsRef.rootsCount]);
                }
                break;
            default:
                break;
        }
    }
}
