//
// Created by Aokama on 2020/08/04.
//

#include "LUDecomposition.h"
#include <stdio.h>

LUDecomposition::LUDecomposition() = default;

LUDecomposition::LUDecomposition(Matrix A, Vector b) {
    this->x = Vector(b.get_dimension());
    this->y = Vector(b.get_dimension());
    this->A = A;
    this->b = b;
}

void LUDecomposition::decompose(bool debug) {
    int n = A.get_dimension().get_row();
    //forward_elimination
    for(int k = 1; k <= n - 1; k++){
        for(int i = k + 1; i <= n; i++){
            double alpha = (A.at(i, k) / A.at(k, k));
            A.set(i, k, alpha);
            for(int j = k + 1; j <= n; j++){
                A.set(i, j, (A.at(i, j) - alpha * A.at(k, j)));
            }
        }
    }
    if(debug){
        A.show2d("A");
    }
}

Matrix LUDecomposition::get_L() {
    Matrix L = A;
    for(int i = 1; i <= L.get_dimension().get_row(); i++){
        for(int j = 1; j <= L.get_dimension().get_col(); j++){
            if(i < j){
                L.set(i, j, 0.0);
            }
            else if(i == j){
                L.set(i, j, 1.0);
            }
        }
    }
    return L;
}

Matrix LUDecomposition::get_U() {
    Matrix U = A;
    for(int i = 1; i <= U.get_dimension().get_row(); i++){
        for(int j = 1; j <= U.get_dimension().get_col(); j++){
            if(i > j){
                U.set(i, j, 0.0);
            }
        }
    }
    return U;
}

void LUDecomposition::run() {
    int n = A.get_dimension().get_row();
    //forward_substitution
    for(int k = 1; k <= n; k++){
        double sum = 0.0;
        for(int j = 1; j <= k - 1; j++){
            sum += A.at(k, j) * y.at(j);
        }
        y.set(k, (b.at(k) - sum));
    }
    //backward_substitution
    for(int k = n; k >= 1; k--){
        double sum = 0.0;
        for(int j = k + 1; j <= n; j++){
            sum += A.at(k, j) * x.at(j);
        }
        x.set(k, ((1 / A.at(k, k)) * (y.at(k) - sum)));
    }
}

Vector LUDecomposition::get_solution_vector() {
    return x;
}

