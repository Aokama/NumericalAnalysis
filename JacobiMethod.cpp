//
// Created by Aokama on 2020/08/19.
//

#include "JacobiMethod.h"

#include <stdio.h>

JacobiMethod::JacobiMethod() = default;

JacobiMethod::JacobiMethod(Matrix A, Vector b) {
    this->A = std::move(A);
    this->b = std::move(b);
}

void JacobiMethod::set_initial_vector(Vector x) {
    this->x = std::move(x);
    this->x_old = this->x;
}

void JacobiMethod::set_convergence_condition(double epsilon) {
    this->epsilon = epsilon;
}

void JacobiMethod::run(int max_iteration, bool is_debug) {
    int n = A.get_dimension().get_row();
    for(int m = 1; m <= max_iteration; m++){
        x_old = x;
        for(int i = 1; i <= n; i++){
            double sum = 0.0;
            for(int j = 1; j <= n; j++){
                if(i != j){
                    sum += A.at(i, j) * x_old.at(j);
                }
            }
            x.set(i, (1.0 / A.at(i, i)) * (b.at(i) - sum));
        }
        /*Success*/
        if(((x_old - x).norm(0) / x.norm(0)) <= epsilon){
            if(is_debug){
                printf("Iteration took : %d\n", m);
            }
            break;
        }
        /*Flown*/
        if(m == max_iteration){
            printf("Did not converged in %d times iteration\n", max_iteration);
            printf("Unless you ensure the solution is reasonable, the solution seems wrong.\n");
        }
    }
}

Vector JacobiMethod::get_solution() {
    return x;
}

