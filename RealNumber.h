//
// Created by Aokama on 2020/11/09.
//

#ifndef NUMERICALANALYSIS_REALNUMBER_H
#define NUMERICALANALYSIS_REALNUMBER_H

#include <stdint.h>

class RealNumber {
private:
    bool is_integer;
    double d_value;
    int64_t i_value;
public:
    RealNumber(double value);
    RealNumber(int value);

};


#endif //NUMERICALANALYSIS_REALNUMBER_H
