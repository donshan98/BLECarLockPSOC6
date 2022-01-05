/*
BLEstuff.c

BLE related functions

made by Donald Shannon
for BLEdoor lock project
*/

#include <stdio.h>
#include <limits.h>

#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "global.h"
#include "error.h"
#include "lockControl.h"


// handles ble events
void genericEventHandler(uint32_t event, void *eventParameter)
{
    cy_stc_ble_gatts_write_cmd_req_param_t   *writeReqParameter;
    
    switch (event)
    {
        case CY_BLE_EVT_STACK_ON:
        {
            writeToLog("ble stack started at genericEventHandler\n");
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
            break;
        }
            
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
        {
            writeToLog("ble device disconnected at genericEventHandler\n");
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
            break;
        }

        case CY_BLE_EVT_GATT_CONNECT_IND:
        {
            writeToLog("ble device connected at genericEventHandler\n");
            break;
        }
        
        case CY_BLE_EVT_GATTS_WRITE_REQ:
        {
            writeToLog("write request received at genericEventHandler\n");
            writeReqParameter = (cy_stc_ble_gatts_write_cmd_req_param_t *)eventParameter;
            
            switch (writeReqParameter->handleValPair.attrHandle)
            {
                case CY_BLE_CARLOCK_DEBUGLED_CHAR_HANDLE:
                {
                    uint32_t val = writeReqParameter->handleValPair.value.val[0];
                    toggleDebugLED();
                    break;
                }
                
                default:
                {
                    // error
                    break;
                }
            }
                     
            Cy_BLE_GATTS_WriteRsp(writeReqParameter->connHandle);
            break;
        }
        
        default:
        {
            writeToLog("unknown ble event at genericEventHandler\n");
            break;
        }
    }
}

// ble interrupt
void bleInterruptNotify()
{
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(bleSemaphore, &xHigherPriorityTaskWoken); 
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

// ble task
void bleTask(void *arg)
{
    (void)arg;
    
    writeToLog("BLE Task Started\n");

    bleSemaphore = xSemaphoreCreateCounting(UINT_MAX,0);
    
    Cy_BLE_Start(genericEventHandler);
    
    
    while(Cy_BLE_GetState() != CY_BLE_STATE_ON) // Get the stack going
    {
        Cy_BLE_ProcessEvents();
    }
    
    Cy_BLE_RegisterAppHostCallback(bleInterruptNotify);
    
    for(;;)
    {
        xSemaphoreTake(bleSemaphore, portMAX_DELAY);
        Cy_BLE_ProcessEvents();
    }
}

/* [] END OF FILE */
