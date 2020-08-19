#include "Matrix.h"
#include "Vector.h"

#include "GaussSeidelMethod.h"

int main() {

    Matrix A = Matrix({
                              {10,-1,-1,0},
                              {-1,10,-1,-1},
                              {-1,-1,10,-1},
                              {0,-1,-1,10}
    });

    Vector b = Vector(
            {1,1,1,1}
            );

    GaussSeidelMethod method = GaussSeidelMethod(A, b);
    method.set_initial_vector(Vector({1,1,1,1}));
    method.set_epsilon(1.0e-8);
    method.run(100, true);
    method.get_solution().show5d("Sol");

    return 0;

}
