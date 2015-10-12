//
// Created by danilo on 11/10/15.
//


#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "poly.h"

#ifndef M_PI
#define M_PI acos(-1.0)
#endif
#define PRECISION 15;
#define MAX_ERR 0.5 * pow(10.0, - PRECISION);

static Sample* Sample_New(int n)
{
    Sample* samp = calloc((size_t) n, sizeof(Sample));
    samp->x = calloc((size_t) n, sizeof(double));
    samp->y = calloc((size_t) n, sizeof(double));
    samp->n = n;
    return samp;
}

void Sample_Destroy(Sample* samp)
{
    assert(samp != NULL);
    if (samp->x != NULL) {
        free(samp->x);
    }
    if (samp->y != NULL) {
        free(samp->y);
    }
    free(samp);
}

/**
 * @param n:integer descreve o número de amostras
 * @param a:double_precision descreve o início do intervado fechado de aproximação
 * @param a:double_precision descreve o fim do intervado fechado de aproximação
 *
 */

Sample* Chebyshev(int n, double a, double b, double (* f)(double))
{
    Sample* samp = Sample_New(n);

    int k;

    for (k = 1; k <= n; k++) {
        // first kind degree
        samp->x[n - k] = cos((((2 * k) - 1) * M_PI) / (2.0 * n));
        //affinite transformation
        samp->x[n - k] = .5 * (a + b) + .5 * (b - a) * (samp->x[n - k]);
        // image


        samp->y[n - k] = f(samp->x[n - k]); // nodes
    }

    return samp;
}


double* LagrangeCompute(Sample* s)
{
    int    k, i;
    double xk;
    double* denominadores = calloc((size_t) s->n, sizeof(double));
    for (k = 0; k <= (s->n - 1); k++) {
        xk = s->x[k];
        denominadores[k] = 1;
        for (i = 0; i <= (s->n - 1); i++) {
            if (k != i) {
                denominadores[k] *= (xk - s->x[i]);
            }
        }
    }
    return denominadores;
}


double LagrangeEval(Sample* s, double* den, double x)
{
    double result = .0;
    double numerador;
    int    k, i;

    for (k = 0; k <= (s->n - 1); k++) {
        numerador = 1.0;
        for (i    = 0; i <= (s->n - 1); i++) {
            if (k!=i) {
                numerador *= (x - s->x[i]);
            }
        }
        result += s->y[k] * (numerador / den[k]);
    }

    return result;
}


static double calcCoeficiente(Sample* s, int i, int j)
{
    if (i == j) {
        return s->y[i];
    }
    return (calcCoeficiente(s, i + 1, j) - calcCoeficiente(s, i, j - 1)) / (s->x[j] - s->x[i]);

}

double* NewtonCompute(Sample* s)
{
    double* coeficientes = calloc((size_t) s->n, sizeof(double)); // B's
    int k;
    for (k = 0; k <= (s->n - 1); k++) {
        coeficientes[k] = calcCoeficiente(s, 0, k);
    }
    return coeficientes;
}


double NewtonEval(Sample* s, double* coef, double x)
{
    double result = 0.0;
    double part   = 0.0;
    int    k, i;


    for (k = 0; k <= (s->n - 1); k++) {
        part   = coef[k];
        for (i = 0; i < k; i++) {
            part *= (x - s->x[i]);
        }
        result += part;
    }

    return result;
}


