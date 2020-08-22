//
// Created by Aokama on 2020/08/19.
//

#include "PowerMethod.h"

#include <stdio.h>
#include <math.h>

PowerMethod::PowerMethod() = default;

PowerMethod::PowerMethod(Matrix A) {
    this->A = std::move(A);
}

void PowerMethod::set_initial_vector(Vector x) {
    this->x = std::move(x);
    this->x_old = this->x;
}

void PowerMethod::set_convergence_condition(double epsilon) {
    this->epsilon = epsilon;
}

void PowerMethod::run(int max_iteration, bool is_debug) {
    int n = A.get_dimension().get_row();
    for(int k = 1; k <= max_iteration; k++){
        x_old = x;
        lambda_old = lambda;
        double norm = x_old.norm(2);
        for(int i = 1; i <= n; i++){
            x_old.set(i, (1 / norm) * x_old.at(i));
        }
        x = A * x_old;
        for(int l = 1; l <= n; l++){
            if(x_old.at(l) != 0){
                lambda = (x.at(l) / x_old.at(l));
                break;
            }
        }
        /*Success*/
        if(abs(lambda - lambda_old) / abs(lambda) < epsilon){
            if(is_debug){
                printf("Iteration took : %d\n", k);
            }
            break;
        }
        /*Flown*/
        if(k == max_iteration){
            printf("Did not converged in %d times iteration\n", max_iteration);
            printf("Unless you ensure the solution is reasonable, the solution seems wrong.\n");
        }
    }
}

Vector PowerMethod::get_eigen_vector() {
    return x;
}

double PowerMethod::get_spectral_radius() {
    return abs(lambda);
}

