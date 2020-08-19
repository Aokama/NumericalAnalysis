//
// Created by Aokama on 2020/08/19.
//

#ifndef NUMERICALANALYSIS_POWERMETHOD_H
#define NUMERICALANALYSIS_POWERMETHOD_H

#include "Matrix.h"
#include "Vector.h"

class PowerMethod {
private:
    Matrix A;
    Vector x;
    Vector x_old;
    double lambda = 1.0;
    double lambda_old = 1.0;
    double epsilon = 1.0e-8;
    double radius =0.0;
public:
    PowerMethod();
    PowerMethod(Matrix A);
    void set_initial_vector(Vector x);
    void set_convergence_condition(double epsilon);
    void run(int max_iteration, bool is_debug);
    Vector get_eigen_vector();
    double get_spectral_radius();
};


#endif //NUMERICALANALYSIS_POWERMETHOD_H
