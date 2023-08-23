#include "header.h"
#include "io.h"
#include "solve.h"
#include "tests.h"

//1. вывод проверки разным цветом
//2. два файла bat
//3. g++ -DDEBUG main.cpp io.cpp solve.cpp tests.cpp
//
//5. убрать прототипы функций
//6. разложить файл header
//7. проверка ввода

#define DEBUG

//int Test();

int main()
{
#ifdef DEBUG
    Test();
#endif

    struct Coeffs coeffs = { };
    struct Roots roots = { };

    ScanCoeff(&coeffs.a);
    ScanCoeff(&coeffs.b);
    ScanCoeff(&coeffs.c);

    SolveQuadraticEquation(&coeffs, &roots);

    PrintRoots(&roots);

    return 0;
}
