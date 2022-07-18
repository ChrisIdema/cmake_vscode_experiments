#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#ifdef __cplusplus 
#define LANGUAGE_VERSION "C++"STR(__cplusplus)
#else
#define LANGUAGE_VERSION "C"STR(__STDC_VERSION__)
#endif



int main(void)
{
    puts("Hello project \"" CMAKE_PROJECT_NAME "\"");
    puts("Project version: " CMAKE_PROJECT_VERSION);
    printf("pointer size: %d bits\n", sizeof(int*)*8);
    puts("Language: " LANGUAGE_VERSION "\n");
    return 0;
}
