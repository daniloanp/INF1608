#include <stdio.h>
#include <math.h>


#define senPI_2  1;
#define cosPI_2  0;

double x0 = M_PI/2;
double f_x0 = cosPI_2;
double df_x0 = -senPI_2;
double ddf_x0 = -cosPI_2;
double dddf_x0 = senPI_2;
double ddddf_x0 = cosPI_2;




double fcos (double x) {

    return f_x0 
           + df_x0 * (x - x0) 
           + (ddf_x0/2) * pow((x - x0),2) 
           + (dddf_x0/6) * pow((x-x0),3)
           + (ddddf_x0/24) * pow((x-x0),4);
}




