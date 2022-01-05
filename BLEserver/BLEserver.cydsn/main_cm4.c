/*
main_cm4.c

main loop for starting tasks etc

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
#include "BLEstuff.h"
#include "error.h"

SemaphoreHandle_t bleSemaphore;

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    // starts the debug uart
    UART_1_Start();
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    writeToLog("UART debug console started\n");

    // creates the ble task
    xTaskCreate(bleTask, "bleTask", (8*1024), 0, 2, 0);
    
    // starts running tasks
    vTaskStartScheduler();
    
    // should not get to here
    throwError("freeRTOS scheduler stopped in main\n", TRUE);
}

/* [] END OF FILE */
