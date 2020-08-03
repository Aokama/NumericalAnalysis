//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_MATRIX_H
#define NUMERICALANALYSIS_MATRIX_H

#include "Dimension.h"
#include "Vector.h"
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> mat_array;
    Dimension dimension = Dimension();
public:
    Matrix();
    Matrix(std::vector<std::vector<double>> array);
    Matrix(Dimension dimension);
    Dimension get_dimension();

    double at(int i, int j);
    void set(int i, int j, double value);

    void scale(double factor);

    Matrix operator + (Matrix right);
    Matrix operator - (Matrix right);

    Vector operator * (const Vector& right);
    Matrix operator * (Matrix right);

    void show2d(const char *name);
    void show4d(const char *name);
    void show6d(const char *name);
    void show8d(const char *name);
    void show10d(const char *name);

};


#endif //NUMERICALANALYSIS_MATRIX_H
