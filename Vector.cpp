//
// Created by Aokama on 2020/08/04.
//

#include "Vector.h"
#include <stdio.h>
#include <math.h>

Vector::Vector() = default ;

Vector::Vector(std::vector<double> array) {
    this->dimension = Dimension(array.size(), 1);
    this->vec_array = std::move(array);
}

Vector::Vector(Dimension dimension) {
    if(!dimension.is_vector()){
        printf("Vector::Vector(Dimension) caused exception related to illegal arguments.\n");
        dimension.show("The Matrix Dimension");
        printf("This Dimension is not a vector.\n");
    }
    else{
        this->dimension = dimension;
        this->vec_array = std::vector<double>(dimension.get_row());
    }
}

Dimension Vector::get_dimension() const {
    return this->dimension;
}

double Vector::at(int i) const {
    if(!this->dimension.include(i, 1)){
        printf("Vector::at(int) caused exception related to illegal arguments.\n");
        this->get_dimension().show("The Vector Dimension");
        printf("This Dimension does not include (%d, %d).\n", i, 1);
        return 0.0;
    }
    return this->vec_array[i - 1];
}

void Vector::set(int i, double value) {
    if(!this->get_dimension().include(i, 1)){
        printf("Vector::set(int, double) caused exception related to illegal arguments.\n");
        this->get_dimension().show("The Vector Dimension");
        printf("This Dimension does not include (%d, %d).\n", i, 1);
    }
    this->vec_array[i - 1] = value;
}

void Vector::scale(double factor) {
   for(int i = 1; i <= this->dimension.get_row(); i++){
       set(i, factor * at(i));
   }
}

double Vector::norm(int n) {
    if(n == 0){
        double max = 0;
        for(int i = 1; i <= this->dimension.get_row(); i++){
            max = (abs(at(i)) > max) ? abs(at(i)) : max;
        }
        return max;
    }
    else if(n > 0){
        double sum = 0;
        for(int i = 1; i <= this->dimension.get_row(); i++){
            sum += pow(abs(at(i)), n);
        }
        return pow(sum, 1 / n);
    }
    else{
        printf("Vector::norm(int) caused exception related to illegal arguments.\n");
        printf("%d - Norm is not calculable.\n", n);
        return 0.0;
    }
}

double Vector::dot(const Vector& target) {
    if(!this->dimension.equals_to(target.get_dimension())){
        printf("Vector::dot(Vector) caused exception related to illegal arguments.\n");
        this->dimension.show("Base");
        target.get_dimension().show("Target");
        printf("Base and Target dimensions are not equivalent to each other.\n");
        return 0.0;
    }
    else{
        double sum = 0;
        for(int i = 1; i <= this->dimension.get_row(); i++){
            sum += at(i) * target.at(i);
        }
        return sum;
    }
}


double Vector::dot(Matrix target) {
    if(!this->dimension.equals_to(target.get_dimension())){
        printf("Vector::dot(Matrix) caused exception related to illegal arguments.\n");
        this->dimension.show("Base");
        target.get_dimension().show("Target");
        printf("Base and Target dimensions are not equivalent to each other.\n");
        return 0.0;
    }
    else{
        double sum = 0;
        for(int i = 1; i <= this->dimension.get_row(); i++){
            sum += at(i) * target.at(1, i);
        }
        return sum;
    }
}

Vector Vector::operator+(const Vector& right) {
    if(!this->dimension.equals_to(right.get_dimension())){
        printf("Vector::operator + (Vector) caused exception related to illegal arguments.\n");
        this->dimension.show("Left");
        right.get_dimension().show("Right");
        printf("Left and Right dimensions are not equivalent to each other.\n");
        return Vector();
    }
    else{
        Vector result = Vector(dimension);
        for(int i = 1; i <= this->dimension.get_row(); i++){
            result.set(i, at(i) + right.at(i));
        }
        return result;
    }
}

Vector Vector::operator-(const Vector &right) {
    if(!this->dimension.equals_to(right.get_dimension())){
        printf("Vector::operator - (Vector) caused exception related to illegal arguments.\n");
        this->dimension.show("Left");
        right.get_dimension().show("Right");
        printf("Left and Right dimensions are not equivalent to each other.\n");
        return Vector();
    }
    else{
        Vector result = Vector(dimension);
        for(int i = 1; i <= this->dimension.get_row(); i++){
            result.set(i, at(i) - right.at(i));
        }
        return result;
    }
}

void Vector::show2d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.get_row(); i++){
        printf("%1.2e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

void Vector::show4d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.get_row(); i++){
        printf("%1.4e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

void Vector::show5d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.get_row(); i++){
        printf("%1.5e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

void Vector::show6d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.get_row(); i++){
        printf("%1.6e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

void Vector::show8d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.get_row(); i++){
        printf("%1.8e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

void Vector::show10d(const char *name) {
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.get_row(); i++){
        printf("%1.12e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

