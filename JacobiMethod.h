//
// Created by Aokama on 2020/08/19.
//

#ifndef NUMERICALANALYSIS_JACOBIMETHOD_H
#define NUMERICALANALYSIS_JACOBIMETHOD_H

#include "Matrix.h"
#include "Vector.h"

class JacobiMethod {
private:
    Matrix A;
    Vector b;
    Vector x;
    Vector x_old;
    double epsilon = 1.0e-8;
public:
    JacobiMethod();
    JacobiMethod(Matrix A, Vector b);
    void set_initial_vector(Vector x);
    void set_convergence_condition(double epsilon);
    void run(int max_iteration, bool is_debug);
    Vector get_solution();
};


#endif //NUMERICALANALYSIS_JACOBIMETHOD_H
