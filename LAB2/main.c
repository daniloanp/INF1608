#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INTERACTIONS 12

double calcError(double a, double b, int interactions) {
    return (b - a) / pow(2.0, interactions);
}

double sign(double a) {
    return a / fabs(a);
}

double bissecao(double a, double b, int p, double (*f) (double x)) {
    double precision = .5 * pow(10, -p);
    int i = 0;
    double c;
    while ((b-a)/2 > precision) {
         c = (a+b)/2; // new midpoint

         printf("a: %lf,  b:%lf,  c: %lf\n", a,b,c);
        if (f(c) ==0 || (b-a)/2 <= precision) {

            break;
        }
        if (f(a)*f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        i++;
    }
    double er = calcError(a, b, i);
    printf("erro %lf\n, interações:%d\n", er, i);

    return (a+b)/2;
}

double f(double x) {
    return sin(x) - pow(x, 3);
}

int main(void) {
    printf("\nResultado: %lf\n", bissecao(0.5, 1.5, 6, f));
    return 0;
}
