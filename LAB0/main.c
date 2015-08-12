
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


//create to make tests easier
void mat_copy(double** matDest, double* vetSource, int m, int n)
{
    int i,j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            matDest[i][j] = vetSource[i*(n) + j];
        }
    }
}

void print_vet(double* vet,  int len) 
{
    int i;
    printf("[");
    for (i=0; i < len; i++) {
        printf("%f", vet[i]);
        if (i+1 != len) {
            printf(", ");
        }
    }
    printf("]");
}

void print_mat(double** mat, int m, int n) 
{
    int i;
    printf("{");
    for (i=0; i < m; i++) {
        printf("\n\t");
        print_vet(mat[i], n);

    }
    printf("\n}\n");
}

int main(void) 
{
    double** A = mat_cria(3,3);
    double** B = mat_cria(3,2);
    double** C = mat_cria(3,2);
    double** TA = mat_cria(3,3);
    double** TB = mat_cria(2,3);
    
    double *w = calloc(sizeof(double), 3);
    
    mat_copy(A, (double []){0.0, 0.1, 0.2, 1.0, 1.1, 1.2, 2.0 ,2.1 , 2.2}, 3,3);
    
    mat_copy(B, (double []){3.0, 3.1, 3.2, 6.0, 6.1, 6.2}, 3, 2);

    
    mat_transposta(3,3, A, TA);
    mat_transposta(3,2, B, TB);
    
    printf("Matriz A:\n");
    print_mat(A, 3, 3);
    printf("Matriz TA (transposta de A):\n");
    print_mat(TA, 3, 3);
    
    printf("\nMatriz B:\n");
    print_mat(B, 3, 2);
    printf("Matriz TB (transposta de B):\n");
    print_mat(TB, 2, 3);
    
    
    
    printf("\nVetor v:\n");
    print_vet((double []){14.006, 11.143}, 2);
    printf("\n");
    
    printf("\nVetor w := B x v:\n");
    mat_multv(3,2, B, (double []){14.006, 11.143}, w);
    print_vet(w, 3);
    printf("\n");
    
    printf("\nVetor C := A x B:\n");
    mat_multm(3, 3, 2 , A, B, C);
    print_mat(C, 3,2);
    printf("\n");
    
    
    mat_libera(3,A);
    mat_libera(3,B);
    mat_libera(3,C);
    mat_libera(3,TA);
    mat_libera(2,TB);
    
    return 0;
    

}

