#ifndef FLOAT_TOOLS_FLOAT_TOOLS_H
#define FLOAT_TOOLS_FLOAT_TOOLS_H
#include <cmath>
#include <stdlib.h>

namespace FloatTools {
    bool approx_equal(float x1, float x2);
    bool approx_equal(float x1, float x2, float tol);
    float rand_float();
}

#endif // FLOAT_TOOLS_FLOAT_TOOLS_H
