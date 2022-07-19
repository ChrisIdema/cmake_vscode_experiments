#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#ifdef __cplusplus 
#define LANGUAGE_VERSION "C++" STR(__cplusplus)
#else
#define LANGUAGE_VERSION "C" STR(__STDC_VERSION__)
#endif

#include "main.h"

// #include "driver_inc.h" // only works if library inc folder public
#include "drivers/inc/driver_inc.h" // always works

// #include "util.h" // should result in error, should be a private include of driver library

extern "C" int main(void) 
{
    puts("Hello project \"" CMAKE_PROJECT_NAME "\"");
    puts("Project version: " CMAKE_PROJECT_VERSION);
    printf("pointer size: %d bits\n", (int)sizeof(int*)*8);
    puts("Language: " LANGUAGE_VERSION "\n");

    int unused;
    driver();
    return 0;
}
