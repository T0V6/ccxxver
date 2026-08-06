#pragma once


//////////////////////////////////////////////////////////
// private impl
//////////////////////////////////////////////////////////
#define CCXXVER_VERSION_COUNT                   0
#define CCXXVER_VERSION_COUNT_STR               "0"
#define CCXXVER_VERSION_HASH                    "0"
#define CCXXVER_VERSION_BRANCH                  "0"
#define CCXXVER_VERSION_COUNT_OFFSET_LAST       0
#define CCXXVER_VERSION_COUNT_OFFSET_LAST_STR   "0"
#define CCXXVER_VERSION_TIMESTAMP               0
#define CCXXVER_VERSION_TIMESTAMP_STR           "0"


#define CCXXVER_VERSION_STR (\
    CCXXVER_VERSION_COUNT_STR \
    "." \
    CCXXVER_VERSION_HASH \
    "." \
    CCXXVER_VERSION_TIMESTAMP_STR \
    "-" \
    CCXXVER_VERSION_BRANCH \
    "." \
    CCXXVER_VERSION_COUNT_OFFSET_LAST_STR \
)

#define CCXXVER_VERSION_SHORT_STR (\
    CCXXVER_VERSION_COUNT_STR \
    "-" \
    CCXXVER_VERSION_BRANCH \
    "." \
    CCXXVER_VERSION_COUNT_OFFSET_LAST_STR \
)





//////////////////////////////////////////////////////////
// public macros
//////////////////////////////////////////////////////////
#define CCXXVER_PUBLIC_LIST(X)              \
    X(VERSION_COUNT)                        \
    X(VERSION_COUNT_STR)                    \
    X(VERSION_HASH)                         \
    X(VERSION_BRANCH)                       \
    X(VERSION_COUNT_OFFSET_LAST)            \
    X(VERSION_COUNT_OFFSET_LAST_STR)        \
    X(VERSION_TIMESTAMP)                    \
    X(VERSION_TIMESTAMP_STR)                \
    X(VERSION_STR)                          \
    X(VERSION_SHORT_STR)
