#pragma once


#define VERSION_COUNT   0
    #define VERSION_COUNT_STR   "0"
#define VERSION_HASH    "0"
#define VERSION_BRANCH  "0"
#define VERSION_COUNT_OFFSET_LAST   0
    #define VERSION_COUNT_OFFSET_LAST_STR   "0"
#define VERSION_TIMESTAMP   0
    #define VERSION_TIMESTAMP_STR   "0"


#define VERSION_STR (\
    VERSION_COUNT_STR \
    "." \
    VERSION_HASH \
    "." \
    VERSION_TIMESTAMP_STR \
    "-" \
    VERSION_BRANCH \
    "." \
    VERSION_COUNT_OFFSET_LAST_STR \
)

#define VERSION_SHORT_STR (\
    VERSION_COUNT_STR \
    "-" \
    VERSION_BRANCH \
    "." \
    VERSION_COUNT_OFFSET_LAST_STR \
)
