#pragma once


#define VERSION_COUNT   0
    #define VERSION_COUNT_STR   "0"
#define VERSION_HASH    0
    #define VERSION_HASH_STR    "0"
#define VERSION_BRANCH  0
    #define VERSION_BRANCH_STR  "0"
#define VERSION_COUNT_OFFSET_LAST   0
    #define VERSION_COUNT_OFFSET_LAST_STR   "0"
#define VERSION_TIMESTAMP   0
    #define VERSION_TIMESTAMP_STR   "0"


#define VERSION_STR (\
    VERSION_COUNT_STR \
    "." \
    VERSION_HASH_STR \
    "." \
    VERSION_TIMESTAMP_STR \
    "-" \
    VERSION_BRANCH_STR \
    "." \
    VERSION_COUNT_OFFSET_LAST_STR \
)
