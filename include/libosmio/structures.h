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
    OsAddressFormat format;
    uint32_t maximumLength;
} OsAddressType;

typedef struct OsProtocolFeatures {
    OsAddressType addressType;
    uint32_t maximumDeviceCount;
} OsProtocolFeatures;

typedef struct OsDeviceCreateInfo {
    OsStructureType sType;
    void* pNext;
    OsInterface interface;
    void* address;
} OsDeviceCreateInfo;

typedef struct OsInterfaceCreateInfo {
    OsStructureType sType;
    void* pNext;
    OsPhysicalInterface physicalInterface;
} OsInterfaceCreateInfo;

typedef struct OsBufferCreateInfo {
    OsStructureType sType;
    void* pNext;
    OsBufferUsage usage;
    OsBufferType type;
    OsBufferBehaviour behaviour;
    OsAddressFormat format;
    uint32_t maximumSize;
} OsBufferCreateInfo;

typedef struct OsCallbackRegistryInfo {
    OsStructureType sType;
    void* pNext;
    void (*pFunction) (void* userData);
    void* userData;
} OsCallbackRegistryInfo;

typedef struct OsCallbackProperties {
} OsCallbackProperties;

typedef struct OsProtocolProperties {
} OsProtocolProperties;

typedef struct OsPhysicalInterfaceProperties {
} OsPhysicalInterfaceProperties;

typedef struct OsTransactionProperties {
} OsTransactionProperties;

typedef struct OsTransactionCreateInfo {
} OsTransactionCreateInfo;

#endif //LIBOSMIO_STRUCTURES_H
