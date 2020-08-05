//
// Created by Aokama on 2020/08/05.
//

#include "CholeskyDecomposition.h"
#include <stdio.h>
#include <math.h>

CholeskyDecomposition::CholeskyDecomposition() = default;

CholeskyDecomposition::CholeskyDecomposition(Matrix A) {
    if(!A.is_symmetric()){
        printf("[CholeskyDecomposition] Non symmetric matrix cannot be used for initialization.");
        A.show2d("Input A");
        this-> A = Matrix();
        this-> L = Matrix();
    }
    else{
        this->A = A;
        this->L = Matrix::zeros(A.get_dimension());
    }
}

Matrix CholeskyDecomposition::decompose() {
    int n = A.get_dimension().get_row();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                double sum = 0.0;
                for(int k = 1; k <= i - 1; k++){
                    sum += pow(L.at(i, k), 2);
                }
                L.set(i, i, (pow(A.at(i, i) - sum, 1.0 / 2)));
            }
            else{
                if(j <= i && i <= n){
                    double sum = 0.0;
                    for(int k = 1; k <= j - 1; k++){
                        sum += (L.at(i, k) * L.at(j, k));
                    }
                    L.set(i, j, ((1.0/ L.at(j, j)) * (A.at(i, j) - sum)));
                }
                else{
                    L.set(i, j, 0.0);
                }
            }
        }
    }
    return L;
}
