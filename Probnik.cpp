#include <stdio.h>        //ОНО ДАЖЕ РАБОТАЕТ!!! :)
#include <math.h>         //и без ошибок... вроде...

#define EPS 1e-9 //эпсилон

void QuadraticEquation(double a, double b, double c, double* x1, double* x2);
bool CheckLinearEquation(double a);
void CountingRoot(double b, double c, double* x1);
double Discriminant(double a, double b, double c);
void CountingRoots(double a, double b, double discrim, double* x1, double* x2);

int main(){
    double a; //коэффициент перед х^2
    double b; //коэффициент перед х
    double c; //свободный коэффициент
    double x1; //первый корень
    double x2; //второй корень
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    QuadraticEquation(a, b, c, &x1, &x2);
    return 0;
}

void QuadraticEquation(double a, double b, double c, double* x1, double* x2){
    if (CheckLinearEquation(a)){
        CountingRoot(b, c, x1);
    }
    else{
        double discrim = Discriminant(a, b, c);
        CountingRoots(a, b, discrim, x1, x2);
    }
}

bool CheckLinearEquation(double a){
    if (fabs(a) < EPS) return 1;
    else return 0;
}

void CountingRoot(double b, double c, double* x1){
    if (fabs(b) < EPS) {
        if (fabs(c) < EPS) printf("x = any real");
        else printf("no roots");
        return;
    }
    else *x1 = -c/b;
    if (fabs(*x1) < EPS) *x1 = fabs(*x1);
    printf("x = %.8lf", *x1);
}

double Discriminant(double a, double b, double c){
    return b*b-4*a*c;
}

void CountingRoots(double a, double b, double discrim, double* x1, double* x2){
    if (discrim < 0) {
        printf("no roots");
        return;
    }
    if (discrim < EPS) {
        *x1 = -b/(2*a);
        if (fabs(*x1) < EPS) *x1 = fabs(*x1);
        printf("x = %.8lf", *x1);
        return;
    }
    *x1 = (-b-sqrt(discrim))/(2*a);
    *x2 = (-b+sqrt(discrim))/(2*a);
    if (fabs(*x1) < EPS) *x1 = fabs(*x1);
    if (fabs(*x2) < EPS) *x2 = fabs(*x2);
    printf("x = %.8lf\nx = %.8lf", *x1, *x2);
}

