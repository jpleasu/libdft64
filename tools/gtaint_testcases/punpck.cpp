#include "testcase.h"

#include <x86intrin.h>

static int punpckl1() {
    int passed = 1;

    uint64_t x[2] = { 0, 0 }, y[2] = { 0, 0 }, z[2] = { 0, 0 };

    printf("%s:     punpcklbw xmm0,xmm1\n", __func__);
    fflush(stdout);

    __gtaint_reset();

    __gtaint_setn(&x, sizeof(x));
    __gtaint_setn(&y, sizeof(y));
    __gtaint_setn(&z, sizeof(z));

    asm volatile("movq xmm0, %1;\n"
                 "movq xmm1, %2;\n"
                 "punpcklbw xmm0,xmm1;\n"
                 "movq %0, xmm0"
                 : "=m"(z[0])
                 : "m"(x[0]), "m"(y[0])
                 : "xmm0", "xmm1");

    for (uint32_t i = 0; i < 8; ++i) {
        ASSERT_TAGGED((char *)&z + 2 * i, { i });
        ASSERT_TAGGED((char *)&z + 2 * i + 1, { 16 + i });
    }

    return passed;
}

static int punpckl2() {
    int passed = 1;

    volatile uint64_t x[2] = { 0, 0 }, y[2] = { 0, 0 }, z[2] = { 0, 0 };

    printf("%s:     punpcklwd xmm0,xmm1\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    __gtaint_setn(&x, sizeof(x));
    __gtaint_setn(&y, sizeof(y));
    __gtaint_setn(&z, sizeof(z));

    asm volatile("movq xmm0, %1;\n"
                 "movq xmm1, %2;\n"
                 "punpcklwd xmm0,xmm1;\n"
                 "movq %0, xmm0"
                 : "=m"(z[0])
                 : "m"(x[0]), "m"(y[0])
                 : "xmm0", "xmm1");

    for (uint32_t i = 0; i < 4; ++i) {
        ASSERT_TAGGED((char *)&z + 4 * i, { 2 * i });
        ASSERT_TAGGED((char *)&z + 4 * i + 1, { 2 * i + 1 });
        ASSERT_TAGGED((char *)&z + 4 * i + 2, { 16 + 2 * i });
        ASSERT_TAGGED((char *)&z + 4 * i + 3, { 16 + 2 * i + 1 });
    }
    return passed;
}

static void __attribute__((noinline, constructor)) init() {
    add_testcase(punpckl1);
    add_testcase(punpckl2);
}
