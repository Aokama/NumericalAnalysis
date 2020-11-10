//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_MATRIX_H
#define NUMERICALANALYSIS_MATRIX_H

#include "Dimension.h"
#include "Vector.h"
#include <vector>

class Vector;

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

    void flip_row(int a, int b);

    void flip_col(int a, int b);

    double norm(int n);

    Matrix transpose();

    Matrix upper_triangular();
    Matrix lower_triangular();

    bool is_square();
    bool is_symmetric();

    Matrix operator + (Matrix right);
    Matrix operator - (Matrix right);

    Vector operator * (const Vector& right);
    Matrix operator * (Matrix right);

    void show2d(const char *name);
    void show4d(const char *name);
    void show5d(const char *name);
    void show6d(const char *name);
    void show8d(const char *name);
    void show10d(const char *name);
    void show12d(const char *name);
    void show15d(const char *name);

    void save(const char *filename);

    static Matrix zeros(Dimension dimension);
    static Matrix ones(Dimension dimension);

};


#endif //NUMERICALANALYSIS_MATRIX_H
