//
// Created by Aokama on 2020/08/04.
//

#include "EulerMethod.h"
#include <math.h>

EulerMethod::EulerMethod() = default;

EulerMethod::EulerMethod(double (*dy)(double, double), int max_count) {
    this->function = dy;
    this->mat_y = Matrix(Dimension(max_count + 1, 2));
    this->mat_y.set(1, 2, 0);
}

void EulerMethod::set_initial_y(double y) {
    mat_y.set(1, 2, y);
}

void EulerMethod::set_range_t(double min, double max) {
    this->min_t = min;
    this->max_t = max;
}

void EulerMethod::run(int max_iteration, bool debug) {
    mat_y.set(1, 1, min_t);
    double h = (max_t - min_t) / max_iteration;
    for(int i = 1; i <= max_iteration; i++){
        mat_y.set(i + 1, 1, min_t + h * i);
        mat_y.set(i + 1, 2, mat_y.at(i, 2) + h * function(min_t + h * (i - 1), mat_y.at(i, 2)));
    }
    if(debug){
        mat_y.show6d("(Col 1 = t(n), Col 2 = y(n))");
    }
}

Matrix EulerMethod::get_error_matrix(double (*true_function)(double)) {
    Matrix mat_error = mat_y;
    for(int i = 1; i <= mat_error.get_dimension().get_row(); i++){
        mat_error.set(i, 2, abs(mat_error.at(i, 2) - true_function(mat_error.at(i, 1))));
    }
    return mat_error;
}

Matrix EulerMethod::get_compiled_maxtrix() {
    return mat_y;
}


