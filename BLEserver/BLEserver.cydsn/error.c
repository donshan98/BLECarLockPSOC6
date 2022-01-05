/*
error.c

manages errors and writes log files

made by Donald Shannon
for BLEdoor lock project
*/

#include <stdio.h>

#include "global.h"

// TODO doesnt work
void writeToLog(char* message)
{
    if(DEBUG_2) printf(message);
    
    // TODO: implement write to log file
    
}

// TODO doesnt work
void throwError(char* error, uint32_t severe)
{
    if (severe)
    {
        writeToLog(error);
        while(true)
        {
            // stalls program
            ;;
        }
    }
    else
    {
        writeToLog(error);
    }
    
}

/* [] END OF FILE */
