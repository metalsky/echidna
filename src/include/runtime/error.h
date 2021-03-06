#ifndef _RUNTIME_ERROR_H
#define _RUNTIME_ERROR_H


typedef enum _RUNTIME_ERROR {

    ERROR_NONE = 0,
    ERROR_INTERNAL,
    ERROR_INTERNAL_ALLOCATION,
    ERROR_INTERNAL_READ,
    ERROR_INTERNAL_WRITE,
    ERROR_INVALID_BYTECODE,
    ERROR_INVALID_SYMBOL,
    ERROR_INVALID_FUNCTION,
    ERROR_INVALID_LENGTH,
    ERROR_DIVIDE_ZERO,
    ERROR_MODULUS_ZERO,
    ERROR_MATH_OVERFLOW,
    ERROR_OPERAND_TYPE,
    ERROR_PARAMETER_COUNT,
    ERROR_PARAMETER_MISMATCH,
    ERROR_PARAMETER_RANGE,
    ERROR_PARAMETER_TYPE,
    ERROR_PARAMETER_UNKNOWN,
    ERROR_STACK_OVERFLOW,
    ERROR_UNIMPLEMENTED,
}
RUNTIME_ERROR;


const char * runtime_errortostr(int Error);


#endif  //  _RUNTIME_ERROR_H
