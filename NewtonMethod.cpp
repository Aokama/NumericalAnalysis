//
// Created by Aokama on 2020/08/04.
//

#include "NewtonMethod.h"
#include <stdio.h>
#include <math.h>

NewtonMethod::NewtonMethod() = default;

NewtonMethod::NewtonMethod(double (*function)(double), double (*dfunction)(double)) {
    this->function = function;
    this->dfunction = dfunction;
}

void NewtonMethod::set_initial_value(double value) {
    this->x_old = value;
    this->initial_value = value;
}

void NewtonMethod::set_convergence_condition(double condition) {
    this->convergence_condition = condition;
}

void NewtonMethod::run(int max_iteration, ConvergenceDetectionMethod method) {
    bool converged = false;
    for(int i = 0; i <= max_iteration; i++) {
        switch (method) {
            case ERROR:
                if (abs(this->x - this->x_old) < this->convergence_condition) {
                    this->approx_root = this->x;
                    converged = true;
                    break;
                }
                break;
            case RELATIVE_ERROR:
                if (abs((this->x - this->x_old) / this->x) < this->convergence_condition) {
                    this->approx_root = this->x;
                    converged = true;
                    break;
                }
                break;
            case RESIDUAL:
                if (abs(function(this->x_old)) < this->convergence_condition) {
                    this->approx_root = this->x;
                    converged = true;
                    break;
                }
                break;
        }
        if (converged || (i == max_iteration)) {
            break;
        }
        this->x_old = this->x;
        this->x = this->x_old - (function(this->x_old) / dfunction(this->x_old));
        this->repeated_count++;
    }

    if (repeated_count == max_iteration) {
        printf("[NewtonMethod] Did not converged in condition below. Repeated [%d] times.\n", this->repeated_count);
        printf("ConvergenceCondition : %1.6e\n", this->convergence_condition);
        printf("InitialValue : %1.6e\n", this->initial_value);
    } else {
        printf("[NewtonMethod] Converged in condition below. Repeated [%d] times.\n", this->repeated_count);
        printf("ConvergenceCondition : %1.6e\n", this->convergence_condition);
        printf("InitialValue : %1.6e\n", this->initial_value);
        printf("ApproxRoot : %1.6e\n", this->approx_root);
    }
}

double NewtonMethod::get_approx_root() {
    return this->approx_root;
}