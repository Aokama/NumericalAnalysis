#include "Matrix.h"
#include "Vector.h"

#include "EulerMethod.h"
#include "EulerMethodSecondOrder.h"
#include "HilbertMatrix.h"
#include "LUDecomposition.h"
#include "GaussianElimination.h"

#include <stdio.h>
#include <math.h>

Matrix Jacobian(double x, double y){
    Matrix ret = Matrix({
            {2 * x, 2 * y},
            {x * (3 * x + 4) * pow(y, 2), 2 * (x - 2) * y}
    });
    return ret;
}

Vector f(double x, double y){
    Vector ret = Vector(Dimension(2, 1));
    ret.set(1, pow(x, 2) + pow(y, 2) - 1);
    ret.set(2, pow(x, 2) * (x + 2) + pow(y, 2) * (x - 2));
    return ret;
}

int main() {

    Vector x_0 = Vector(Dimension(2, 1));
    x_0.set(1, 1.0);
    x_0.set(2, 0.5);
    Vector x_k = Vector(Dimension(2, 1));

    x_k = x_0;

    for(int i = 1; i <= 50; i++){
        Matrix J = Jacobian(x_k.at(1), x_k.at(2));
        Vector F = f(x_k.at(1), x_k.at(2));
        F.scale(-1.0);
        GaussianElimination ge = GaussianElimination(J, F);
        ge.forward_elimination(true, false);
        ge.backward_substitution(false);
        Vector d = ge.get_solution();
        x_k = x_k + d;

        Vector comp = f(x_k.at(1), x_k.at(2));
        if(comp.norm(1) < 1.0e-10){
            printf("the solution is (%0.5e, %0.5e), Repeated %d times", x_k.at(1), x_k.at(2), i);
            break;
        }
    }


    /*
    int N = 1000000;
    double max_t = 1.0;
    double min_t = 0.0;
    double init_Y = 0.0;
    double h = (max_t - min_t) / N;

    Vector Y = Vector(Dimension(N + 1, 1));
    Vector x = Vector(Dimension(N + 1, 1));

    Y.set(0, init_Y);
    x.set(0, min_t);

    for(int i = 0; i <= N; i++){
        x.set(i + 1, x.at(i) + h);
        double temp_Y = Y.at(i) + h * function(x.at(i), Y.at(i));
        Y.set(i + 1, Y.at(i) + (0.5) * h * (function(x.at(i), Y.at(i)) + function(x.at(i + 1), temp_Y)));
    }

    for(int i = 0; i <= N; i++){
        printf("%0.15e\t", x.at(i));
        printf("%0.15e\n", Y.at(i));
    }
    */


}
