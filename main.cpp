#include "Matrix.h"
#include "Vector.h"

#include "GaussianElimination.h"
#include "CholeskyDecomposition.h"

#include <math.h>

int main() {

    /*
    Matrix A_6 = Matrix({
                              {-2, 4.0/3, 0, 0, 0},
                              {2.0/3, -2, 4.0/3, 0, 0},
                              {0, 2.0/3, -2, 4.0/3, 0},
                              {0, 0, 2.0/3, -2, 4.0/3},
                              {0, 0, 0, 2.0/3, -2}

    });

    Matrix A_24 = Matrix({
                              {-2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2, 13.0/12},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11.0/12, -2},

                      });

    Matrix A_comb = Matrix({
                                 {-2, 1, 0, 0, 0, 0},
                                 {1, -2, 1, 0, 0, 0},
                                 {0, 1, -2, 1, 0, 0},
                                 {0, 0, 1, -2, 1, 0},
                                 {0, 0, 0, 1, -2, 1},
                                 {0, 0, 0, 0, -1, 1}
    });

    Vector b_6 = Vector({
                                 -1.0/9,
                                 -1.0/9,
                                 -1.0/9,
                                 -1.0/9,
                                 -13.0/9
                         });

    double s = -4 * pow((1.0 / 24), 2);

    Vector b_24 = Vector({
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s,
        s - (1 + 2 * (1.0/ 24))
    });

    Vector b_comb = Vector({
        -1.0/9,
        -1.0/9,
        -1.0/9,
        -1.0/9,
        -1.0/9,
        0.0
    });


    GaussianElimination ge_6 = GaussianElimination(A_6, b_6);
    ge_6.forward_elimination(false);
    ge_6.backward_substitution(false);
    ge_6.get_solution().show5d("Solution N = 6");

    GaussianElimination ge_24 = GaussianElimination(A_24, b_24);
    ge_24.forward_elimination(false);
    ge_24.backward_substitution(false);
    ge_24.get_solution().show5d("Solution N = 24");

    GaussianElimination ge_comb = GaussianElimination(A_comb, b_comb);
    ge_comb.forward_elimination(false);
    ge_comb.backward_substitution(false);
    ge_comb.get_solution().show5d("Solution Comb");

    (A_comb * ge_comb.get_solution()).show5d("ss");
    */

    Matrix A = Matrix({
                              {9, 3, 6},
                              {3, 5, 4},
                              {6, 4, 6}
    });

    Vector b = Vector({
        12,
        2,
        8
    });

    CholeskyDecomposition dec = CholeskyDecomposition(A);
    Matrix L = dec.decompose();
    L.show4d("L");

    A.show2d("A");
    (L * L.transpose()).show2d("L * L^t");

    GaussianElimination ge = GaussianElimination(A, b);
    ge.forward_elimination(false);
    ge.backward_substitution(false);
    ge.get_solution().show4d("sol");

    return 0;

}
