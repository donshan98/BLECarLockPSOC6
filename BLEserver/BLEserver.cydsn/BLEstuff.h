/*
BLEstuff.h

header for BLE related functions

made by Donald Shannon
for BLEdoor lock project
*/

#ifndef _BLEstuff_HEADER_
#define _BLEstuff_HEADER_
    
    #include <stdio.h>
    
    void genericEventHandler(uint32_t event, void *eventParameter);
    
    void bleInterruptNotify();
    
    void bleTask(void *arg);
    
#endif

/* [] END OF FILE */
