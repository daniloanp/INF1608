#ifndef BRENT_C
#define BRENT_C

#include <math.h>


static double max_err(int p) {
    return  .5 * pow(10.0, -p);
}

static int condicoes(double x0, double x1, double x2, double fx2, double fxm) {
  double interval = fabs(x1 - x0);
  return fabs(fx2) < fabs(fxm) && 
        ((x2 < 0 && interval / 2 > fabs(x1 - x2)) 
      || (x2 > 0 && interval / 2 > fabs(x0 - x2)) );
}

double brent(double x0, double x1, int p, double (*f) (double x)) {
  double xm, fxm, x2, fx2;
  double maxerr = max_err(p);

  double fx0 = f(x0);
  double fx1 = f(x1);

  do {
    xm = (x0+x1)/2;
    fxm = f(xm);

    // IQI
    x2 = x0 * fx1 * fxm / (fx0 - fx1) / (fx0 - fxm) + 
               x1 * fx0 * fxm / (fx1 - fx0) / (fx1 - fxm) +
               xm * fx0 * fx1 / (fxm - fx0) / (fxm - fx1);
    
    if (!condicoes(x0, x1, x2, fx2, fxm)) {
      //Secante
      x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
      if (!condicoes(x0, x1, x2, fx2, fxm)) {
        //Bissecao
        x2 = xm;
      }
    }

    fx2 = f(x2);

    if (fx0 * fx2 < 0) {
      x1 = x2;
      fx1 = fx2;
    } else {
      x0 = x2;
      fx0 = fx2;
    }

  } while(fabs(fx2) >= maxerr);

  return x2;
}

#endif
