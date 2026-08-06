#pragma once


//////////////////////////////////////////////////////////
// private impl
//////////////////////////////////////////////////////////
#ifndef CCXXVER_STR
    #define CCXXVER_STR_IMPL(x) #x
    #define CCXXVER_STR(x)  CCXXVER_STR_IMPL(x)
#endif


// active compiler
#define CCXXVER_COMPILER_ICX            0
#define CCXXVER_COMPILER_ICC            0
#define CCXXVER_COMPILER_APPLE_CLANG    0
#define CCXXVER_COMPILER_AMD_AOCC       0
#define CCXXVER_COMPILER_CLANG          0
#define CCXXVER_COMPILER_GCC            0
#define CCXXVER_COMPILER_MSC            0
#define CCXXVER_COMPILER_COMPCERT       0
#define CCXXVER_COMPILER_TINYC          0


#ifdef __INTEL_LLVM_COMPILER
    #undef  CCXXVER_COMPILER_ICX
    #define CCXXVER_COMPILER_ICX            1
    #define CCXXVER_COMPILER_ICX_VERSION    CCXXVER_STR(__INTEL_LLVM_COMPILER)

    #define CCXXVER_COMPILER_NAME       "INTEL_ICX"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_ICX_VERSION

#elif defined(__INTEL_COMPILER)
    #undef  CCXXVER_COMPILER_ICC
    #define CCXXVER_COMPILER_ICC            1
    #define CCXXVER_COMPILER_ICC_VERSION    CCXXVER_STR(__INTEL_COMPILER)

    #define CCXXVER_COMPILER_NAME       "INTEL_ICC"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_ICC_VERSION

#elif defined(__clang__) && defined(__apple_build_version__)
    #undef  CCXXVER_COMPILER_APPLE_CLANG
    #define CCXXVER_COMPILER_APPLE_CLANG            1
    #define CCXXVER_COMPILER_APPLE_CLANG_VERSION    CCXXVER_STR(__apple_build_version__)

    #define CCXXVER_COMPILER_NAME       "APPLE_CLANG"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_APPLE_CLANG_VERSION

#elif defined(__AOCC__)
    #undef  CCXXVER_COMPILER_AMD_AOCC
    #define CCXXVER_COMPILER_AMD_AOCC            1
    #define CCXXVER_COMPILER_AMD_AOCC_VERSION    CCXXVER_STR(__AOCC__) "." CCXXVER_STR(__AOCC_MINOR__) "." CCXXVER_STR(__AOCC_PATCHLEVEL__)

    #define CCXXVER_COMPILER_NAME       "AMD_AOCC"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_AMD_AOCC_VERSION

#elif defined(__clang__)
    #undef  CCXXVER_COMPILER_CLANG
    #define CCXXVER_COMPILER_CLANG            1
    #define CCXXVER_COMPILER_CLANG_VERSION    CCXXVER_STR(__clang_major__) "." CCXXVER_STR(__clang_minor__) "." CCXXVER_STR(__clang_patchlevel__)

    #define CCXXVER_COMPILER_NAME       "LLVM_CLANG"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_CLANG_VERSION

#elif defined(__GNUC__) || defined(__GNUG__)
    #undef  CCXXVER_COMPILER_GCC
    #define CCXXVER_COMPILER_GCC            1
    #define CCXXVER_COMPILER_GCC_VERSION    CCXXVER_STR(__GNUC__) "." CCXXVER_STR(__GNUC_MINOR__) "." CCXXVER_STR(__GNUC_PATCHLEVEL__)

    #define CCXXVER_COMPILER_NAME       "GNU_GCC"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_GCC_VERSION

#elif defined(_MSC_VER)
    #undef  CCXXVER_COMPILER_MSC
    #define CCXXVER_COMPILER_MSC            1
    #define CCXXVER_COMPILER_MSC_VERSION    CCXXVER_STR(_MSC_FULL_VER) "." CCXXVER_STR(_MSC_BUILD)

    #define CCXXVER_COMPILER_NAME       "MICROSOFT_MSC"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_MSC_VERSION

#elif defined(__COMPCERT__)
    #undef  CCXXVER_COMPILER_COMPCERT
    #define CCXXVER_COMPILER_COMPCERT            1
    #define CCXXVER_COMPILER_COMPCERT_VERSION    CCXXVER_STR(__COMPCERT_MAJOR__) "." CCXXVER_STR(__COMPCERT_MINOR__)

    #define CCXXVER_COMPILER_NAME       "INRIA_COMPCERT"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_COMPCERT_VERSION

#elif defined(__TINYC__)
    #undef  CCXXVER_COMPILER_TINYC
    #define CCXXVER_COMPILER_TINYC            1
    #define CCXXVER_COMPILER_TINYC_VERSION    CCXXVER_STR(__TINYC__)

    #define CCXXVER_COMPILER_NAME       "BELLARD_TINYC"
    #define CCXXVER_COMPILER_VERSION    CCXXVER_COMPILER_TINYC_VERSION

#else
    #error "non standard or unsupported compiler, compiler version or variant"
#endif





//////////////////////////////////////////////////////////
// public macros
//////////////////////////////////////////////////////////
#define CCXXVER_PUBLIC_LIST(X)         \
    X(COMPILER_NAME)                   \
    X(COMPILER_VERSION)                \
    X(COMPILER_ICX)                    \
    X(COMPILER_ICX_VERSION)            \
    X(COMPILER_ICC)                    \
    X(COMPILER_ICC_VERSION)            \
    X(COMPILER_APPLE_CLANG)            \
    X(COMPILER_APPLE_CLANG_VERSION)    \
    X(COMPILER_AMD_AOCC)               \
    X(COMPILER_AMD_AOCC_VERSION)       \
    X(COMPILER_CLANG)                  \
    X(COMPILER_CLANG_VERSION)          \
    X(COMPILER_GCC)                    \
    X(COMPILER_GCC_VERSION)            \
    X(COMPILER_MSC)                    \
    X(COMPILER_MSC_VERSION)            \
    X(COMPILER_COMPCERT)               \
    X(COMPILER_COMPCERT_VERSION)       \
    X(COMPILER_TINYC)                  \
    X(COMPILER_TINYC_VERSION)
