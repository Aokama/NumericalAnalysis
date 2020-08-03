//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_NEWTONMETHOD_H
#define NUMERICALANALYSIS_NEWTONMETHOD_H

enum ConvergenceDetectionMethod{
    ERROR,
    RELATIVE_ERROR,
    RESIDUAL
};

class NewtonMethod {
private:
    double (*function)(double){};
    double (*dfunction)(double){};
    double initial_value = 0.0;
    double x = 6542165484651;
    double x_old = 0.0;
    double convergence_condition = 1.0e-12;
    double approx_root = 0.0;
    int repeated_count = 0;
public:
    NewtonMethod();
    NewtonMethod(double (*function)(double), double (*dfunction)(double));
    void set_initial_value(double value);
    void set_convergence_condition(double condition);
    void run(int max_iteration, ConvergenceDetectionMethod method);
    double get_approx_root();
};


#endif //NUMERICALANALYSIS_NEWTONMETHOD_H
