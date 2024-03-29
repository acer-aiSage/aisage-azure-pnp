﻿/*******************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.3.
 *
 * You need to add your implementation here to:
 *    - get telemetry data from device/sensor
 *    - set read-only property data
 *    - handle read-write property callback
 *    - process device command
 *
 * Generated Date: 2019年12月9日
 *******************************************************************************************/

#include "sample_device_impl.h"
#include "utilities/digitaltwin_serializer.h"
#include "utilities/deviceinfo_interface.h"
#include "utilities/sensor_interface.h"
#include <stdio.h>    //printf
#include <string.h>   //strncpy
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>   //ifreq
#include <unistd.h>   //close

#define Payload_Buffer_Size 256

void SendTelemetry_Succeeded_Callback(const char* interfaceName, const char* telemetryName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on success.

    LogInfo("DigitalTwin successfully delivered telemetry message for %s::%s", interfaceName, telemetryName);
}

void SendTelemetry_Error_Callback(const char* interfaceName, const char* telemetryName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on failure.

    LogInfo("DigitalTwin failed to deliver telemetry message for %s::%s", interfaceName, telemetryName);
}

void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback reporting property on success.

    LogInfo("DigitalTwin successfully report writable property for %s::%s", interfaceName, propertyName);
}

void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback of reporting property on failure.

    LogInfo("DigitalTwin failed to report writable property for %s::%s", interfaceName, propertyName);
}

char* Deviceinfo_Property_GetManufacturer()
{
    // TODO: provide implementation here
    return "Acer";
}

char* Deviceinfo_Property_GetModel()
{
    // TODO: provide implementation here
    return "aiSage";
}

char* Deviceinfo_Property_GetSwVersion()
{
    // TODO: provide implementation here
    return "V1.15";
}

char* Deviceinfo_Property_GetOsName()
{
    // TODO: provide implementation here
    return "Debian 9";
}

char* Deviceinfo_Property_GetProcessorArchitecture()
{
    // TODO: provide implementation here
    return "arm64";
}

char* Deviceinfo_Property_GetProcessorManufacturer()
{
    // TODO: provide implementation here
    return "Rochchip";
}

long Deviceinfo_Property_GetTotalStorage()
{
    // TODO: provide implementation here
    return 32*1024*1024;
}

long Deviceinfo_Property_GetTotalMemory()
{
    // TODO: provide implementation here
    return 2*1024*1024;
}

int Sensor_Telemetry_ReadCpuusage()
{
    // TODO: provide implementation here
    long double a[4], b[4], loadavg;
    FILE *fp;
    char dump[50];
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
    fclose(fp);
    sleep(1);

    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
    fclose(fp);

    loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
    printf("The current CPU utilization is : %d\n",(int)(loadavg * 100));
    return (int)(loadavg * 100);
}

int Sensor_Telemetry_ReadGpuusage()
{
    FILE *fp;
    fp = fopen("/sys/devices/platform/ff9a0000.gpu/utilisation","r");
    int gpuusage;
    fscanf(fp,"%d",&gpuusage);
    printf("The current gpu usage is : %d\n", gpuusage);
    fclose(fp);
    return gpuusage;
}

int Sensor_Telemetry_ReadMemoryusage()
{
    long double a[4], b[4], loadavg;
    char str1[20];
    int total,free;
    FILE *fp;
    char dump[50];
    fp = fopen("/proc/meminfo","r");
    fscanf(fp,"%s %d kB",str1, &total);
    fscanf(fp,"%s %d kB",str1, &free);
    printf("The current memory utilization is : %d\n", (total - free));
    fclose(fp);
    return (total - free);
}

bool Sensor_Property_WifimacCallback(char* wifimac)
{
    int fd;
    struct ifreq ifr;
    char *iface = "wlan0";
    unsigned char *mac;
 
    fd = socket(AF_INET, SOCK_DGRAM, 0);
 
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);
 
    ioctl(fd, SIOCGIFHWADDR, &ifr);
 
    close(fd);
 
    mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    //display mac address
    printf("Mac : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n" , mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    sprintf(wifimac, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    //wifimac = mac;
    LogInfo("Wifimac property new value: %s", wifimac);
    return true;
}

bool Sensor_Property_LanmacCallback(char* lanmac)
{
    int fd;
    struct ifreq ifr;
    char *iface = "eth0";
    unsigned char *mac;
 
    fd = socket(AF_INET, SOCK_DGRAM, 0);
 
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);
 
    ioctl(fd, SIOCGIFHWADDR, &ifr);
 
    close(fd);
 
    mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    //display mac address
    sprintf(lanmac, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    //wifimac = mac;
    LogInfo("Lan mac property new value: %s", lanmac);
    return true;
}

DIGITALTWIN_COMMAND_RESULT Sensor_Command_Reboot(unsigned int* statusCode)
{
    // TODO: provide implementation here

    *statusCode = 200;
    LogInfo("Execute 'reboot' command successfully");
    system("sudo reboot");
    return DIGITALTWIN_COMMAND_OK;
}

