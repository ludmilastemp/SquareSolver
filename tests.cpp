#include "io.h"
#include "solve.h"
#include "tests.h"

#include <math.h>
#include <assert.h>

#define GREEN_UNDER_LINE  "\033[102;1;4m"
#define RED_UNDER_LINE    "\033[41;1;4m"
#define RED               "\033[41;1m"
#define YELLOW            "\033[30;103;1m"
#define CLEANER           "\033[0m"

const char* StringRootsCount[4] = {"ROOTS_ZERO", "ROOTS_ONE", "ROOTS_TWO", "ROOTS_INFINIK"};

bool IsEqual(double x1, double x2)
{
    const double EPS = 1e-9;
    return fabs(x1 - x2) < EPS;
}

void PrintEquation(const struct Coeffs* coeffs)
{
    printf(RED "\n\t ");
    if (IsEqual(coeffs->a, 0))
    {
        if (IsEqual(coeffs->b, 0))
        {
            printf("0 ");                    // 0
        }
        else if (IsEqual(coeffs->b, -1))
        {
            printf("-x ");                   // -x
        }
        else if (IsEqual(coeffs->b, 1))
        {
            printf("x ");                    // x
        }
        else
        {
            printf("%gx ", coeffs->b);      // bx
        }

        printf("= %g" CLEANER, -coeffs->c);     // = -c

        return;
    }
    else if (IsEqual(coeffs->a, -1))
    {
        printf("-x^2 ");                     // -x^2
    }
    else if (IsEqual(coeffs->a, 1))
    {
        printf("x^2 ");                      // x^2
    }
    else
    {
        printf("%gx^2 ", coeffs->a);        // ax^2
    }
    if (IsEqual(coeffs->b, 0))
    {
    }
    else if (IsEqual(coeffs->b, -1))
    {
        printf("- x ");                      // - x
    }
    else if (IsEqual(coeffs->b, 1))
    {
        printf("+ x ");                      // + x
    }
    else
    {
        if (coeffs->b > 0)
        {
            printf("+ ");                    // + bx
        }
        else
        {
            printf("- ");                    // - bx
        }
        printf("%gx ", fabs(coeffs->b));
    }

    printf("= %g" CLEANER, -coeffs->c);     // = -c
}

int MyScan(FILE* fp, double* x)
{
    int restOfLine = getc(fp);
    if (restOfLine == '\n') return 10;
    else ungetc(restOfLine, fp);

    if (fscanf(fp, "%lg", x) == 0)
    {
        restOfLine = getc(fp);

        while (restOfLine == ' ')
        {
            restOfLine = getc(fp);
        }
        if (restOfLine == EOF)
        {
            return 30;
        }
        while (restOfLine != '\n' && restOfLine != EOF)
        {
            restOfLine = getc(fp);
        }

        if (restOfLine == EOF)
        {
            return 30;
        }
        else
        {
            return 10;
        }
    }

    restOfLine = getc(fp);

    while (restOfLine == ' ')
    {
        restOfLine = getc(fp);
    }

    if (restOfLine == EOF)
    {
        return 30;
    }
    else if (restOfLine == '\n')
    {
        return 10;
    }
    else
    {
        ungetc(restOfLine, fp);
        return 1;
    }
}

int FscanCoeffs(FILE* fp, struct Coeffs* coeffs, struct Roots* rootsRef)
{
    assert(coeffs);

    int nVarsEntered = 0;
    //nVarsEntered = fscanf(fp, "%lg%lg%lg%lg%lg%d", &coeffs->a, &coeffs->b, &coeffs->c, &rootsRef->x1, &rootsRef->x2, (int*)&rootsRef->rootsCount);

    nVarsEntered += MyScan(fp, &coeffs->a);
    if (nVarsEntered == 1) nVarsEntered += MyScan(fp, &coeffs->b);
    if (nVarsEntered == 2) nVarsEntered += MyScan(fp, &coeffs->c);
    if (nVarsEntered == 3) nVarsEntered += MyScan(fp, &rootsRef->x1);
    if (nVarsEntered == 4) nVarsEntered += MyScan(fp, &rootsRef->x2);
    if (nVarsEntered == 5)
    {
        //nVarsEntered += MyScan(fp, (int*)&rootsRef->rootsCount);
        int restOfLine = 0;
        if (fscanf(fp, "%d", (int*)&rootsRef->rootsCount) == 0)
        {
            //ungetc((int)&rootsRef->rootsCount, fp);
            restOfLine = getc(fp);
            while (restOfLine == ' ')
            {
                restOfLine = getc(fp);
            }
            if (restOfLine == EOF)
            {
                return 0;
            }

            while (restOfLine != '\n' && restOfLine != EOF)
            {
                restOfLine = getc(fp);
            }

            if (restOfLine == EOF)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        restOfLine = getc(fp);

        while (restOfLine == ' ')
        {
            restOfLine = getc(fp);
        }

        if (restOfLine == EOF)
        {
            ungetc(restOfLine, fp);
            return 2;
        }
        else if (restOfLine == '\n')
        {
            return 2;
        }
        while (restOfLine != '\n' && restOfLine != EOF)
        {
            restOfLine = getc(fp);
        }

        if (restOfLine == '\n')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //printf("\nnveCR = %d\n", nVarsEntered);
    if (nVarsEntered >= 30) return 0;
    //if (nVarsEntered == 6) return 2;
    return 1;

    /*
    int restOfLine = getc(fp);

    printf("\n\n\nnve = %d, rol = %d", nVarsEntered, restOfLine);

    if (nVarsEntered == 6 && restOfLine == '\n')  return 2;
    if (nVarsEntered == EOF || restOfLine == EOF)
    {
        return 0;
    }

    while (restOfLine == ' ')
    {
        restOfLine = getc(fp);
    }

    if (restOfLine == EOF)
    {
        return 0;

    }
    else if (restOfLine == '\n')
    {
        return 2;

    }
    else
    {
        while (restOfLine != '\n' && restOfLine != EOF)
        {
            restOfLine = getc(fp);
        }

        if (restOfLine == '\n')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }*/
}

void Test()
{
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

        switch(FscanCoeffs(fp, &coeffs, &rootsRef))
        {

            case 0:
                return;
            case 1:
                printf(RED_UNDER_LINE "\nTest %2d !ERROR!" CLEANER, testsAll);
                printf(RED " The coefficients are entered incorrectly!" CLEANER);
                break;
            case 2:
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
                    printf(RED_UNDER_LINE "\nTest %2d !ERROR!" CLEANER, testsAll);
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

    printf("\n" YELLOW "\nPassed %d tests out of %d!" CLEANER "\n", testsPassed, testsAll);
}
