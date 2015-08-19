#include <stdio.h>
#include <math.h>

double fcos (double x);




const double step = M_PI/30.0;

void parte2() {
    printf("\n\n ===== Task 2 ====\n");
    printf("\t %.16g\n\n", 2.3 - 2.0 - 0.3);
}

int main(void) {
    double x;
    double max_err_dom = -INFINITY;
    double max_err_im = -INFINITY;
    
    
    for (x = 0.0; x <= M_PI+step/3; x += step) {
        printf("fcos: %lf;\n", fcos(x));
        printf("cos: %lf;\n", cos(x));
        printf("diff: %lf;\n", fcos(x)-cos(x));
        printf("\n====== x =====\n");
        if (fcos(x)-cos(x) > max_err_im) {
            max_err_im = fcos(x)-cos(x);
            max_err_dom = x;
        }
    }
    
    printf("\n Max err:%lf em x = %lf\n", max_err_im, max_err_dom);
    parte2();
    
    
    return 0;
}
