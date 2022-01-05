/*
lockControl.c

functions for controlling the GPIO lock relays

made by Donald Shannon
for BLEdoor lock project
*/

#include "project.h"

#include "error.h"
#include "global.h"

// TODO doesnt work
void lock()
{
    
}

// TODO doesnt work
void unlock()
{
    
}

// toggles the debug led
void toggleDebugLED()
{
    Cy_GPIO_Inv(LED_pin_PORT, LED_pin_NUM);
}

// reads and does the appropriate command
void processCommand(uint8_t command)
{
    switch (command)
    {
        case LOCK:
        {
            writeToLog("locking\n");
            lock();
            break;
        }
        
        case UNLOCK:
        {
            writeToLog("unlocking\n");
            unlock();
            break;
        }
        
        case DEBUG_LED_TOGGLE:
        {
            writeToLog("toggling debug led\n");
            toggleDebugLED();
            break;
        }
        
        default:
        {
            throwError("unknown command in lockControl\n", FALSE);
            break;
        }
    }
}


/* [] END OF FILE */
