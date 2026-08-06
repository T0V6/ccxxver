#include <print>
#include <iostream>
#include "include/lang.h"
#include "include/version.h"


int main() {
    #ifdef CXX26
        std::println("C++ version: {}", CXX_STD_VERSION);
    #elif defined(CXX23)
        std::print("C++ version: {}\n", CXX_STD_VERSION);
    #else
        std::cout << "C++ version: " << CXX_STD_VERSION << "\n";
    #endif

    std::cout << "\tversion number: " << CXX_STD << "\t(" << CXX_STD_STR << ")\n";
    std::cout << "\tversion name: " << CXX_STD_NAME << "\n";


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
