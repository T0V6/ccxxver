# C/C++ simple build metadata

## feats
- [comp.h](include/comp.h): get compiler name and version
- [lang.h](include/lang.h): get c/c++ language version
- [ver.h](include/ver.h): project version header
- [gen_header.sh](gen_header.sh): generate a single or multiple headers with a custom prefix for build metadata macros. outputs `<proj>_metadata.h` or `<proj>_comp.h`, `<proj>_lang.h`, `<proj>_ver.h`
    - [gen_ver.sh](script/gen_ver.sh): generate custom project version header
    - [gen_lang.sh](script/gen_lang.sh): generate custom project language header
    - [gen_comp.sh](script/gen_comp.sh): generate custom project compiler header

---

## limitations
- for C lang versions prior to C99 it will show `preC99`
- for C++ lang versions prior to C++11 it will show `preCXX11`
- only a few (mainstream) compilers are supported, therefore it can error or output wrong info on some

---

## examples
- `clang example/test.c -o test_c --std=c23 -I.`
- `clang++ example/test.cxx -o test_cxx --std=c++26 -I.`
