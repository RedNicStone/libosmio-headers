//
// Created by RedNicStone on 23/03/23.
//

#ifndef LIBOSMIO_STRUCTURES_H
#define LIBOSMIO_STRUCTURES_H

#include "platform.h"
#include "handles.h"
#include "enums.h"


// ---------- //
// Structures //
// ---------- //

typedef struct OsAddressType {
    OsStructureType sType;
    void*           pNext;
    OsAddressFormat format;
    uint32_t        maximumLength;
} OsAddressType;

typedef struct OsProtocolInfo {
    OsStructureType sType;
    void*           pNext;
    char*           name;
    OsAddressType   addressType;
} OsProtocolInfo;

typedef struct OsRange {
    uint32_t begin;
    uint32_t end;
} OsRange;

typedef struct OsPortRange {
    OsRange* portRanges;
    uint32_t portRangesCount;
} OsPortRange;

typedef struct OsPhysicalInterfaceInfo {
    OsStructureType sType;
    void*           pNext;
    uint32_t        minimumTransmissionRate;
    uint32_t        maximumTransmissionRate;
} OsPhysicalInterfaceInfo;

typedef struct OsTransactionInfo {
    OsStructureType         sType;
    void*                   pNext;
    OsTransactionOperation* supportedOperations;
    uint32_t                supportedOperationCount;
} OsTransactionInfo;

typedef struct OsCallbackInfo {
    OsStructureType sType;
    void*           pNext;
} OsCallbackInfo;

typedef struct OsInterfaceCreateInfo {
    OsStructureType     sType;
    void*               pNext;
    OsPhysicalInterface physicalInterface;
} OsInterfaceCreateInfo;

typedef struct OsDeviceCreateInfo {
    OsStructureType sType;
    void*           pNext;
    OsInterface     interface;
    void*           address;
} OsDeviceCreateInfo;

typedef struct OsBufferCreateInfo {
    OsStructureType   sType;
    void*             pNext;
    OsBufferUsage     usage;
    OsBufferType      type;
    OsBufferBehaviour behaviour;
    uint32_t          size;
} OsBufferCreateInfo;

typedef struct OsTransactionCreateInfo {
    OsStructureType        sType;
    void*                  pNext;
    OsBuffer               bufferSource;
    OsBuffer               bufferTarget;
    OsDevice               device;
    OsTransactionOperation operation;
} OsTransactionCreateInfo;

typedef struct OsCallbackRegistryInfo {
    OsStructureType sType;
    void*           pNext;
    void          (*pFunction) (void* userData);
    void*           userData;
} OsCallbackRegistryInfo;

#endif //LIBOSMIO_STRUCTURES_H
