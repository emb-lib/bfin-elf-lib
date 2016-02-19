# ADI GNU Toolchain (bfin-elf) support library for bare-metal C/C++ projects

Main goal is to fix all toolchain lacks for C++ bare-metal  applications.

##  Contents

* Exceptions support.
* PLL/clock management routines.
* C++ constructor call loop support (added "weak" `_init()` fucntion required by `__libc_init_array)`.
* Several intrinsic functions.

## Details

### Exceptions support

ADI GNU toolchain does not have code to register exception/interrut hanlders. There are two files added to fix this lack:

* exc.h;
* reg_handler.c

### PLL/clock mamagement routines

`_pll_set_system_clocks` and `_pll_set_system_vco` from file `pwrclk.S`

### C++ constructor call loop

GNU toolchain uses function `__libc_init_array` from newlib. The function performs call of low-level function `_init()` before constructor loop call. But `_init()` does not exist in toolchain library, so the using of C++ global/static objects (i.e. call of `__libc_init_array`) causes a link error. To fix this error 'weak' `_init()` function added to this support library.

### Intinsic fuctions

ADI GNU toolchain has some built-in functions to support low-level platform-specific features. Unfortunately, not all such functions have been ported from VDSP++. This library contains `read_cycles_reg` to read processor's CYCLES register.

Besides, ADI GNU toolchain realization of `cli/sei` built-in functions are erroneous: see bug description https://sourceforge.net/p/adi-toolchain/bugs/69. This library offers replacement for `cli/sei` built-ins (macros) as inline functions `__cli/__sti`.
