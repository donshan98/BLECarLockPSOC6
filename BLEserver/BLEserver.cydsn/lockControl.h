/*
lockControl.h

header for controlling the GPIO lock relays

made by Donald Shannon
for BLEdoor lock project
*/

#ifndef _lockControl_HEADER_
#define _lockControl_HEADER_
    
    #include <stdio.h>
    
    void lock();
    void unlock();
    
    void toggleDebugLED();
    
    void processCommand(uint8_t command);
    
#endif

/* [] END OF FILE */
