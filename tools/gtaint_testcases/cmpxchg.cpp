#include "testcase.h"

// cmpxchg d,s
//   if a=d then d<-s
//   else a<-d

static int testcase0() {
    int passed = 1;

    printf("%s     cmpxchg al,al\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile("mov AL,%1;\n"
                 "cmpxchg al,al;\n" // <--
                 "mov %0,AL;\n"
                 : "=m"(outAL)
                 : "m"(inAL)
                 : "al");

    ASSERT_TAGGED((char *)&outAL + 0, { 0 });
    return passed;
}

static int testcase1() {
    int passed = 1;

    printf("%s     cmpxchg al,cl\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile("mov AL,%1;\n"
                 "mov CL,%2;\n"
                 "cmpxchg al,cl;\n" // <--
                 "mov %0,AL;\n"
                 : "=m"(outAL)
                 : "m"(inAL), "m"(inCL)
                 : "al", "cl");

    ASSERT_TAGGED((char *)&outAL + 0, { 1 });
    return passed;
}

static int testcase2() {
    int passed = 1;

    printf("%s     cmpxchg ax,ax\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile("mov AX,%1;\n"
                 "cmpxchg ax,ax;\n" // <--
                 "mov %0,AX;\n"
                 : "=m"(outAX)
                 : "m"(inAX)
                 : "ax");

    ASSERT_TAGGED((char *)&outAX + 0, { 0 });
    ASSERT_TAGGED((char *)&outAX + 1, { 1 });
    return passed;
}

static int testcase3() {
    int passed = 1;

    printf("%s     cmpxchg ax,cx\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile("mov AX,%1;\n"
                 "mov CX,%2;\n"
                 "cmpxchg ax,cx;\n" // <--
                 "mov %0,AX;\n"
                 : "=m"(outAX)
                 : "m"(inAX), "m"(inCX)
                 : "ax", "cx");

    ASSERT_TAGGED((char *)&outAX + 0, { 2 });
    ASSERT_TAGGED((char *)&outAX + 1, { 3 });
    return passed;
}

