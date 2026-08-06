#pragma once


#define CCXXVER_STR_IMPL(x) #x
#define CCXXVER_STR(x)  CCXXVER_STR_IMPL(x)


#ifdef __INTEL_LLVM_COMPILER
    #define ICX
    #define ICX_VERSION     CCXXVER_STR(__INTEL_LLVM_COMPILER)

    #define COMPILER_NAME       "INTEL_ICX"
    #define COMPILER_VERSION    ICX_VERSION

#elif defined(__INTEL_COMPILER)
    #define ICC
    #define ICC_VERSION     CCXXVER_STR(__INTEL_COMPILER)

    #define COMPILER_NAME       "INTEL_ICC"
    #define COMPILER_VERSION    ICC_VERSION

#elif defined(__clang__) && defined(__apple_build_version__)
    #define APPLE_CLANG
    #define APPLE_CLANG_VERSION     CCXXVER_STR(__apple_build_version__)

    #define COMPILER_NAME       "APPLE_CLANG"
    #define COMPILER_VERSION    APPLE_CLANG_VERSION

#elif defined(__AOCC__)
    #define AMD_AOCC
    #define AMD_AOCC_VERSION     CCXXVER_STR(__AOCC__) "." CCXXVER_STR(__AOCC_MINOR__) "." CCXXVER_STR(__AOCC_PATCHLEVEL__)

    #define COMPILER_NAME       "AMD_AOCC"
    #define COMPILER_VERSION    AMD_AOCC_VERSION

#elif defined(__clang__)
    #define CLANG
    #define CLANG_VERSION   CCXXVER_STR(__clang_major__) "." CCXXVER_STR(__clang_minor__) "." CCXXVER_STR(__clang_patchlevel__)

    #define COMPILER_NAME       "LLVM_CLANG"
    #define COMPILER_VERSION    CLANG_VERSION

#elif defined(__GNUC__) || defined(__GNUG__)
    #define GCC
    #define GCC_VERSION     CCXXVER_STR(__GNUC__) "." CCXXVER_STR(__GNUC_MINOR__) "." CCXXVER_STR(__GNUC_PATCHLEVEL__)

    #define COMPILER_NAME       "GNU_GCC"
    #define COMPILER_VERSION    GCC_VERSION

#elif defined(_MSC_VER)
    #define MSC
    #define MSC_VERSION     CCXXVER_STR(_MSC_FULL_VER) "." CCXXVER_STR(_MSC_BUILD)

    #define COMPILER_NAME       "MICROSOFT_MSC"
    #define COMPILER_VERSION    MSC_VERSION

#elif defined(__COMPCERT__)
    #define COMPCERT
    #define COMPCERT_VERSION    CCXXVER_STR(__COMPCERT_MAJOR__) "." CCXXVER_STR(__COMPCERT_MINOR__)

    #define COMPILER_NAME       "INRIA_COMPCERT"
    #define COMPILER_VERSION    COMPCERT_VERSION

#elif defined(__TINYC__)
    #define TINYC
    #define TINYC_VERSION   CCXXVER_STR(__TINYC__)

    #define COMPILER_NAME       "BELLARD_TINYC"
    #define COMPILER_VERSION    TINYC_VERSION

#else
    #error "non standard or unsupported compiler, compiler version or variant"
#endif
