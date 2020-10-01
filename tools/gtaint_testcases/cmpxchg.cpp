#include "testcase.h"

static int cmpxchg1() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg ax,ax\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg ax,ax;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}
static int cmpxchg2() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg ax,cx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg ax,cx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg3() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg cx,ax\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg cx,ax;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg4() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x2;
    rdx_in = 0x3;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg cx,dx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg cx,dx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg5() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x2;
    rdx_in = 0x3;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg dx,cx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg dx,cx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 16 17 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}



static int cmpxchg6() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg eax,eax\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg eax,eax;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}
static int cmpxchg7() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg eax,ecx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg eax,ecx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg8() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg ecx,eax\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg ecx,eax;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg9() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x2;
    rdx_in = 0x3;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg ecx,edx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg ecx,edx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg10() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x2;
    rdx_in = 0x3;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg edx,ecx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg edx,ecx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 16 17 18 19 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}



static int cmpxchg11() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg rax,rax\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg rax,rax;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}
static int cmpxchg12() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg rax,rcx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg rax,rcx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg13() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x1;
    rdx_in = 0x0;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg rcx,rax\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg rcx,rax;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg14() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x2;
    rdx_in = 0x3;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg rcx,rdx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg rcx,rdx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}

static int cmpxchg15() {
    volatile uint64_t rax_in, rcx_in, rdx_in;
    volatile uint64_t rax_out, rcx_out, rdx_out;

    rax_in = 0x1;
    rcx_in = 0x2;
    rdx_in = 0x3;

    rax_out = 0x0;
    rcx_out = 0x0;
    rdx_out = 0x0;

    printf("%s:     cmpxchg rdx,rcx\n", __func__);
    fflush(stdout);
    __gtaint_reset();
    __gtaint_setn(&rax_in, sizeof(rax_in));
    __gtaint_setn(&rcx_in, sizeof(rcx_in));
    __gtaint_setn(&rdx_in, sizeof(rdx_in));
    asm volatile("cmpxchg rdx,rcx;\n"
                 : "=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
                 : "a"(rax_in), "c"(rcx_in), "d"(rdx_in));
    int passed0, passed1, passed2;
    __gtaint_assert(&rax_out, sizeof(rax_out), "{ 16 17 18 19 20 21 22 23 }", &passed0);
    __gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
    __gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
    return passed0 && passed1 && passed2;
}





static void __attribute__((noinline, constructor)) init() {
    add_testcase(cmpxchg1);
    add_testcase(cmpxchg2);
    add_testcase(cmpxchg3);
    add_testcase(cmpxchg4);
    add_testcase(cmpxchg5);

    add_testcase(cmpxchg6);
    add_testcase(cmpxchg7);
    add_testcase(cmpxchg8);
    add_testcase(cmpxchg9);
    add_testcase(cmpxchg10);

    add_testcase(cmpxchg11);
    add_testcase(cmpxchg12);
    add_testcase(cmpxchg13);
    add_testcase(cmpxchg14);
    add_testcase(cmpxchg15);
}
