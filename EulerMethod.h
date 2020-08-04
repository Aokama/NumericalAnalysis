//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_EULERMETHOD_H
#define NUMERICALANALYSIS_EULERMETHOD_H

#include "Matrix.h"

class EulerMethod {
private:
    double (*function)(double, double){};
    Matrix mat_y;
    double min_t;
    double max_t;
public:
    EulerMethod();
    EulerMethod(double (*dy)(double, double), int max_count);
    void set_initial_y(double y);
    void set_range_t(double min, double max);
    void run(int max_iteration, bool debug);
    Matrix get_error_matrix(double (*true_function)(double));
    Matrix get_compiled_maxtrix();

};


#endif //NUMERICALANALYSIS_EULERMETHOD_H
