#pragma once


#define CCXXVER_STR_IMPL(x) #x
#define CCXXVER_STR(x)  CCXXVER_STR_IMPL(x)


#ifdef __cplusplus
    ////////////////
    // CXX
    ////////////////

    #ifdef _MSVC_LANG
        #define CCXXVER_COMPILER_CXX_STD   _MSVC_LANG
    #else
        #define CCXXVER_COMPILER_CXX_STD   __cplusplus //__cplusplus fmt is <year><month>
    #endif


    #define CXX_STD CCXXVER_STR(CCXXVER_COMPILER_CXX_STD)


    #define CCXXVER_LANG_STD_CXX11   201103L //0x (1x)
    #define CCXXVER_LANG_STD_CXX14   201402L //1y
    #define CCXXVER_LANG_STD_CXX17   201703L //1z
    #define CCXXVER_LANG_STD_CXX20   202002L //2a
    #define CCXXVER_LANG_STD_CXX23   202302L //2b
    #define CCXXVER_LANG_STD_CXX26   202603L //2c


    #if CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX11
        #define CXX_STD_NAME    "preCXX11"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX11
        #define CXX11
        #define CXX_STD_NAME    "CXX11"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX14
        #define CXX_STD_NAME    "preCXX14"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX14
        #define CXX14
        #define CXX_STD_NAME    "CXX14"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX17
        #define CXX_STD_NAME    "preCXX17"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX17
        #define CXX17
        #define CXX_STD_NAME    "CXX17"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX20
        #define CXX_STD_NAME    "preCXX20"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX20
        #define CXX20
        #define CXX_STD_NAME    "CXX20"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX23
        #define CXX_STD_NAME    "preCXX23"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX23
        #define CXX23
        #define CXX_STD_NAME    "CXX23"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX26
        #define CXX_STD_NAME    "preCXX26"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX26
        #define CXX26
        #define CXX_STD_NAME    "CXX26"

    #else
        #define CXX_STD_NAME    "UNKNOWN"
    #endif


    #define CXX_STD_VERSION     CXX_STD_NAME "_" CXX_STD

#elif defined(__STDC_VERSION__) || defined(__STDC__)
    ////////////////
    // C
    ////////////////
    #ifdef __STDC_VERSION__
        #define CCXXVER_COMPILER_C_STD __STDC_VERSION__    //__STDC_VERSION__ fmt is <year><month>
    #else
        // __STDC__ && !__STDC_VERSION__
        #define CCXXVER_COMPILER_C_STD 198912L //default to c89
    #endif


    #define C_STD CCXXVER_STR(CCXXVER_COMPILER_C_STD)


    #define CCXXVER_LANG_STD_C99     199901L // (0X)
    #define CCXXVER_LANG_STD_C11     201112L // 1X
    #define CCXXVER_LANG_STD_C17     201710L // 1X
    #define CCXXVER_LANG_STD_C23     202311L // 2X
    // todo! update with final value
    #define CCXXVER_LANG_STD_C29     202911L // 2Y


    #if CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C99
        #define C_STD_NAME  "preC99"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C99
        #define C99
        #define C_STD_NAME  "C99"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C11
        #define C_STD_NAME  "preC11"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C11
        #define C11
        #define C_STD_NAME  "C11"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C17
        #define C_STD_NAME  "preC17"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C17
        #define C17
        #define C_STD_NAME  "C17"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C23
        #define C_STD_NAME  "preC23"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C23
        #define C23
        #define C_STD_NAME  "C23"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C29
        #define C_STD_NAME  "preC29"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C29
        #define C29
        #define C_STD_NAME  "C29"

    #else
        #define C_STD_NAME  "UNKNOWN"
    #endif


    #define C_STD_VERSION     C_STD_NAME "_" C_STD

#else
    #error "non standard compiler or unsupported C/CXX version (__cplusplus/__STDC__/__STDC_VERSION__ undefined)"
#endif
