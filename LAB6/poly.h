//
// Created by danilo on 11/10/15.
//

#ifndef LAB6_INF1608_POLY_C_H
#define LAB6_INF1608_POLY_C_H


typedef struct sample Sample;
struct sample
{
    int n;
    /* número de amostras */
    double* x;
    /* valores x das amostras */
    double* y; /* valores y das amostras */
};

/**
 * 1 - Determinar as `n` amostras de Chebyshev para a aproximação de uma função dada `f` dentro do intervalo `[a, b]`. Os valores de `y(i)` são encontrados usando a função `f`passada como parâmetro. A função deve retornar o tipo Sample dinamicamente alocado e preenchido, seguindo o protótipo:
 */

Sample* Chebyshev(int n, double a, double b, double(* f)(double x));


/**
 * 2 - O polinômio interpolante de Lagrange é dado por:
 *
 * P(n-1)(x) = y(0) * L(0)(x) + ... + y(n-1) * L(n-1)(x)
 *
 * Onde:
 *
 * L(k)(x) = (x - X(0)) ... (x - X(k-1)) * (x - X(k+1)) ... (x - X(n-1))
 *         ----------------------------------------------------------------
 *        (X(k) - X(0) ... (X(k) - X(k-1)) * (X(k) - X(k+1) ... (X(k) - X(n-1))
 *
 * Escreva uma função que receba o conjunto de amostras e determine os denominadores das funções L(k). A função deve receber as amostras e retornar o vetor dos denominadores alocados dinamicamente.
 *
 */

double* LagrangeCompute(Sample* s);


/** Escreve uma função para avaliar o polinômio interpolante de lagrande em um ponto de x dado. A função deve receber como parâmetros as amostras, o vetor de denominadores e o valor de x, retornando o valor do polinômio no ponto x;
 *
 */

double LagrangeEval(Sample* s, double* den, double x);



void Sample_Destroy(Sample* samp);



double* NewtonCompute(Sample* s);

double NewtonEval(Sample *s, double* coef, double x);

#endif //LAB6_INF1608_POLY_C_H
