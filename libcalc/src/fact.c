#include <stddef.h>
#include "calc.h"

factint_t fact(double a) {
    factint_t result = 1;
    for (factint_t i = 2; i < (factint_t) a; i++) {
        result *= i;
    }
    return result;
}

