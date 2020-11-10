//
// Created by Aokama on 2020/08/04.
//

#include "GaussianElimination.h"

#include <utility>
#include <math.h>

GaussianElimination::GaussianElimination() = default;

GaussianElimination::GaussianElimination(Matrix A, Vector b) {
    this->base_A = std::move(A);
    this->base_b = std::move(b);
    this->A = this->base_A;
    this->b = this->base_b;
    this->x = Vector(this->base_b.get_dimension());
}

void GaussianElimination::forward_elimination(bool pivoting, bool debug) {
    int n = A.get_dimension().get_row();

    for(int k = 1; k <= n - 1; k++){
        if(pivoting){
            int max_row = k;
            for(int s = k + 1; s <= base_A.get_dimension().get_row(); s++){
                if(abs(A.at(s, k)) > abs(A.at(max_row, max_row))){
                    max_row = s;
                }
            }
            A.flip_row(k, max_row);
            b.flip(k, max_row);
        }
        for(int i = k + 1; i <= n; i++){
            double prop = (A.at(i, k) / A.at(k, k));
            for(int j = k + 1; j <= n; j++){
                A.set(i, j, (A.at(i, j) - prop * A.at(k, j)));
            }
            b.set(i, (b.at(i) - prop * b.at(k)));
        }
    }
    if(debug){
        A.show2d("[GaussianElimination] Matrix A after FEP applied");
        b.show2d("[GaussianElimination] Vector b after FEP applied");
    }
}

void GaussianElimination::backward_substitution(bool debug) {
    int n = A.get_dimension().get_row();
    for(int k = n; k >= 1; k--){
        double sum = 0.0;
        for(int j = k + 1; j <= n; j++){
            sum += A.at(k, j) * x.at(j);
        }
        x.set(k, (1 / A.at(k, k)) * (b.at(k) - sum));
    }
    if(debug){
        A.show2d("[GaussianElimination] Matrix A after BSP applied");
        b.show2d("[GaussianElimination] Vector b after BSP applied");
    }
}

Vector GaussianElimination::get_solution() {
    return x;
}
