#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h"
#include "DefineOperation.h"
#include "SimpleMemoryControl.h"

typedef union {
    double singleValue;
    struct {
        double a;
        double b;
    } pair;
    struct {
        double *x;
        size_t len;
    } array;
} InputValue;

typedef struct {
    CurrentOperation operation;
    InputValue args;
} Input;

Input getInputFromCommandLine(int argc, char **argv);
Input getInputFromUserKeyboard(void);

int main(int argc, char **argv) {
    Input input = (argc == 1) ?
                    getInputFromUserKeyboard() :
                    getInputFromCommandLine(argc, argv);
    switch (input.operation) {
    case CURRENT_OP_SUM: {
        double result = sum(input.args.array.x, input.args.array.len);
        printf("The sum is %f\n", result);
        break;
    }
    case CURRENT_OP_SUB: {
        double result = sub(input.args.pair.a, input.args.pair.b);
        printf("The difference is %f\n", result);
        break;
    }
    case CURRENT_OP_MUL: {
        double result = mul(input.args.array.x, input.args.array.len);
        printf("The product is %f\n", result);
        break;
    }
    case CURRENT_OP_DIV: {
        ResultNeedingSuccessCheck result = divide(input.args.pair.a, input.args.pair.b);
        if(result.status == OP_STATUS_ERROR) {
            printf("Error: division by zero.\n");
            deallocateAll();
            exit(2);
        } else {
            printf("The quotient is %f\n", result.value);
        }
        break;
    }
    case CURRENT_OP_FACT: {
        factint_t result = fact(input.args.singleValue);
        printf("The factorial is %d\n", result);
        break;
    }
    case CURRENT_OP_SQRT: {
        ResultNeedingSuccessCheck result = mysqrt(input.args.singleValue);
        if(result.status == OP_STATUS_ERROR) {
            printf("Error: sqrt from negative value.\n");
            deallocateAll();
            exit(2);
        } else {
            printf("The sqrt is %f\n", result.value);
        }
        break;
    }}
    deallocateAll();
    return 0;
}

typedef struct {
    double *param;
    size_t len;
} ParametersFromArgv;

ParametersFromArgv getParameters(int argc, char **argv);
// dependent on fn allocateMemory from SimpleMemoryControl

Input getInputFromCommandLine(int argc, char **argv) {
    CurrentOperation op = defineOperation(argv[1]);
    OperationArgumentsQuantity argqty = getOperationArgumentsQuantity(op);
    ParametersFromArgv param = getParameters(argc, argv);
    Input result = {.operation = op};

    switch(argqty) {
        case OPERATION_ARGUMENTS_QUANTITY_ONE:
            if(param.len != 1) {
                printf("Error: wrong arguments quantity.\n");
                deallocateAll();
                exit(1);
            }
            result.args.singleValue = param.param[0];
            break;
        case OPERATION_ARGUMENTS_QUANTITY_TWO:
            if(param.len != 2) {
                printf("Error: wrong arguments quantity.\n");
                deallocateAll();
                exit(1);
            }
            result.args.pair.a = param.param[0];
            result.args.pair.b = param.param[1];
            break;
        case OPERATION_ARGUMENTS_QUANTITY_MANY:
            if(param.len < 2) {
                printf("Error: wrong arguments quantity.\n");
                deallocateAll();
                exit(1);
            }
            result.args.array.x = param.param;
            result.args.array.len = param.len;
            break;
    }
    return result;
}

ParametersFromArgv getParameters(int argc, char **argv) {
    ParametersFromArgv p = {NULL, 0};
    p.param = allocateMemory(sizeof(double)*(argc-2));
    for(int i = 2; i < argc; i++) {
        char *endptr;
        double tmp = strtod(argv[i], &endptr);
        if(argv[i] != endptr) {
            p.param[p.len++] = tmp;
        } else {
            printf("Error: '%s' can't be converted to double. Argument was skipped.\n", argv[i]);
        }
    }
    return p;
}


CurrentOperation scanOperationStr(void);
double scanNecessaryParameter(char *message);

Input getInputFromUserKeyboard(void) {
    CurrentOperation op = scanOperationStr();
    OperationArgumentsQuantity argqty = getOperationArgumentsQuantity(op);
    Input result = {.operation = op};

    switch(argqty) {
        case OPERATION_ARGUMENTS_QUANTITY_ONE:
            result.args.singleValue = scanNecessaryParameter("Input argument:");
            break;
        case OPERATION_ARGUMENTS_QUANTITY_TWO:
            result.args.pair.a = scanNecessaryParameter("Input first argument:");
            result.args.pair.b = scanNecessaryParameter("Input second argument:");
            break;
        case OPERATION_ARGUMENTS_QUANTITY_MANY:
            result.args.array.x = allocateMemory(sizeof(double)*2);
            result.args.array.x[0] = scanNecessaryParameter("Input first argument:");
            result.args.array.x[1] = scanNecessaryParameter("Input second argument:");
            result.args.array.len = 2;
            break;
    }
    return result;
}

CurrentOperation scanOperationStr(void) {
    char tmp[64];
    printf("Input operation:\n");
    scanf("%s", tmp);
    return defineOperation(tmp);
}

double scanNecessaryParameter(char *message) {
    char tmp[64];
    char *endptr;
    double result;
    printf("%s\n", message);
    do {
        scanf("%s", tmp);
        result = strtod(tmp, &endptr);
        if(endptr == tmp) {
            printf("Error: str was not converted to double. Try again:\n");
        }
    } while (endptr == tmp);
    return result;
}

