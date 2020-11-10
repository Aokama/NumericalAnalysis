//
// Created by Aokama on 2020/10/12.
//

#ifndef NUMERICALANALYSIS_HILBERTMATRIX_H
#define NUMERICALANALYSIS_HILBERTMATRIX_H

#include "Matrix.h"

class HilbertMatrix {
public:
    [[nodiscard]] Matrix create(int N) const;
};


#endif //NUMERICALANALYSIS_HILBERTMATRIX_H