static int testcase4() {
    int passed = 1;

    printf("%s     cmpxchg cl,al\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 2;
    uint8_t outAL = 1;
    uint8_t outCL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile("mov AL,%2;\n"
                 "mov CL,%3;\n"
                 "cmpxchg cl,al;\n" // <--
                 "mov %0,AL;\n"
                 "mov %1,CL;\n"
                 : "=m"(outAL), "=m"(outCL)
                 : "m"(inAL), "m"(inCL)
                 : "al", "cl");

    ASSERT_TAGGED((char *)&outAL + 0, { 1 });
    ASSERT_TAGGED((char *)&outCL + 0, { 1 });
    return passed;
}

static int testcase5() {
    int passed = 1;

    printf("%s     cmpxchg cx,ax\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 2;
    uint16_t outAX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile("mov AX,%2;\n"
                 "mov CX,%3;\n"
                 "cmpxchg cx,ax;\n" // <--
                 "mov %0,AX;\n"
                 "mov %1,CX;\n"
                 : "=m"(outAX), "=m"(outCX)
                 : "m"(inAX), "m"(inCX)
                 : "ax", "cx");

    ASSERT_TAGGED((char *)&outAX + 0, { 2 });
    ASSERT_TAGGED((char *)&outAX + 1, { 3 });
    ASSERT_TAGGED((char *)&outCX + 0, { 2 });
    ASSERT_TAGGED((char *)&outCX + 1, { 3 });
    return passed;
}

static int testcase6() {
    int passed = 1;

    printf("%s     cmpxchg eax,eax\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t outEAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile("mov EAX,%1;\n"
                 "cmpxchg eax,eax;\n" // <--
                 "mov %0,EAX;\n"
                 : "=m"(outEAX)
                 : "m"(inEAX)
                 : "eax");

    ASSERT_TAGGED((char *)&outEAX + 0, { 0 });
    ASSERT_TAGGED((char *)&outEAX + 1, { 1 });
    ASSERT_TAGGED((char *)&outEAX + 2, { 2 });
    ASSERT_TAGGED((char *)&outEAX + 3, { 3 });
    return passed;
}

static int testcase7() {
    int passed = 1;

    printf("%s     cmpxchg eax,ecx\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint32_t outEAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile("mov EAX,%1;\n"
                 "mov ECX,%2;\n"
                 "cmpxchg eax,ecx;\n" // <--
                 "mov %0,EAX;\n"
                 : "=m"(outEAX)
                 : "m"(inEAX), "m"(inECX)
                 : "eax", "ecx");

    ASSERT_TAGGED((char *)&outEAX + 0, { 4 });
    ASSERT_TAGGED((char *)&outEAX + 1, { 5 });
    ASSERT_TAGGED((char *)&outEAX + 2, { 6 });
    ASSERT_TAGGED((char *)&outEAX + 3, { 7 });
    return passed;
}

static int testcase8() {
    int passed = 1;

    printf("%s     cmpxchg ecx,eax\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 2;
    uint32_t outEAX = 1;
    uint32_t outECX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile("mov EAX,%2;\n"
                 "mov ECX,%3;\n"
                 "cmpxchg ecx,eax;\n" // <--
                 "mov %0,EAX;\n"
                 "mov %1,ECX;\n"
                 : "=m"(outEAX), "=m"(outECX)
                 : "m"(inEAX), "m"(inECX)
                 : "eax", "ecx");

    ASSERT_TAGGED((char *)&outEAX + 0, { 4 });
    ASSERT_TAGGED((char *)&outEAX + 1, { 5 });
    ASSERT_TAGGED((char *)&outEAX + 2, { 6 });
    ASSERT_TAGGED((char *)&outEAX + 3, { 7 });
    ASSERT_TAGGED((char *)&outECX + 0, { 4 });
    ASSERT_TAGGED((char *)&outECX + 1, { 5 });
    ASSERT_TAGGED((char *)&outECX + 2, { 6 });
    ASSERT_TAGGED((char *)&outECX + 3, { 7 });
    return passed;
}

static int testcase9() {
    int passed = 1;

    printf("%s     cmpxchg rax,rax\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile("mov RAX,%1;\n"
                 "cmpxchg rax,rax;\n" // <--
                 "mov %0,RAX;\n"
                 : "=m"(outRAX)
                 : "m"(inRAX)
                 : "rax");

    ASSERT_TAGGED((char *)&outRAX + 0, { 0 });
    ASSERT_TAGGED((char *)&outRAX + 1, { 1 });
    ASSERT_TAGGED((char *)&outRAX + 2, { 2 });
    ASSERT_TAGGED((char *)&outRAX + 3, { 3 });
    ASSERT_TAGGED((char *)&outRAX + 4, { 4 });
    ASSERT_TAGGED((char *)&outRAX + 5, { 5 });
    ASSERT_TAGGED((char *)&outRAX + 6, { 6 });
    ASSERT_TAGGED((char *)&outRAX + 7, { 7 });
    return passed;
}

static int testcase10() {
    int passed = 1;

    printf("%s     cmpxchg rax,rcx\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile("mov RAX,%1;\n"
                 "mov RCX,%2;\n"
                 "cmpxchg rax,rcx;\n" // <--
                 "mov %0,RAX;\n"
                 : "=m"(outRAX)
                 : "m"(inRAX), "m"(inRCX)
                 : "rax", "rcx");

    ASSERT_TAGGED((char *)&outRAX + 0, { 8 });
    ASSERT_TAGGED((char *)&outRAX + 1, { 9 });
    ASSERT_TAGGED((char *)&outRAX + 2, { 10 });
    ASSERT_TAGGED((char *)&outRAX + 3, { 11 });
    ASSERT_TAGGED((char *)&outRAX + 4, { 12 });
    ASSERT_TAGGED((char *)&outRAX + 5, { 13 });
    ASSERT_TAGGED((char *)&outRAX + 6, { 14 });
    ASSERT_TAGGED((char *)&outRAX + 7, { 15 });
    return passed;
}

static int testcase11() {
    int passed = 1;

    printf("%s     cmpxchg rcx,rax\n", __func__);
    fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 2;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile("mov RAX,%2;\n"
                 "mov RCX,%3;\n"
                 "cmpxchg rcx,rax;\n" // <--
                 "mov %0,RAX;\n"
                 "mov %1,RCX;\n"
                 : "=m"(outRAX), "=m"(outRCX)
                 : "m"(inRAX), "m"(inRCX)
                 : "rax", "rcx");

    ASSERT_TAGGED((char *)&outRAX + 0, { 8 });
    ASSERT_TAGGED((char *)&outRAX + 1, { 9 });
    ASSERT_TAGGED((char *)&outRAX + 2, { 10 });
    ASSERT_TAGGED((char *)&outRAX + 3, { 11 });
    ASSERT_TAGGED((char *)&outRAX + 4, { 12 });
    ASSERT_TAGGED((char *)&outRAX + 5, { 13 });
    ASSERT_TAGGED((char *)&outRAX + 6, { 14 });
    ASSERT_TAGGED((char *)&outRAX + 7, { 15 });

    ASSERT_TAGGED((char *)&outRCX + 0, { 8 });
    ASSERT_TAGGED((char *)&outRCX + 1, { 9 });
    ASSERT_TAGGED((char *)&outRCX + 2, { 10 });
    ASSERT_TAGGED((char *)&outRCX + 3, { 11 });
    ASSERT_TAGGED((char *)&outRCX + 4, { 12 });
    ASSERT_TAGGED((char *)&outRCX + 5, { 13 });
    ASSERT_TAGGED((char *)&outRCX + 6, { 14 });
    ASSERT_TAGGED((char *)&outRCX + 7, { 15 });
    return passed;
}

static void __attribute__((noinline, constructor)) init() {
    add_testcase(testcase0);
    add_testcase(testcase1);
    add_testcase(testcase2);
    add_testcase(testcase3);
    add_testcase(testcase4);
    add_testcase(testcase5);
    add_testcase(testcase6);
    add_testcase(testcase7);
    add_testcase(testcase8);
    add_testcase(testcase9);
    add_testcase(testcase10);
    add_testcase(testcase11);
}
