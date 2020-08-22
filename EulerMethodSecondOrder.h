//
// Created by Aokama on 2020/08/22.
//

#ifndef NUMERICALANALYSIS_EULERMETHODSECONDORDER_H
#define NUMERICALANALYSIS_EULERMETHODSECONDORDER_H

#include "Matrix.h"

class EulerMethodSecondOrder {
private:
    /*dy(t, y1, y2)*/
    double (*function_1)(double, double, double){};
    /*dx(t, y1, y2)*/
    double (*function_2)(double, double, double){};
    /*t, y1, y2*/
    Matrix data_mat;
    double min_t;
    double max_t;
public:
    EulerMethodSecondOrder();
    EulerMethodSecondOrder(double (*func_1)(double, double, double), double (*func_2)(double, double, double), int max_count);
    void set_initial_y1(double y1);
    void set_initial_y2(double y2);
    void set_range_t(double min, double max);
    void run(int max_iteration, bool debug);
    Matrix get_compiled_maxtrix();
};


#endif //NUMERICALANALYSIS_EULERMETHODSECONDORDER_H
