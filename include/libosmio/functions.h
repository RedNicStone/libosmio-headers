//
// Created by RedNicStone on 23/03/23.
//

#ifndef LIBOSMIO_FUNCTIONS_H
#define LIBOSMIO_FUNCTIONS_H

#include "platform.h"
#include "structures.h"


// -------------------- //
// Function Definitions //
// -------------------- //

// OsInstance
OS_DECLARE_FUNCTION_ICD(void, osCreateInstance,
                        OsInstance* pInstance)
OS_DECLARE_FUNCTION_ICD(void, osDestroyInstance,
                        OsInstance pInstance)

// OsProtocol
OS_DECLARE_FUNCTION_ICD(void, osEnumerateProtocols,
                        OsInstance instance, uint32_t* protocolCount, OsProtocol** pProtocols)
OS_DECLARE_FUNCTION_ICD(void, osGetProtocolInfo,
                        OsProtocol protocol, OsProtocolInfo* pProtocolInfo)

// OsPhysicalInterface
OS_DECLARE_FUNCTION_ICD(void, osEnumeratePhysicalInterfaces,
                        OsProtocol protocol, uint32_t* physicalInterfaceCount, OsPhysicalInterface** pPhysicalInterfaces)
OS_DECLARE_FUNCTION_ICD(void, osGetPhysicalDeviceInfo,
                        OsPhysicalInterface physicalInterface, OsPhysicalInterfaceInfo* pPhysicalInterfaceInfo)

// OsInterface
OS_DECLARE_FUNCTION_ICD(OsResult, osCreateInterface,
                        OsInterfaceCreateInfo physicalInterface, OsInterface* pInterface)
OS_DECLARE_FUNCTION_ICD(void, osDestroyInterface,
                        OsInterface interface)

// OsDevice
OS_DECLARE_FUNCTION_ICD(OsResult, osCreateDevice,
                        OsDeviceCreateInfo* pCreateInfo, OsDevice* pDevice)
OS_DECLARE_FUNCTION_ICD(void, osDestroyDevice,
                        OsDevice device)

// OsBuffer
OS_DECLARE_FUNCTION_ICD(OsResult, osAllocateBuffer,
                        OsDeviceCreateInfo* pCreateInfo, OsDevice* pDevice)
OS_DECLARE_FUNCTION_ICD(void, osFreeBuffer,
                        OsBuffer buffer)

// OsCallback
OS_DECLARE_FUNCTION_ICD(void, osEnumerateProtocolCallbacks,
                        OsProtocol protocol, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION_ICD(void, osEnumerateInterfaceCallbacks,
                        OsInterface interface, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION_ICD(void, osEnumerateDeviceCallbacks,
                        OsDevice device, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION_ICD(void, osEnumerateTransactionCallbacks,
                        OsDevice device, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION_ICD(void, osGetCallbackInfo,
                        OsCallback callback, OsCallbackInfo* pCallbackInfo)
OS_DECLARE_FUNCTION_ICD(OsResult, osRegisterCallback,
                        OsCallback callback, OsCallbackRegistryInfo callbackRegistryInfo)
OS_DECLARE_FUNCTION_ICD(void, osRemoveCallback,
                        OsCallback callback, void (*pFunction) (void* userData))
OS_DECLARE_FUNCTION_ICD(void, osRemoveAllCallbacks,
                        OsCallback callback)

// OsTransaction
OS_DECLARE_FUNCTION_ICD(void, osGetInterfaceTransactionInfo,
                        OsInterface interface, OsTransactionInfo* transactionInfo);
OS_DECLARE_FUNCTION_ICD(void, osCreateTransaction,
                        OsTransactionCreateInfo transactionCreateInfo, OsTransaction* transaction);
OS_DECLARE_FUNCTION_ICD(void, osBeginTransaction,
                        OsTransaction transaction);
OS_DECLARE_FUNCTION_ICD(void, osWaitForTransaction,
                        OsTransaction transaction)
OS_DECLARE_FUNCTION_ICD(void, osDestroyTransaction,
                        OsTransaction transaction);

// OsICD
struct OsICD;
OS_DECLARE_FUNCTION(void, osRegisterICD,
                    const OsICD* icd);

#endif //LIBOSMIO_FUNCTIONS_H
