//
// Created by RedNicStone on 23/03/23.
//

#ifndef LIBOSMIO_GLOBALS_H
#define LIBOSMIO_GLOBALS_H

#include <cstring>


// -------------- //
// Function Table //
// -------------- //

#include "functions.h"

#undef OS_DECLARE_FUNCTION_ICD
#define OS_DECLARE_FUNCTION_ICD(type, functionName, ...) \
    CONCATENATE(OS_FUNCTION_PTR_PREFIX, functionName) functionName;

#undef OS_DECLARE_FUNCTION
#define OS_DECLARE_FUNCTION(type, functionName, ...)

struct OsDispatchTable {
#undef LIBOSMIO_FUNCTIONS_H
#include "functions.h"
};

struct OsICD {
    char* name;
    void (*functionRegister)();
    void (*functionDeregister)();
    OsDispatchTable dispatchTable;
};

#endif //LIBOSMIO_GLOBALS_H
