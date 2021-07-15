#ifndef FLOAT_TOOLS_FLOAT_TOOLS_H
#define FLOAT_TOOLS_FLOAT_TOOLS_H
#include <cmath>
#include <stdlib.h>

namespace FloatTools {
    bool approx_equal(double x1, double x2);
    bool approx_equal(double x1, double x2, double tol);
    float rand_float();
    double rand_double();
}

#endif // FLOAT_TOOLS_FLOAT_TOOLS_H
