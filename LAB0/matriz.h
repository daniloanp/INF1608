#include <stdlib.h>

#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

//assert: m * n will not be as greater to an overflow
double** mat_cria(int m, int n);

//assert: A is a valid pointer to a double**
//assert: let i:=0...m,  A[i] is a valid pointer to a double*
void mat_libera(int m, double** A);

//assert: A and T are allocated and same size;
void mat_transposta(int m, int n, double** A, double** T);


//assert: A is a valid pointer to (double**)
//assert: A is a allocated m x n matrix (double**)
//assert: v is a allocated vector of size n
//assert: w is a allocated vector of size m
void mat_multv(int m, int n, double** A, double* v, double* w);

//assert: A and B are valid pointers to some double**
//assert: let i:=0...m,  A[i] is a valid pointer to a double*
//assert: let i:=0...n,  B[i] is a valid pointer to a double*
void mat_multm(int m, int n,int q, double** A, double** B, double** C);
#endif
