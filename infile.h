#ifndef __INFILE__
#define __INFILE__

#include <stdio.h>
#include "struct.h"

ScanReturn MyScan(FILE* fp, double* x);

ScanReturn FscanCoeffs(FILE* fp, struct Coeffs* coeffs, struct Roots* rootsRef);

#endif
