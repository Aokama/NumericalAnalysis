//
// Created by Aokama on 2020/08/05.
//

#ifndef NUMERICALANALYSIS_CHOLESKYDECOMPOSITION_H
#define NUMERICALANALYSIS_CHOLESKYDECOMPOSITION_H

#include "Matrix.h"

class CholeskyDecomposition {
private:
    Matrix A;
    Matrix L;
public:
    CholeskyDecomposition();
    CholeskyDecomposition(Matrix A);
    Matrix decompose();
};


#endif //NUMERICALANALYSIS_CHOLESKYDECOMPOSITION_H
