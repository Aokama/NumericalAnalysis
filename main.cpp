#include "Matrix.h"
#include "Vector.h"

#include "PowerMethod.h"
#include <stdio.h>

int main() {

    Matrix A = Matrix({
                              {1,1,0},
                              {1,2,1},
                              {2,5,3}
    });

    PowerMethod method = PowerMethod(A);
    method.set_initial_vector(Vector({1,1,1}));
    method.set_convergence_condition(1.0e-8);
    method.run(100, true);
    method.get_eigen_vector().show5d("EigenVector");
    printf("Spectral Radius %lf\n", method.get_spectral_radius());

    return 0;

}
