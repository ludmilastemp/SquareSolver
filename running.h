#ifndef __RUNNING__
#define __RUNNING__

const int MAX_STRING_LENGTH = 250;

void BinInConsole(FILE* fp);

int TxtInBin(FILE* fp, FILE* fpBin);

char DecToHex(int x);

int TxtInBinTxt(FILE* fp, FILE* fpBinTxt);

#endif
