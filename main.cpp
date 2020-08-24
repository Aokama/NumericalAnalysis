#include "Matrix.h"
#include "Vector.h"

#include "EulerMethod.h"
#include "CholeskyDecomposition.h"

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>

/*
double f1(double t, double y1, double y2){
    return y2;
}

double f2(double t, double y1, double y2){
    int m = 1.0;
    int o = 1.0;
    return m * (1 - pow(y1, 2)) * y2 - pow(o, 2) * y1;
}
 */


int main() {

    Matrix A = Matrix(Dimension(5, 5));
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            A.set(i, j, (1.0 / (i + j - 1)));
        }
    }

    CholeskyDecomposition cd = CholeskyDecomposition(A);
    Matrix L = cd.decompose();
    L.show2d("Cholesky L");

    (L * L.transpose()).show2d("A");

    A.show2d("A");

    /*

    EulerMethodSecondOrder emso = EulerMethodSecondOrder(f1, f2, 60000);
    emso.set_initial_y1(0);
    emso.set_initial_y2(2);
    emso.set_range_t(0, 15);
    emso.run(60000, true);
    emso.get_compiled_maxtrix().save("60000.txt");

    for(int i = 1; i <= 10; i++){

        EulerMethodSecondOrder method = EulerMethodSecondOrder(f1, f2, 100 * i);
        method.set_initial_y1(0);
        method.set_initial_y2(2);
        method.set_range_t(0, 5);
        method.run(100 * i, true);
        std::string s1 = "VDP-T15-";
        std::string s2 = std::to_string(100 * i);
        std::string s3 = ".txt";
        method.get_compiled_maxtrix().save((s1 + s2 + s3).c_str());

    }

     */

    return 0;

}
