﻿/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.3.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 2019年12月9日
 ***********************************************************************************************/

#include "deviceinfo_interface.h"

#define MAX_MASSAGE_SIZE 256

//
// Application state associated with this interface.
// It contains the DIGITALTWIN_INTERFACE_CLIENT_HANDLE used for responses in callbacks along with properties set
// and representations of the property update and command callbacks invoked on given interface
//
typedef struct DEVICEINFO_INTERFACE_STATE_TAG
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceClientHandle;

} DEVICEINFO_INTERFACE_STATE;

static DEVICEINFO_INTERFACE_STATE appState;

// DeviceinfoInterface_PropertyCallback is invoked when a property is updated (or failed) going to server.
// ALL property callbacks will be routed to this function and just have the userContextCallback set to the propertyName.
// Product code will potentially have context stored in this userContextCallback.
static void DeviceinfoInterface_PropertyCallback(DIGITALTWIN_CLIENT_RESULT digitalTwinReportedStatus, void* userContextCallback)
{
    if (digitalTwinReportedStatus == DIGITALTWIN_CLIENT_OK)
    {
        ReportProperty_Succeeded_Callback("Deviceinfo", (const char*)userContextCallback);
        LogInfo("DEVICEINFO_INTERFACE: Updating property=<%s> succeeded", (const char*)userContextCallback);
    }
    else
    {
        ReportProperty_Error_Callback("Deviceinfo", (const char*)userContextCallback);
        LogError("DEVICEINFO_INTERFACE: Updating property=<%s> failed, error=<%s>", (const char*)userContextCallback, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, digitalTwinReportedStatus));
    }
}

// DeviceinfoInterface_ReportProperty_Internal is a helper function to report a Deviceinfo's properties.
// It invokes underlying DigitalTwin API for reporting properties and sets up its callback on completion.
DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_ReportProperty_Internal(DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle, const char* propertyName, const char* propertyData)
{
    DIGITALTWIN_CLIENT_RESULT result = DigitalTwin_InterfaceClient_ReportPropertyAsync(interfaceHandle, propertyName,
        (const char*)propertyData, NULL,
        DeviceinfoInterface_PropertyCallback, (void*)propertyName);

    if (result == DIGITALTWIN_CLIENT_OK)
    {
        LogInfo("DEVICEINFO_INTERFACE: Queued async report read only property for %s", propertyName);
        
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: Reporting property=<%s> failed, error=<%s>", propertyName, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
    }

    DigitalTwinClientHelper_Check();
    return result;
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportManufacturer()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeManufacturerProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_ManufacturerProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property manufacturer failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportModel()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeModelProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_ModelProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property model failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportSwVersion()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeSwVersionProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_SwVersionProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property swVersion failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportOsName()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeOsNameProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_OsNameProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property osName failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportProcessorArchitecture()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeProcessorArchitectureProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_ProcessorArchitectureProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property processorArchitecture failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportProcessorManufacturer()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeProcessorManufacturerProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_ProcessorManufacturerProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property processorManufacturer failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportTotalStorage()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeTotalStorageProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_TotalStorageProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property totalStorage failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportTotalMemory()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("DEVICEINFO_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Deviceinfo_SerializeTotalMemoryProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return DeviceinfoInterface_ReportProperty_Internal(appState.interfaceClientHandle, DeviceinfoInterface_TotalMemoryProperty, payloadBuffer);
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: serialize read only property totalMemory failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT DeviceinfoInterface_Property_ReportAll()
{
    DIGITALTWIN_CLIENT_RESULT result;

    // NOTE: Future versions of SDK will support ability to send multiple properties in a single
    // send.  For now, one at a time is sufficient albeit less efficient.
    if (((result = DeviceinfoInterface_Property_ReportManufacturer()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportModel()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportSwVersion()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportOsName()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportProcessorArchitecture()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportProcessorManufacturer()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportTotalStorage()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = DeviceinfoInterface_Property_ReportTotalMemory()) != DIGITALTWIN_CLIENT_OK) )

    {
        LogError("DEVICE_INFO: Reporting properties failed.");
    }
    else
    {
        LogInfo("DEVICE_INFO: Queuing of all properties to be reported has succeeded");
    }

    return result;
}

// DeviceinfoInterface_InterfaceRegisteredCallback is invoked when this interface
// is successfully or unsuccessfully registered with the service, and also when the interface is deleted.
static void DeviceinfoInterface_InterfaceRegisteredCallback(DIGITALTWIN_CLIENT_RESULT dtInterfaceStatus, void* userInterfaceContext)
{
    LogInfo("DeviceinfoInterface_InterfaceRegisteredCallback with status=<%s>, userContext=<%p>", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus), userInterfaceContext);
    if (dtInterfaceStatus == DIGITALTWIN_CLIENT_OK)
    {
        // Once the interface is registered, send our reported properties to the service.  
        // It *IS* safe to invoke most DigitalTwin API calls from a callback thread like this, though it 
        // is NOT safe to create/destroy/register interfaces now.
        LogInfo("DEVICEINFO_INTERFACE: Interface successfully registered.");
    }
    else if (dtInterfaceStatus == DIGITALTWIN_CLIENT_ERROR_INTERFACE_UNREGISTERING)
    {
        // Once an interface is marked as unregistered, it cannot be used for any DigitalTwin SDK calls.
        LogInfo("DEVICEINFO_INTERFACE: Interface received unregistering callback.");
    }
    else
    {
        LogError("DEVICEINFO_INTERFACE: Interface received failed, status=<%s>.", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus));
    }
}

//
// Create DigitalTwin interface client handle
//
DIGITALTWIN_INTERFACE_CLIENT_HANDLE DeviceinfoInterface_Create()
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle;
    DIGITALTWIN_CLIENT_RESULT result;

    memset(&appState, 0, sizeof(DEVICEINFO_INTERFACE_STATE));

    if ((result = DigitalTwin_InterfaceClient_Create(DeviceinfoInterfaceId,  DeviceinfoInterfaceInstanceName, DeviceinfoInterface_InterfaceRegisteredCallback, (void*)&appState, &interfaceHandle)) != DIGITALTWIN_CLIENT_OK)
    {
        LogError("DEVICEINFO_INTERFACE: Unable to allocate interface client handle for interfaceId=<%s>, interfaceInstanceName=<%s>, error=<%s>", DeviceinfoInterfaceId, DeviceinfoInterfaceInstanceName, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
        interfaceHandle = NULL;
    }

    else
    {
        LogInfo("DEVICEINFO_INTERFACE: Created DIGITALTWIN_INTERFACE_CLIENT_HANDLE successfully for interfaceId=<%s>, interfaceInstanceName=<%s>, handle=<%p>", DeviceinfoInterfaceId, DeviceinfoInterfaceInstanceName, interfaceHandle);
        appState.interfaceClientHandle = interfaceHandle;
    }

    return interfaceHandle;
}

void DeviceinfoInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle)
{
    // On shutdown, in general the first call made should be to DigitalTwin_InterfaceClient_Destroy.
    // This will block if there are any active callbacks in this interface, and then
    // mark the underlying handle such that no future callbacks shall come to it.
    DigitalTwin_InterfaceClient_Destroy(digitalTwinInterfaceClientHandle);

    // After DigitalTwin_InterfaceClient_Destroy returns, it is safe to assume
    // no more callbacks shall arrive for this interface and it is OK to free
    // resources callbacks otherwise may have needed.

}
