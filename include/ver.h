#pragma once


#ifndef CCXXVER_STR
    #define CCXXVER_STR_IMPL(x) #x
    #define CCXXVER_STR(x)  CCXXVER_STR_IMPL(x)
#endif


// version
#define CCXXVER_VERSION_MAJOR                           0
#define CCXXVER_VERSION_MINOR                           0
#define CCXXVER_VERSION_PATCHLEVEL                      0

#define CCXXVER_VERSION                                 CCXXVER_VERSION_MAJOR
#define CCXXVER_VERSION_STR                             CCXXVER_STR(CCXXVER_VERSION)


// build metadata
#define CCXXVER_VERSION_BUILD_COUNT                     0
#define CCXXVER_VERSION_BUILD_COUNT_STR                 "0"
#define CCXXVER_VERSION_BUILD_HASH                      "0"
#define CCXXVER_VERSION_BUILD_BRANCH                    "0"
#define CCXXVER_VERSION_BUILD_COUNT_OFFSET_LAST         0
#define CCXXVER_VERSION_BUILD_COUNT_OFFSET_LAST_STR     "0"
#define CCXXVER_VERSION_BUILD_TIMESTAMP                 0
#define CCXXVER_VERSION_BUILD_TIMESTAMP_STR             "0"
#define CCXXVER_VERSION_BUILD_DIRTY                     "+dirty"


#define CCXXVER_VERSION_BUILD (\
    CCXXVER_VERSION_BUILD_COUNT_STR \
    "." \
    CCXXVER_VERSION_BUILD_HASH \
    "." \
    CCXXVER_VERSION_BUILD_TIMESTAMP_STR \
    "-" \
    CCXXVER_VERSION_BUILD_BRANCH \
    "." \
    CCXXVER_VERSION_BUILD_COUNT_OFFSET_LAST_STR \
)

#define CCXXVER_VERSION_BUILD_SHORT (\
    CCXXVER_VERSION_BUILD_COUNT_STR \
    "-" \
    CCXXVER_VERSION_BUILD_BRANCH \
    "." \
    CCXXVER_VERSION_BUILD_COUNT_OFFSET_LAST_STR \
)
