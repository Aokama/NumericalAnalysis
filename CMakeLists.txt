cmake_minimum_required(VERSION 3.16)
project(NumericalAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(NumericalAnalysis main.cpp Matrix.cpp Matrix.h Dimension.cpp Dimension.h Vector.cpp Vector.h NewtonMethod.cpp NewtonMethod.h LUDecomposition.cpp LUDecomposition.h GaussianElimination.cpp GaussianElimination.h EulerMethod.cpp EulerMethod.h CholeskyDecomposition.cpp CholeskyDecomposition.h JacobiMethod.cpp JacobiMethod.h GaussSeidelMethod.cpp GaussSeidelMethod.h PowerMethod.cpp PowerMethod.h EulerMethodSecondOrder.cpp EulerMethodSecondOrder.h Cell.cpp Cell.h HilbertMatrix.cpp HilbertMatrix.h RealNumber.cpp RealNumber.h)