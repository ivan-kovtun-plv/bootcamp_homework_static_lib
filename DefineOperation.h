typedef enum {
    CURRENT_OP_SUM,
    CURRENT_OP_SUB,
    CURRENT_OP_MUL,
    CURRENT_OP_DIV,
    CURRENT_OP_FACT,
    CURRENT_OP_SQRT
} CurrentOperation;

typedef enum {
    OPERATION_ARGUMENTS_QUANTITY_ONE,
    OPERATION_ARGUMENTS_QUANTITY_TWO,
    OPERATION_ARGUMENTS_QUANTITY_MANY
} OperationArgumentsQuantity;

CurrentOperation defineOperation(char *in);
/* uses the insert defined key-value table */

OperationArgumentsQuantity getOperationArgumentsQuantity(CurrentOperation op);
/* uses the insert defined table */

