#include <stddef.h>
#include <stdint.h>

typedef enum {
    OP_STATUS_SUCCESS,
    OP_STATUS_ERROR
} OperationStatus;

typedef struct {
    OperationStatus status;
    double value;
} ResultNeedingSuccessCheck;

typedef uint64_t factint_t;

double sum(double x[], size_t len);
double sub(double a, double b);
double mul(double x[], size_t len);
ResultNeedingSuccessCheck divide(double a, double b);
factint_t fact(double a);
ResultNeedingSuccessCheck mysqrt(double a);

