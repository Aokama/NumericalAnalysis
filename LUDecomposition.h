//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_LUDECOMPOSITION_H
#define NUMERICALANALYSIS_LUDECOMPOSITION_H

#include "Matrix.h"
#include "Vector.h"

class LUDecomposition {
private:
    Matrix A;
    Vector b;
    Vector x;
    Vector y;
public:
    LUDecomposition();
    LUDecomposition(Matrix A, Vector b);
    void decompose(bool is_debug);
    Matrix get_L();
    Matrix get_U();
    void run();
    Vector get_solution_vector();
};


#endif //NUMERICALANALYSIS_LUDECOMPOSITION_H
