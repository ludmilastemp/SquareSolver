#include <assert.h>

#include "infile.h"
#include "struct.h"

ScanReturn MyScan(FILE* fp, double* x)
{
    assert(fp);
    assert(x);

    int restOfLine = getc(fp);
    if (restOfLine == '\n')
    {
        return SCAN_INCORRECT;
    }
    else ungetc(restOfLine, fp);

    if (fscanf(fp, "%lg", x) == 0)
    {
        restOfLine = getc(fp);

        while (restOfLine != '\n' && restOfLine != EOF)
        {
            restOfLine = getc(fp);
        }

        if (restOfLine == EOF)
        {
            return SCAN_EOF;
        }
        else
        {
            return SCAN_INCORRECT;
        }
    }

    restOfLine = getc(fp);

    while (restOfLine == ' ')
    {
        restOfLine = getc(fp);
    }

    if (restOfLine == EOF)
    {
        return SCAN_EOF;
    }
    else if (restOfLine == '\n')
    {
        return SCAN_INCORRECT;
    }
    else
    {
        ungetc(restOfLine, fp);
        return SCAN_CORRECT;
    }
}

ScanReturn FscanCoeffs(FILE* fp, struct Coeffs* coeffs, struct Roots* rootsRef)
{
    assert(fp);
    assert(coeffs);
    assert(rootsRef);

    int nVarsEntered = 0;

    nVarsEntered += MyScan(fp, &coeffs->a);
    if (nVarsEntered == 2) nVarsEntered += MyScan(fp, &coeffs->b);
    if (nVarsEntered == 4) nVarsEntered += MyScan(fp, &coeffs->c);
    if (nVarsEntered == 6) nVarsEntered += MyScan(fp, &rootsRef->x1);
    if (nVarsEntered == 8) nVarsEntered += MyScan(fp, &rootsRef->x2);
    if (nVarsEntered == 10)
    {
        int restOfLine = 0;
        if (fscanf(fp, "%d", (int*)&rootsRef->rootsCount) == 0)
        {
            restOfLine = getc(fp);

            while (restOfLine != '\n' && restOfLine != EOF)
            {
                restOfLine = getc(fp);
            }

            if (restOfLine == EOF)
            {
                return SCAN_EOF;
            }
            else
            {
                return SCAN_INCORRECT;
            }
        }

        restOfLine = getc(fp);

        while (restOfLine != '\n' && restOfLine != EOF)
        {
            restOfLine = getc(fp);
        }

        if (restOfLine == '\n')
        {
            return SCAN_CORRECT;
        }
        else
        {
            return SCAN_EOF;
        }
    }
    if (nVarsEntered % 2 == 0) return SCAN_EOF;
    return SCAN_INCORRECT;
}
