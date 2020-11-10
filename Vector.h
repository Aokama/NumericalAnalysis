//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_VECTOR_H
#define NUMERICALANALYSIS_VECTOR_H

#include "Dimension.h"
#include "Matrix.h"
#include <vector>

class Matrix;

class Vector {
private:
    std::vector<double> vec_array;
    Dimension dimension;
public:
    Vector();
    Vector(std::vector<double> array);
    Vector(Dimension dimension);
    Dimension get_dimension() const;

    double at(int i) const;
    void set(int i, double value);
    void scale(double factor);

    Matrix transpose();

    void flip(int a, int b);

    double norm(int n);

    double dot(const Vector& target);
    double dot(Matrix target);

    int hamming_distance(Vector target);

    Vector operator + (const Vector& right);
    Vector operator - (const Vector& right);

    void show2d(const char *name);
    void show4d(const char *name);
    void show5d(const char *name);
    void show6d(const char *name);
    void show8d(const char *name);
    void show10d(const char *name);
};


#endif //NUMERICALANALYSIS_VECTOR_H
