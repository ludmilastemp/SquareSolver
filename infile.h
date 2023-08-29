#ifndef __INFILE__
#define __INFILE__

#include <stdio.h>
#include "struct.h"

/**
    \brief Function reads value from a file
    \details The function reads from the file the number
    \param x pointer to the structure in which the variables being read are stored
    \returns status of the scanf
*/
ScanReturn MyScan(FILE* fp, double* x);

/**
    \brief Function reads values from a file
    \details The function reads from the file the coefficients of the quadratic equation a, b and c and the reference roots
    \param coeffs pointer to the structure in which the variables being read are stored
    \param rootsRef pointer to the structure in which the variables being read are stored
    \returns status of the scanf
*/
ScanReturn FscanCoeffs(FILE* fp, struct Coeffs* coeffs, struct Roots* rootsRef);

#endif
