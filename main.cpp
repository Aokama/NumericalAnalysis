#include "NewtonMethod.h"
#include <math.h>

double f(double x){
    return pow(x, 2) - 3;
}

double df(double x){
    return 2 * x;
}

int main() {

    NewtonMethod nm = NewtonMethod(f, df);
    nm.set_initial_value(0.0);
    nm.set_convergence_condition(1.0e-12);
    nm.run(500, ConvergenceDetectionMethod::RESIDUAL);

    return 0;
}
