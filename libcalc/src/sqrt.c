#include <stddef.h>
#include "calc.h"
#include <math.h>

ResultNeedingSuccessCheck mysqrt(double a) {
    if(a < 0) {
        ResultNeedingSuccessCheck result = {.status = OP_STATUS_ERROR};
        return result;
    }
    ResultNeedingSuccessCheck result = {
        .status = OP_STATUS_SUCCESS,
        .value = sqrt(a)
    };
    return result;
}


