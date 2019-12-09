﻿/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.3.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 2019年12月9日
 ***********************************************************************************************/

#ifndef SAMPLE_DEVICE_IMPL
#define SAMPLE_DEVICE_IMPL

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/threadapi.h"
#include "parson.h"

/**
* Type definition
*/

/**
* @brief Result of DigitalTwin command execution.
*/
typedef enum DIGITALTWIN_COMMAND_RESULT_TAG
{
    DIGITALTWIN_COMMAND_OK,
    DIGITALTWIN_COMMAND_TIMEOUT,
    DIGITALTWIN_COMMAND_ERROR
} DIGITALTWIN_COMMAND_RESULT;

/**
* Device telemetries related methods.
*/

int Sensor_Telemetry_ReadCpuusage();

int Sensor_Telemetry_ReadGpuusage();

int Sensor_Telemetry_ReadMemoryusage();

/**
* Device properties related methods.
*/

char* Deviceinfo_Property_GetManufacturer();

char* Deviceinfo_Property_GetModel();

char* Deviceinfo_Property_GetSwVersion();

char* Deviceinfo_Property_GetOsName();

char* Deviceinfo_Property_GetProcessorArchitecture();

char* Deviceinfo_Property_GetProcessorManufacturer();

long Deviceinfo_Property_GetTotalStorage();

long Deviceinfo_Property_GetTotalMemory();

bool Sensor_Property_WifimacCallback(char* wifimac);

bool Sensor_Property_LanmacCallback(char* lanmac);

/**
* Device commands related methods.
*/

DIGITALTWIN_COMMAND_RESULT Sensor_Command_Reboot(unsigned int* statusCode);

// Callbacks to handle the confirmation result of sending telemetry
void SendTelemetry_Succeeded_Callback(const char* interfaceName, const char* telemetryName);
void SendTelemetry_Error_Callback(const char* interfaceName, const char* telemetryName);

// Callbacks to handle the confirmation result of reporting property
void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName);
void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName);

#ifdef __cplusplus
}
#endif

#endif // SAMPLE_DEVICE_IMPL