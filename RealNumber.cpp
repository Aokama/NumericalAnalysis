//
// Created by Aokama on 2020/11/09.
//

#include "RealNumber.h"

RealNumber::RealNumber(double value) {
    this->d_value = value;
    this->i_value = 0;
    this->is_integer = false;
}

RealNumber::RealNumber(int value) {
    this->d_value = (double)value;
    this->i_value = value;
    this->is_integer = true;
}
