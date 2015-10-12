//
// Created by danilo on 11/10/15.
//


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "poly.h"

#ifndef M_PI
#define M_PI acos(-1.0)
#endif

static double fatorial(unsigned long n) {
    double res = 1.0;
    for(n;n > 0;n--) {
        res = res * n;
    }
    return res;
}
static double calcError(int n, double a, double b) {
    double p1,p2;
    p1 = pow((b-a)/2, n)/ pow(2, n-1);
    p2 = 1/ fatorial((unsigned long)n);
    return p1 * p2;
}

int main(void)
{
    int i;
    double libres, newtonres, lagrangeres;
    Sample* samp          = Chebyshev(6, 0, M_PI / 2, cos); // Item (A)
    double* denominadores = LagrangeCompute(samp); // Item(B)
    double* coeficientes  = NewtonCompute(samp); // Item (c)
    double max_err = calcError(6, 0, M_PI/2);

    double points[] = {
            0,
            M_PI / 16,
            M_PI / 15.3,
            M_PI / 15,
            M_PI / 14.7061,
            M_PI / 14,
            M_PI / 13.8,
            M_PI / 13.2961,
            M_PI / 13,
            M_PI / 12.447,
            M_PI / 12,
            M_PI / 11.5,
            M_PI / 11,
            M_PI / 10.384,
            M_PI / 10,
            M_PI / 9.357,
            M_PI / 9,
            M_PI / 8.6,
            M_PI / 8,
            M_PI / 7.8,
            M_PI / 7.1,
            M_PI / 7,
            M_PI / 6.5,
            M_PI / 6,
            M_PI / 5.50098,
            M_PI / 5,
            M_PI / 4.8,
            M_PI / 4.3,
            M_PI / 4,
            M_PI / 3.4,
            M_PI / 3,
            M_PI / 2.19234,
            M_PI / 2.5,
            M_PI / 2.8,
            M_PI / 2
    };

    printf("Iniciando testes do lab6!\n");
    for (i=0; i < sizeof(points)/sizeof(double); i++) {
        libres = cos(points[i]);
        lagrangeres = LagrangeEval(samp, denominadores, points[i]);
        newtonres = NewtonEval(samp, coeficientes, points[i]);
        printf("\tcos(%lf) == %lf \n", points[i], libres);
        printf("\tLagrange para %lf: %lf \t==> erro: %lf \n", points[i], lagrangeres, fabs(lagrangeres-libres));
        printf("\tNewton para %lf: %lf \t==>  erro: %lf \n", points[i], newtonres, fabs(newtonres-libres));
        printf(" ================ \n\n");
    }

    Sample_Destroy(samp);
    free(denominadores);
    free(coeficientes);




    printf("\nErro máximo: %lf!\n", max_err);

    printf("\nFinalizando testes do lab6!\n");
    return 0;
}

#undef M_PI