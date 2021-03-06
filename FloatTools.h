#ifndef FLOAT_TOOLS_FLOAT_TOOLS_H
#define FLOAT_TOOLS_FLOAT_TOOLS_H
#include <cmath>
#include <stdlib.h>
#include <complex>

namespace FloatTools {
    bool approx_equal(double x1, double x2);
    bool approx_equal(double x1, double x2, double tol);
    bool approx_equal(std::complex<double> x1, std::complex<double> x2);
    bool approx_equal(std::complex<double> x1, std::complex<double> x2, double tol);
    float rand_float();
    double rand_double();
    float mag_squared(std::complex<float> x);
    float one_magnitude(std::complex<float> x);
    double db_up_from(double x_linear, double db_up);
}

#endif // FLOAT_TOOLS_FLOAT_TOOLS_H

