#include <stddef.h>
#include "calc.h"
#include <math.h>

ResultNeedingSuccessCheck divide(double a, double b) {
    double divResult = a / b;
    OperationStatus status = OP_STATUS_SUCCESS;
    if(divResult == HUGE_VAL ||
            divResult == - HUGE_VAL ||
            isnan(divResult)) {
        status = OP_STATUS_ERROR;
    }
    ResultNeedingSuccessCheck result = {status, divResult};
    return result;
}


