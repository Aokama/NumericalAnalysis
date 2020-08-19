//
// Created by Aokama on 2020/08/19.
//

#ifndef NUMERICALANALYSIS_GAUSSSEIDELMETHOD_H
#define NUMERICALANALYSIS_GAUSSSEIDELMETHOD_H

#include "Matrix.h"
#include "Vector.h"

class GaussSeidelMethod {
private:
    Matrix A;
    Vector b;
    Vector x;
    Vector x_old;
    double epsilon = 1.0e-8;
public:
    GaussSeidelMethod();
    GaussSeidelMethod(Matrix A, Vector b);
    void set_initial_vector(Vector x);
    void set_convergence_condition(double epsilon);
    void run(int max_iteration, bool is_debug);
    Vector get_solution();
};


#endif //NUMERICALANALYSIS_GAUSSSEIDELMETHOD_H
