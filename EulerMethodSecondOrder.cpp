//
// Created by Aokama on 2020/08/22.
//

#include "EulerMethodSecondOrder.h"

EulerMethodSecondOrder::EulerMethodSecondOrder() = default;

EulerMethodSecondOrder::EulerMethodSecondOrder(double (*func_1)(double, double, double), double (*func_2)(double, double, double), int max_count) {
    this->function_1 = func_1;
    this->function_2 = func_2;
    this->data_mat = Matrix(Dimension(max_count + 1, 3));
    this->data_mat.set(1, 2, 0);
    this->data_mat.set(1, 3, 0);
}

void EulerMethodSecondOrder::set_initial_y1(double y1) {
    this->data_mat.set(1, 2, y1);
}

void EulerMethodSecondOrder::set_initial_y2(double y2) {
    this->data_mat.set(1, 3, y2);
}

void EulerMethodSecondOrder::set_range_t(double min, double max) {
    this->min_t = min;
    this->max_t = max;
}

void EulerMethodSecondOrder::run(int max_iteration, bool debug) {
    data_mat.set(1, 1, min_t);
    double h = (max_t - min_t) / max_iteration;
    for(int i = 1; i <= max_iteration; i++){
        data_mat.set(i + 1, 1, min_t + h * i);
        /*Update y1 and y2*/
        double y1_new = data_mat.at(i, 2) + h * function_1(min_t + h * (i - 1), data_mat.at(i, 2), data_mat.at(i, 3));
        double y2_new = data_mat.at(i, 3) + h * function_2(min_t + h * (i - 1), data_mat.at(i, 2), data_mat.at(i, 3));
        data_mat.set(i + 1, 2, y1_new);
        data_mat.set(i + 1, 3, y2_new);

    }
    if(debug){
        data_mat.show6d("(Col 1 = t(n), Col 2 = y1(n), Col 3 = y2(n))");
    }
}

Matrix EulerMethodSecondOrder::get_compiled_maxtrix() {
    return data_mat;
}



