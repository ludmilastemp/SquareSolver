#include "io.h"
#include "solve.h"
#include "tests.h"

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
    Roots roots = { .x1 = 0, .x2 = 0, .count_roots = ROOTS_ZERO };

    printf("Please enter the coefficients:\n");
    while (1)
    {
        ScanReturn scan_status = ScanCoeff(&coeffs);
        if (scan_status == TERMIN) return 0;
        if (scan_status == OK) break;
    }

    SolveQuadraticEquation(&coeffs, &roots);

    PrintRoots(&roots);

#endif
    return 0;
}