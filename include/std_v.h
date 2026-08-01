#pragma once


#define STR_IMPL(x) #x
#define STR(x)  STR_IMPL(x)


#ifdef __cplusplus
    ////////////////
    // CXX
    ////////////////
    #define _COMPILER_CXX_STD   __cplusplus //__cplusplus fmt is <year><month>


    #define CXX_STD STR(_COMPILER_CXX_STD)


    #define _STD_CXX11   201103L //0x (1x)
    #define _STD_CXX14   201402L //1y
    #define _STD_CXX17   201703L //1z
    #define _STD_CXX20   202002L //2a
    #define _STD_CXX23   202302L //2b
    #define _STD_CXX26   202603L //2c


    #if _COMPILER_CXX_STD < _STD_CXX11
        #define CXX_STD_NAME    "preCXX11"

    #elif _COMPILER_CXX_STD == _STD_CXX11
        #define CXX11
        #define CXX_STD_NAME    "CXX11"

    #elif _COMPILER_CXX_STD < _STD_CXX14
        #define CXX_STD_NAME    "preCXX14"

    #elif _COMPILER_CXX_STD == _STD_CXX14
        #define CXX14
        #define CXX_STD_NAME    "CXX14"

    #elif _COMPILER_CXX_STD < _STD_CXX17
        #define CXX_STD_NAME    "preCXX17"

    #elif _COMPILER_CXX_STD == _STD_CXX17
        #define CXX17
        #define CXX_STD_NAME    "CXX17"

    #elif _COMPILER_CXX_STD < _STD_CXX20
        #define CXX_STD_NAME    "preCXX20"

    #elif _COMPILER_CXX_STD == _STD_CXX20
        #define CXX20
        #define CXX_STD_NAME    "CXX20"

    #elif _COMPILER_CXX_STD < _STD_CXX23
        #define CXX_STD_NAME    "preCXX23"

    #elif _COMPILER_CXX_STD == _STD_CXX23
        #define CXX23
        #define CXX_STD_NAME    "CXX23"

    #elif _COMPILER_CXX_STD < _STD_CXX26
        #define CXX_STD_NAME    "preCXX26"

    #elif _COMPILER_CXX_STD == _STD_CXX26
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
        #define _COMPILER_C_STD __STDC_VERSION__    //__STDC_VERSION__ fmt is <year><month>
    #else
        // __STDC__ && !__STDC_VERSION__
        #define _COMPILER_C_STD 198912L //default to c89
    #endif


    #define C_STD STR(_COMPILER_C_STD)


    #define _STD_C99     199901L // (0X)
    #define _STD_C11     201112L // 1X
    #define _STD_C17     201710L // 1X
    #define _STD_C23     202311L // 2X
    // todo! update with final value
    #define _STD_C29     202911L // 2Y


    #if _COMPILER_C_STD < _STD_C99
        #define C_STD_NAME  "preC99"

    #elif _COMPILER_C_STD == _STD_C99
        #define C99
        #define C_STD_NAME  "C99"

    #elif _COMPILER_C_STD < _STD_C11
        #define C_STD_NAME  "preC11"

    #elif _COMPILER_C_STD == _STD_C11
        #define C11
        #define C_STD_NAME  "C11"

    #elif _COMPILER_C_STD < _STD_C17
        #define C_STD_NAME  "preC17"

    #elif _COMPILER_C_STD == _STD_C17
        #define C17
        #define C_STD_NAME  "C17"

    #elif _COMPILER_C_STD < _STD_C23
        #define C_STD_NAME  "preC23"

    #elif _COMPILER_C_STD == _STD_C23
        #define C23
        #define C_STD_NAME  "C23"

    #elif _COMPILER_C_STD < _STD_C29
        #define C_STD_NAME  "preC29"

    #elif _COMPILER_C_STD == _STD_C29
        #define C29
        #define C_STD_NAME  "C29"

    #else
        #define C_STD_NAME  "UNKNOWN"
    #endif


    #define C_STD_VERSION     C_STD_NAME "_" C_STD

#else
    #error "non standard compiler or unsupported C/CXX version (__cplusplus/__STDC__/__STDC_VERSION__ undefined)"
#endif
