#include "testcase.h"

static int testcase() {
    volatile int x,y;
    __gtaint_reset();
    __gtaint_setn(&x,sizeof(x));
    asm volatile (
            "mov %0,%1;\n"
            :"=r"(y)
            :"r"(x)
    );
    int passed;
    __gtaint_assert(&y, sizeof(y),  "{ 0 1 2 3 }", &passed);
    return passed;
}

static void __attribute__((noinline, constructor)) init() {
    add_testcase(testcase);
}
