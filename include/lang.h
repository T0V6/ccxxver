#pragma once


//////////////////////////////////////////////////////////
// private impl
//////////////////////////////////////////////////////////
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
    #define CCXXVER_COMPILER_CXX_STD_STR   CCXXVER_STR(CCXXVER_COMPILER_CXX_STD)


    // lang standard version values
    #define CCXXVER_LANG_STD_CXX11   201103L //0x (1x)
    #define CCXXVER_LANG_STD_CXX14   201402L //1y
    #define CCXXVER_LANG_STD_CXX17   201703L //1z
    #define CCXXVER_LANG_STD_CXX20   202002L //2a
    #define CCXXVER_LANG_STD_CXX23   202302L //2b
    #define CCXXVER_LANG_STD_CXX26   202603L //2c


    // active lang std
    #define CCXXVER_LANG_CXX11   0
    #define CCXXVER_LANG_CXX14   0
    #define CCXXVER_LANG_CXX17   0
    #define CCXXVER_LANG_CXX20   0
    #define CCXXVER_LANG_CXX23   0
    #define CCXXVER_LANG_CXX26   0


    #if CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX11
        #define CCXXVER_LANG_CXX_STD_NAME    "preCXX11"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX11
        #undef  CCXXVER_LANG_CXX11
        #define CCXXVER_LANG_CXX11           1
        #define CCXXVER_LANG_CXX_STD_NAME    "CXX11"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX14
        #define CCXXVER_LANG_CXX_STD_NAME    "preCXX14"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX14
        #undef  CCXXVER_LANG_CXX14
        #define CCXXVER_LANG_CXX14           1
        #define CCXXVER_LANG_CXX_STD_NAME    "CXX14"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX17
        #define CCXXVER_LANG_CXX_STD_NAME    "preCXX17"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX17
        #undef  CCXXVER_LANG_CXX17
        #define CCXXVER_LANG_CXX17           1
        #define CCXXVER_LANG_CXX_STD_NAME    "CXX17"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX20
        #define CCXXVER_LANG_CXX_STD_NAME    "preCXX20"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX20
        #undef  CCXXVER_LANG_CXX20
        #define CCXXVER_LANG_CXX20           1
        #define CCXXVER_LANG_CXX_STD_NAME    "CXX20"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX23
        #define CCXXVER_LANG_CXX_STD_NAME    "preCXX23"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX23
        #undef  CCXXVER_LANG_CXX23
        #define CCXXVER_LANG_CXX23           1
        #define CCXXVER_LANG_CXX_STD_NAME    "CXX23"

    #elif CCXXVER_COMPILER_CXX_STD < CCXXVER_LANG_STD_CXX26
        #define CCXXVER_LANG_CXX_STD_NAME    "preCXX26"

    #elif CCXXVER_COMPILER_CXX_STD == CCXXVER_LANG_STD_CXX26
        #undef  CCXXVER_LANG_CXX26
        #define CCXXVER_LANG_CXX26           1
        #define CCXXVER_LANG_CXX_STD_NAME    "CXX26"

    #else
        #error "unrecognized CXX standard"
    #endif


    #define CCXXVER_LANG_CXX_STD_VERSION   CCXXVER_LANG_CXX_STD_NAME "_" CCXXVER_COMPILER_CXX_STD_STR


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
    #define CCXXVER_COMPILER_C_STD_STR   CCXXVER_STR(CCXXVER_COMPILER_C_STD)


    // lang standard version values
    #define CCXXVER_LANG_STD_C99     199901L // (0X)
    #define CCXXVER_LANG_STD_C11     201112L // 1X
    #define CCXXVER_LANG_STD_C17     201710L // 1X
    #define CCXXVER_LANG_STD_C23     202311L // 2X
    // todo! update with final value
    #define CCXXVER_LANG_STD_C29     202911L // 2Y


    // active lang std
    #define CCXXVER_LANG_C99   0
    #define CCXXVER_LANG_C11   0
    #define CCXXVER_LANG_C17   0
    #define CCXXVER_LANG_C23   0
    #define CCXXVER_LANG_C29   0


    #if CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C99
        #define CCXXVER_LANG_C_STD_NAME  "preC99"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C99
        #undef  CCXXVER_LANG_C99
        #define CCXXVER_LANG_C99         1
        #define CCXXVER_LANG_C_STD_NAME  "C99"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C11
        #define CCXXVER_LANG_C_STD_NAME  "preC11"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C11
        #undef  CCXXVER_LANG_C11
        #define CCXXVER_LANG_C11         1
        #define CCXXVER_LANG_C_STD_NAME  "C11"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C17
        #define CCXXVER_LANG_C_STD_NAME  "preC17"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C17
        #undef  CCXXVER_LANG_C17
        #define CCXXVER_LANG_C17         1
        #define CCXXVER_LANG_C_STD_NAME  "C17"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C23
        #define CCXXVER_LANG_C_STD_NAME  "preC23"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C23
        #undef  CCXXVER_LANG_C23
        #define CCXXVER_LANG_C23         1
        #define CCXXVER_LANG_C_STD_NAME  "C23"

    #elif CCXXVER_COMPILER_C_STD < CCXXVER_LANG_STD_C29
        #define CCXXVER_LANG_C_STD_NAME  "preC29"

    #elif CCXXVER_COMPILER_C_STD == CCXXVER_LANG_STD_C29
        #undef  CCXXVER_LANG_C29
        #define CCXXVER_LANG_C29         1
        #define CCXXVER_LANG_C_STD_NAME  "C29"

    #else
        #error "unrecognized C standard"
    #endif


    #define CCXXVER_LANG_C_STD_VERSION   CCXXVER_LANG_C_STD_NAME "_" CCXXVER_COMPILER_C_STD_STR


#else
    #error "non standard compiler or unsupported C/CXX version (__cplusplus/__STDC__/__STDC_VERSION__ undefined)"
#endif





//////////////////////////////////////////////////////////
// public macros
//////////////////////////////////////////////////////////
#define CCXXVER_PUBLIC_LIST(X)    \
    X(COMPILER_CXX_STD)           \
    X(COMPILER_CXX_STD_STR)       \
    X(LANG_CXX_STD_NAME)          \
    X(LANG_CXX_STD_VERSION)       \
    X(LANG_CXX11)                 \
    X(LANG_CXX14)                 \
    X(LANG_CXX17)                 \
    X(LANG_CXX20)                 \
    X(LANG_CXX23)                 \
    X(LANG_CXX26)                 \
    X(COMPILER_C_STD)             \
    X(COMPILER_C_STD_STR)         \
    X(LANG_C_STD_NAME)            \
    X(LANG_C_STD_VERSION)         \
    X(LANG_C99)                   \
    X(LANG_C11)                   \
    X(LANG_C17)                   \
    X(LANG_C23)                   \
    X(LANG_C29)
