//
// Created by Aokama on 2020/08/04.
//

#include "Matrix.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

Matrix::Matrix() = default;

Matrix::Matrix(std::vector<std::vector<double>> array) {
    this->dimension = Dimension(array.size(), array[0].size());
    this->mat_array = array;
}

Matrix::Matrix(Dimension dimension) {
    this->dimension = dimension;
    this->mat_array = std::vector<std::vector<double>>(this->dimension.get_row(), std::vector<double>(this->dimension.get_col()));
}

Dimension Matrix::get_dimension() {
    return this->dimension;
}

double Matrix::at(int i, int j) {
    if(!this->get_dimension().include(i, j)){
        printf("Matrix::at(int, int) caused exception related to illegal arguments.\n");
        this->get_dimension().show("The Matrix Dimension");
        printf("This Dimension does not include (%d, %d).\n", i, j);
        return 0.0;
    }
    return this->mat_array[i - 1][j - 1];
}

void Matrix::set(int i, int j, double value) {
    if(!this->get_dimension().include(i, j)){
        printf("Matrix::set(int, int, double) caused exception related to illegal arguments.\n");
        this->get_dimension().show("The Matrix Dimension");
        printf("This Dimension does not include (%d, %d).\n", i, j);
    }
    this->mat_array[i - 1][j - 1] = value;
}

void Matrix::scale(double factor) {
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            set(i, j, factor * at(i, j));
        }
    }
}

Matrix Matrix::transpose() {
    Matrix result = Matrix(this->dimension);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            result.set(i, j, at(j, i));
        }
    }
    return result;
}

Matrix Matrix::upper_triangular() {
    Matrix result = Matrix(this->dimension);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j){
            if(i <= j){
                result.set(i, j, at(i, j));
            }
            else{
                result.set(i, j, 0.0);
            }
        }
    }
    return result;
}

Matrix Matrix::lower_triangular() {
    Matrix result = Matrix(this->dimension);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j){
            if(i >= j){
                result.set(i, j, at(i, j));
            }
            else{
                result.set(i, j, 0.0);
            }
        }
    }
    return result;
}

bool Matrix::is_square() {
    return this->dimension.is_square();
}

bool Matrix::is_symmetric() {
    if(!is_square()){
        return false;
    }
    else{
        bool symmetric = true;
        for(int i = 1; i <= this->dimension.get_row(); i++){
            for(int j = 1; j <= this->dimension.get_col(); j++){
                if(at(i, j) != at(j, i)){
                    symmetric = false;
                }
            }
        }
        return symmetric;
    }
}

Matrix Matrix::operator+(Matrix right) {
    if(!this->dimension.equals_to(right.get_dimension())){
        printf("Matrix::operator + (Matrix) caused exception related to illegal arguments.\n");
        this->dimension.show("Left");
        right.get_dimension().show("Right");
        printf("Wrong dimensions for adding.\n");
        return Matrix();
    }
    else{
        Matrix result = Matrix(this->dimension);
        for(int i = 1; i <= this->dimension.get_row(); i++){
            for(int j = 1; j <= this->dimension.get_col(); j++){
                result.set(i, j, at(i, j) + right.at(i, j));
            }
        }
        return result;
    }
}

Matrix Matrix::operator-(Matrix right) {
    if(!this->dimension.equals_to(right.get_dimension())){
        printf("Matrix::operator + (Matrix) caused exception related to illegal arguments.\n");
        this->dimension.show("Left");
        right.get_dimension().show("Right");
        printf("Wrong dimensions for subtracting.\n");
        return Matrix();
    }
    else{
        Matrix result = Matrix(this->dimension);
        for(int i = 1; i <= this->dimension.get_row(); i++){
            for(int j = 1; j <= this->dimension.get_col(); j++){
                result.set(i, j, at(i, j) - right.at(i, j));
            }
        }
        return result;
    }
}

Vector Matrix::operator*(const Vector& right) {
    if(!this->dimension.can_multiply_from_right(right.get_dimension())){
        printf("Matrix::operator * (Vector) caused exception related to illegal arguments.\n");
        this->dimension.show("Left");
        right.get_dimension().show("Right");
        printf("Wrong dimensions for multiplying.\n");
        return Vector();
    }
    else{
        Vector result = Vector(right.get_dimension());
        for(int i = 1; i <= this->dimension.get_row(); i++){
            double sum = 0.0;
            for(int k = 1; k <= this->dimension.get_col(); k++){
                sum += at(i, k) * right.at(k);
            }
            result.set(i, sum);
        }
        return result;
    }
}

Matrix Matrix::operator*(Matrix right) {
    if(!this->dimension.can_multiply_from_right(right.get_dimension())){
        printf("Matrix::operator * (Matrix) caused exception related to illegal arguments.\n");
        this->dimension.show("Left");
        right.get_dimension().show("Right");
        printf("Wrong dimensions for multiplying.\n");
        return Matrix();
    }
    else{
        Matrix result = Matrix(Dimension(this->dimension.get_row(), right.get_dimension().get_col()));
        for(int i = 1; i <= this->dimension.get_row(); i++){
            for(int j = 1; j <= right.get_dimension().get_col(); j++){
                double sum = 0.0;
                for(int k = 1; k <= this->dimension.get_col(); k++){
                    sum += at(i, k) * right.at(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }
}

void Matrix::show2d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            printf("%1.2e\t", at(i, j));
        }
        printf("\n");
    }
    printf("======== %s ========\n", name);
}

void Matrix::show4d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            printf("%1.4e\t", at(i, j));
        }
        printf("\n");
    }
    printf("======== %s ========\n", name);
}

void Matrix::show6d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            printf("%1.6e\t", at(i, j));
        }
        printf("\n");
    }
    printf("======== %s ========\n", name);
}

void Matrix::show8d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            printf("%1.8e\t", at(i, j));
        }
        printf("\n");
    }
    printf("======== %s ========\n", name);
}

void Matrix::show10d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= this->dimension.get_row(); i++){
        for(int j = 1; j <= this->dimension.get_col(); j++){
            printf("%1.10e\t", at(i, j));
        }
        printf("\n");
    }
    printf("======== %s ========\n", name);
}

void Matrix::save(const char *filename) {
    std::ofstream file(filename);
    for(int i = 1; i <= dimension.get_row(); i++){
        for(int j = 1; j <= dimension.get_col(); j++){
            file << std::fixed << at(i, j) << "\t";
        }
        file << "\n";
    }
    file.close();
}

Matrix Matrix::zeros(Dimension dimension) {
    Matrix result = Matrix(dimension);
    for(int i = 1; i <= dimension.get_row(); i++){
        for(int j = 1; j <= dimension.get_col(); j++){
            result.set(i, j, 0);
        }
    }
    return result;
}

Matrix Matrix::ones(Dimension dimension) {
    Matrix result = Matrix(dimension);
    for(int i = 1; i <= dimension.get_row(); i++){
        for(int j = 1; j <= dimension.get_col(); j++){
            result.set(i, j, 1);
        }
    }
    return result;
}
