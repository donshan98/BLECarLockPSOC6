/*
main_cm0p.c

core 0 BLE thread

made by Donald Shannon
for BLEdoor lock project
*/
#include "project.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    // starts bluetooth
    Cy_BLE_Start(0);
    
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 

    // processes bluetooth events continuously
    for(;;)
    {
        Cy_BLE_ProcessEvents();
    }
}

/* [] END OF FILE */
