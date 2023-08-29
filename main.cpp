#include <stdio.h>

#include "io.h"
#include "solve.h"
#include "tests.h"
#include "draw_cats.h"
#include "struct.h"

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

    DrawCats1();

    printf("Please enter the meowfficients:\n");
    while (true)
    {
        ScanReturn scanStatus = ScanCoeff(&coeffs);
        if (scanStatus == SCAN_TERMINATE)
        {
            return 0;
        }
        if (scanStatus == SCAN_CORRECT)
        {
            break;
        }
    }

    SolveQuadraticEquation(&coeffs, &roots);

    PrintRoots(&coeffs, &roots);

#endif
    return 0;
}
