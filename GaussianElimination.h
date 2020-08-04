//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_GAUSSIANELIMINATION_H
#define NUMERICALANALYSIS_GAUSSIANELIMINATION_H

#include "Matrix.h"
#include "Vector.h"

class GaussianElimination {
private:
    Matrix base_A;
    Vector base_b;
    Matrix A;
    Vector b;
    Vector x;
public:
    GaussianElimination();
    GaussianElimination(Matrix A, Vector b);
    void forward_elimination(bool debug);
    void backward_substitution(bool debug);
    Vector get_solution();
};


#endif //NUMERICALANALYSIS_GAUSSIANELIMINATION_H
