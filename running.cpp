#include <stdio.h>
#include <assert.h>

#include "running.h"
            //krya
int main()
{
#ifdef WRITEBINTXT
    FILE *fp = fopen("running.txt", "r");
    assert(fp);

    FILE *fpBinTxt = fopen("running_bintxt.txt", "w");
    assert(fpBinTxt);

    if(!TxtInBinTxt(fp, fpBinTxt)) printf("OK!");

    return 0;
#endif

#ifdef WRITEBIN
    FILE *fp = fopen("running.txt", "r");
    assert(fp);

    FILE *fpBin = fopen("running_bin.txt", "wb");
    assert(fpBin);

    if(!TxtInBin(fp, fpBin)) printf("OK!");

    return 0;
#endif

#ifdef PRINTBIN
    FILE *fpBin = fopen("running_bin.txt", "rb");
    assert(fpBin);

    BinInConsole(fpBin);

    return 0;
#endif
}

void BinInConsole(FILE* fp)
{
    int symbol = 0;
    int quantity = 0;

    while(true)
    {
        symbol = getc(fp);
        if (symbol == EOF || quantity == EOF) break;
        if (symbol == 1)
        {
            while (true)
            {
                symbol = getc(fp);
                quantity = getc(fp);

                for(int i = 0; i < quantity; ++i)
                {
                    printf("%c", symbol);
                }

                if (symbol == EOF || quantity == EOF) break;
                if (symbol == 10 || symbol == 13) break;
            }
        }
        else
        {
            while (true)
            {
                symbol = getc(fp);
                printf("%c", symbol);

                if (symbol == EOF) break;
                if (symbol == 10 || symbol == 13) break;
            }
        }
    }
}

int TxtInBin(FILE* fp, FILE* fpBin)
{
    int symbol = 0;
    int symbolTemp = 0;
    int symbolSameCount = 1;

    int str[MAX_STRING_LENGTH] = { 0 };
    int strBin[MAX_STRING_LENGTH] = { 0 };

    int toIndex = 0;
    int toIndexBin = 0;

    symbol = getc(fp);
    while(true)
    {
        symbolTemp = getc(fp);
        str[toIndex++] = symbolTemp;

        if (symbolTemp == EOF) return 0;
        else if (symbolTemp == symbol)
        {
            ++symbolSameCount;
        }
        else if (symbolTemp != '\n')
        {
            strBin[toIndexBin++] = symbol;
            strBin[toIndexBin++] = symbolSameCount;

            symbol = symbolTemp;
            symbolSameCount = 1;
        }
        else
        {
            strBin[toIndexBin++] = symbol;
            strBin[toIndexBin++] = symbolSameCount;

            assert(symbolSameCount <= 255);

            strBin[toIndexBin++] = '\n';
            strBin[toIndexBin++] = 1;

            if (toIndex <= toIndexBin)
            {
                fprintf(fpBin, "%c", 0);
                for (int i = 0; i < toIndex; ++i)
                {
                    fprintf(fpBin, "%c", str[i]);

                    assert(strBin[i] != -1);
                    assert(strBin[i] != 255);
                }
            }
            else
            {
                fprintf(fpBin, "%c", 1);
                for (int i = 0; i < toIndexBin; ++i)
                {
                    fprintf(fpBin, "%c", strBin[i]);

                    assert(strBin[i] != -1);
                    assert(strBin[i] != 255);
                }
            }

            symbol = getc(fp);
            symbolSameCount = 1;

            toIndex = 0;
            toIndexBin = 0;

            str[toIndex++] = symbol;
        }
    }

    return 0;
}

char DecToHex(int x)
{
    char mass[] = {"0123456789ABCDEF"};

    assert(0 <= x && x < 16);

    return mass[x];
}

int TxtInBinTxt(FILE* fp, FILE* fpBinTxt)
{
    int symbol = 0;
    int symbolTemp = 0;
    int symbolSameCount = 1;

    int str[MAX_STRING_LENGTH] = { 0 };
    int strBinTxt[MAX_STRING_LENGTH] = { 0 };

    int toIndex = 0;
    int toIndexBinTxt = 0;

    symbol = getc(fp);

    while (true)
    {
        symbolTemp = getc(fp);
        str[toIndex++] = symbolTemp;

        if (symbolTemp == EOF) return 0;
        else if (symbolTemp == symbol)
        {
            ++symbolSameCount;
        }
        else if (symbolTemp != '\n')
        {
            strBinTxt[toIndexBinTxt++] = symbol;
            strBinTxt[toIndexBinTxt++] = symbolSameCount;

            symbol = symbolTemp;
            symbolSameCount = 1;
        }
        else
        {
            strBinTxt[toIndexBinTxt++] = symbol;
            strBinTxt[toIndexBinTxt++] = symbolSameCount;

            assert(symbolSameCount <= 255);

            strBinTxt[toIndexBinTxt++] = '\n';
            strBinTxt[toIndexBinTxt++] = 1;

            if (toIndex <= toIndexBinTxt)
            {
                fprintf(fpBinTxt, "0 ");

                for (int i = 0; i < toIndex; ++i)
                {
                    fprintf(fpBinTxt, "%c", DecToHex(str[i] / 16));
                    fprintf(fpBinTxt, "%c ", DecToHex(str[i] % 16));

                    assert(strBinTxt[i] != -1);
                    assert(strBinTxt[i] != 255);
                }
                fprintf(fpBinTxt, "\n");
            }
            else
            {
                fprintf(fpBinTxt, "1 ");

                for (int i = 0; i < toIndexBinTxt; ++i)
                {
                    fprintf(fpBinTxt, "%c", DecToHex(strBinTxt[i] / 16));
                    fprintf(fpBinTxt, "%c ", DecToHex(strBinTxt[i] % 16));

                    assert(strBinTxt[i] != -1);
                    assert(strBinTxt[i] != 255);
                }
                fprintf(fpBinTxt, "\n");
            }

            symbol = getc(fp);
            symbolSameCount = 1;

            toIndex = 0;
            toIndexBinTxt = 0;

            str[toIndex++] = symbol;
        }
    }

    return 0;
}
