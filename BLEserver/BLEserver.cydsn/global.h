/*
global.h

stores global variables and flags

made by Donald Shannon
for BLEdoor lock project
*/

#ifndef _global_HEADER_
#define _global_HEADER_

    #include <stdio.h>
    #include "FreeRTOS.h"
    #include "semphr.h"

    // freeRTOS vals
    #define TICK_TIME 1000
    
    // other vals
    #define true 1
    #define TRUE 1
    #define false 0
    #define FALSE 0

    // debug flag
    #define DEBUG_2 true

    // LED status
    #define LED_ON (uint32_t)0
    #define LED_OFF (uint32_t)1

    // function codes
    #define LOCK (uint8_t)1
    #define UNLOCK (uint8_t)2
    #define DEBUG_LED_TOGGLE (uint8_t)3

    // response codes
    #define ERROR (uint8_t)0
    #define SUCCESS (uint8_t)1

    // global vals
    extern SemaphoreHandle_t bleSemaphore;
    
#endif

/* [] END OF FILE */
