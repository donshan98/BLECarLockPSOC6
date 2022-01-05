/*
error.h

header for managing errors and writing log files

made by Donald Shannon
for BLEdoor lock project
*/

#ifndef _error_HEADER_
#define _error_HEADER_

    #include <stdio.h>

    // write log files
    void writeToLog(char* message);

    // throws an error message
    // potentially quits program
    void throwError(char* error, uint32_t severe);

#endif

/* [] END OF FILE */
