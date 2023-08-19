//
// Created by RedNicStone on 23/03/23.
//

#ifndef LIBOSMIO_FUNCTIONS_H
#define LIBOSMIO_FUNCTIONS_H

#include "libosmio/handles.h"
#include "platform.h"
#include "structures.h"
#include "version.h"


// -------------------- //
// Function Definitions //
// -------------------- //


// OsVersion
OS_DECLARE_FUNCTION_GLOBAL(OsResult, osEnumerateInstanceVersion,
                           OsVersion* pVersion);

// OsInstance
OS_DECLARE_FUNCTION_GLOBAL(OsResult, osCreateInstance,
                           OsInstance* pInstance);
OS_DECLARE_FUNCTION_GLOBAL(OsResult, osDestroyInstance,
                           OsInstance instance);

// OsProtocol
OS_DECLARE_FUNCTION_GLOBAL(OsResult, osEnumerateProtocols,
                           OsInstance instance, uint32_t* pProtocolCount, OsProtocol** ppProtocols);
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osGetProtocolProperties,
                             OsProtocol protocol, OsProtocolProperties* pProtocolProperties);

// OsPhysicalInterface
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osEnumeratePhysicalInterfaces,
                             OsProtocol protocol, uint32_t* pPhysicalInterfaceCount,
                             OsPhysicalInterface** ppPhysicalInterfaces);
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osGetPhysicalDeviceProperties,
                             OsPhysicalInterface physicalInterface,
                             OsPhysicalInterfaceProperties* pPhysicalInterfaceProperties);

// OsInterface
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osCreateInterface,
                             OsPhysicalInterface physicalInterface, OsInterfaceCreateInfo* interfaceCreateInfo,
                             OsInterface* pInterface);
OS_DECLARE_FUNCTION_INSTANCE(void, osDestroyInterface,
                             OsInterface interface);

// OsDevice
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osCreateDevice,
                             OsInterface interface, OsDeviceCreateInfo* pCreateInfo, OsDevice* pDevice);
OS_DECLARE_FUNCTION_INSTANCE(void, osDestroyDevice,
                             OsDevice device);

// OsBuffer
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osAllocateBuffer,
                             OsDevice device, OsBufferCreateInfo* pCreateInfo, OsBuffer* pBuffer);
OS_DECLARE_FUNCTION_INSTANCE(void, osFreeBuffer,
                             OsBuffer buffer);

// OsCallback
OS_DECLARE_FUNCTION_INSTANCE(void, osEnumerateProtocolCallbacks,
                             OsProtocol protocol, uint32_t* pCallbackCount, OsCallback** ppCallbacks);
OS_DECLARE_FUNCTION_INSTANCE(void, osEnumerateInterfaceCallbacks,
                             OsInterface interface, uint32_t* pCallbackCount, OsCallback** ppCallbacks);
OS_DECLARE_FUNCTION_INSTANCE(void, osEnumerateDeviceCallbacks,
                             OsDevice device, uint32_t* pCallbackCount, OsCallback** ppCallbacks);
OS_DECLARE_FUNCTION_INSTANCE(void, osEnumerateTransactionCallbacks,
                             OsDevice device, uint32_t* pCallbackCount, OsCallback** ppCallbacks);
OS_DECLARE_FUNCTION_INSTANCE(void, osGetCallbackProperties,
                             OsCallback callback, OsCallbackProperties* pCallbackProperties);
OS_DECLARE_FUNCTION_INSTANCE(OsResult, osRegisterCallback,
                             OsCallback callback, OsCallbackRegistryInfo callbackRegistryInfo);
OS_DECLARE_FUNCTION_INSTANCE(void, osRemoveCallback,
                             OsCallback callback, void (*pFunction) (void* userData));
OS_DECLARE_FUNCTION_INSTANCE(void, osRemoveAllCallbacks,
                             OsCallback callback);

// OsTransaction
OS_DECLARE_FUNCTION_INSTANCE(void, osGetInterfaceTransactionProperties,
                             OsInterface interface, OsTransactionProperties* pTransactionProperties);
OS_DECLARE_FUNCTION_INSTANCE(void, osCreateTransaction,
                             OsInterface interface, OsTransactionCreateInfo* pTransactionCreateInfo,
                             OsTransaction* pTransaction);
OS_DECLARE_FUNCTION_INSTANCE(void, osBeginTransaction,
                             OsTransaction transaction);
OS_DECLARE_FUNCTION_INSTANCE(void, osWaitForTransaction,
                             OsTransaction transaction);
OS_DECLARE_FUNCTION_INSTANCE(void, osDestroyTransaction,
                             OsTransaction transaction);

#endif //LIBOSMIO_FUNCTIONS_H
