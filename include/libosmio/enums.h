//
// Created by RedNicStone on 23/03/23.
//

#ifndef LIBOSMIO_ENUMS_H
#define LIBOSMIO_ENUMS_H


// ------------ //
// Enumerations //
// ------------ //

#include "handles.h"

typedef enum OsStructureType {
    OS_ADDRESS_TYPE             = 0,
    OS_PROTOCOL_INFO            = 1,
    OS_PORT_RANGE               = 2,
    OS_PHYSICAL_INTERFACE_INFO  = 3,
    OS_TRANSACTION_INFO         = 4,
    OS_CALLBACK_INFO            = 5,
    OS_INTERFACE_CREATE_INFO    = 6,
    OS_DEVICE_CREATE_INFO       = 7,
    OS_BUFFER_CREATE_INFO       = 8,
    OS_TRANSACTION_CREATE_INFO  = 9,
    OS_CALLBACK_REGISTRY_INFO   = 10,
} OsStructureType;

typedef enum OsResult {
    OS_SUCCESS          = 0,
    OS_GENERIC_ERROR    = 1,
    OS_INTERNAL_ERROR   = 2,
    OS_ICD_NOT_FOUND    = 3,
} OsResult;

typedef enum OsBufferUsage {
    OS_BUFFER_USAGE_NATIVE  = 0b01,
    OS_BUFFER_USAGE_DMA     = 0b10,
} OsBufferUsage;

typedef enum OsBufferType {
    OS_BUFFER_TYPE_SINGLE   = 0,
    OS_BUFFER_TYPE_DOUBLE   = 1,
    OS_BUFFER_TYPE_TRIPLE   = 2,
    OS_BUFFER_TYPE_CIRCULAR = 3,
} OsBufferType;

typedef enum OsBufferBehaviour {
    OS_BUFFER_BEHAVIOUR_STATIC  = 0,
    OS_BUFFER_BEHAVIOUR_GROWING = 0,
} OsBufferBehaviour;

typedef enum OsAddressFormat {
    OS_ADDRESS_FORMAT_NONE              = 0,
    OS_ADDRESS_FORMAT_FIXED_LENGTH      = 1,
    OS_ADDRESS_FORMAT_NULL_TERMINATED   = 2,
    OS_ADDRESS_FORMAT_SIZE_PREFIX       = 3,
} OsAddressFormat;

typedef enum OsTransactionOperation {
    OS_TRANSACTION_OPERATION_COPY       = 0,
    OS_TRANSACTION_OPERATION_RECEIVE    = 1,
    OS_TRANSACTION_OPERATION_TRANSMIT   = 2,
} OsTransactionOperation;

typedef enum OsTransactionBehaviour {
    OS_TRANSACTION_OPERATION_BLOCKING   = 0,
    OS_TRANSACTION_OPERATION_INTERRUPT  = 1,
    OS_TRANSACTION_OPERATION_THREADED   = 2,
    OS_TRANSACTION_OPERATION_DMA        = 3,
} OsTransactionBehaviour;

#endif //LIBOSMIO_ENUMS_H
