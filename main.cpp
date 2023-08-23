#include "header.h"
#include "io.h"
#include "solve.h"
#include "tests.h"

//1. ����� �������� ������ ������
//2. ��� ����� bat
//3. g++ -DDEBUG main.cpp io.cpp solve.cpp tests.cpp
//
//5. ������ ��������� �������
//6. ��������� ���� header
//7. �������� �����

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
