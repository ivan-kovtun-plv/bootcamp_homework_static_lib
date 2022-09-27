#include <stddef.h>
#include "calc.h"

double mul(double x[], size_t len) {
    double result = 1.0f;
    for(size_t i = 0; i < len; i++) {
        result *= x[i];
    }
    return result;
}
