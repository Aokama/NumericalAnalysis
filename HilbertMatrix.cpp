//
// Created by Aokama on 2020/10/12.
//

#include "HilbertMatrix.h"

Matrix HilbertMatrix::create(int N) const {
    Matrix mat = Matrix(Dimension(N, N));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            mat.set(i, j, 1.0 / (i + j - 1));
        }
    }
    return mat;
}
