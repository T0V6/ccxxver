# C/C++ simple versioning

## feats
- [std_v.h](include/std_v.h): get c/c++ language version
- [version.h](include/version.h): system version header (generated via [versioning.sh](script/versioning.sh))
- [versioning.sh](script/versioning.sh): generate system version and fill [version.h](include/version.h)

---

## limitations
- for C lang versions prior to C99 it will show `preC99`
- for C++ lang versions prior to C++11 it will show `preCXX11`

---

## examples
- `clang example/test.c -o test_c --std=c23 -I .`
- `clang++ example/test.cxx -o test_cxx --std=c++26 -I .`
