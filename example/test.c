#include <stdio.h>
#include "include/version.h"
#include "include/lang.h"


int main (void) {
    #ifdef C99
        printf("C version: %s\n", C_STD_VERSION);
    #elif defined(C23)
        bool a = true;
        printf("C version: %s\n", C_STD_VERSION);
    #else
        printf("C version: %s\n", C_STD_VERSION);
    #endif

    printf("\tversion number: %ld\t(%s)\n\tversion name: %s\n", C_STD, C_STD_STR, C_STD_NAME);


    printf("\napp version: %s\n", VERSION_STR);
    printf("\tcommit: %s\n", VERSION_HASH);
    printf("\tbranch: %s\n", VERSION_BRANCH);
    printf("\tbuild time: %s\n", VERSION_TIMESTAMP_STR);
    #if VERSION_COUNT_OFFSET_LAST > 0
        printf("\tcommits since last tag: %d\n", VERSION_COUNT_OFFSET_LAST);
    #else
        printf("\tno commits since last tag\n");
    #endif

    return 0;
}
