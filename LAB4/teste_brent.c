#include <stdio.h>
#include <math.h>
#include "brent.h"

double test_func_1(double x)
{
    return 4 * cos(x) - exp(2 * x);
}

double test_func_2(double x)
{
    return x / 2.0 - tan(x);
}

double test_func_3(double x)
{
    return 1 - x * log(x + 20);
}

double test_func_4(double x)
{
    return pow(2, x) - 3 * x;
}

double test_func_5(double x)
{
    return pow(x, 3) + x - 1;
}

int main(void)
{
    printf("Testes: ...\n");
    printf("\t1 = 0 em x = %f\n\n", brent(-1, 1, 6, test_func_1));
    printf("\tf2 = 0 em x = %f\n\n", brent(-1, 1, 6, test_func_2));
    printf("\tf3 = 0 em x = %f\n\n", brent(-1, 1, 6, test_func_3));
    printf("\tf4 = 0 em x = %f\n\n", brent(-1, 1, 6, test_func_4));
    printf("\tf5 = 0 em x = %f\n\n", brent(-1, 1, 6, test_func_5));
    printf("\nFim!");

    return 0;
}
