#include "io.h"
#include "solve.h"
#include "tests.h"
                                            //maketutorial -
#include <stdio.h>

/**
    \authors Ludmila Stemp
    \date 24.08.2023
*/

int main()
{
#ifdef DEBUG
    Test();
#else
    Coeffs coeffs = { .a = 0, .b = 0, .c = 0 };
    Roots roots = { .x1 = 0, .x2 = 0, .rootsCount = ROOTS_ZERO };

    printf("Please enter the coefficients:\n");
    while (true)
    {
        ScanReturn scanStatus = ScanCoeff(&coeffs);
        if (scanStatus == TERMINATE)
        {
            return 0;
        }
        if (scanStatus == OK)
        {
            break;
        }
    }

    SolveQuadraticEquation(&coeffs, &roots);

    PrintRoots(&roots);

#endif
    return 0;
}
