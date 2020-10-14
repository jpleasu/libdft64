#include "testcase.h"

static int testcase0() {
    int passed = 1;

    printf("%s     adc    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "adc    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase1() {
    int passed = 1;

    printf("%s     adc    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "adc    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase2() {
    int passed = 1;

    printf("%s     adc    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "adc    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase3() {
    int passed = 1;

    printf("%s     adc    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "adc    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase4() {
    int passed = 1;

    printf("%s     adc    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "adc    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase5() {
    int passed = 1;

    printf("%s     adc    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "adc    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase6() {
    int passed = 1;

    printf("%s     adc    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "adc    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase7() {
    int passed = 1;

    printf("%s     adc    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "adc    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase8() {
    int passed = 1;

    printf("%s     adc    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "adc    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase9() {
    int passed = 1;

    printf("%s     adc    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "adc    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase10() {
    int passed = 1;

    printf("%s     adc    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "adc    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase11() {
    int passed = 1;

    printf("%s     adc    ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "adc    ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase12() {
    int passed = 1;

    printf("%s     adc    ax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "adc    ax,0xffff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase13() {
    int passed = 1;

    printf("%s     adc    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "adc    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase14() {
    int passed = 1;

    printf("%s     adc    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "adc    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    return passed;
}

static int testcase15() {
    int passed = 1;

    printf("%s     adc    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "adc    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase16() {
    int passed = 1;

    printf("%s     adc    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "adc    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase17() {
    int passed = 1;

    printf("%s     adc    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "adc    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase18() {
    int passed = 1;

    printf("%s     adc    eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "adc    eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase19() {
    int passed = 1;

    printf("%s     adc    eax,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "adc    eax,0xffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase20() {
    int passed = 1;

    printf("%s     adc    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "adc    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase21() {
    int passed = 1;

    printf("%s     adc    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "adc    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase22() {
    int passed = 1;

    printf("%s     adc    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "adc    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase23() {
    int passed = 1;

    printf("%s     adc    rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "adc    rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase24() {
    int passed = 1;

    printf("%s     adc    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "adc    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase25() {
    int passed = 1;

    printf("%s     adc    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "adc    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase26() {
    int passed = 1;

    printf("%s     add    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "add    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase27() {
    int passed = 1;

    printf("%s     add    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "add    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase28() {
    int passed = 1;

    printf("%s     add    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "add    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase29() {
    int passed = 1;

    printf("%s     add    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "add    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase30() {
    int passed = 1;

    printf("%s     add    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "add    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase31() {
    int passed = 1;

    printf("%s     add    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "add    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase32() {
    int passed = 1;

    printf("%s     add    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "add    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase33() {
    int passed = 1;

    printf("%s     add    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "add    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase34() {
    int passed = 1;

    printf("%s     add    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "add    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase35() {
    int passed = 1;

    printf("%s     add    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "add    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase36() {
    int passed = 1;

    printf("%s     add    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "add    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase37() {
    int passed = 1;

    printf("%s     add    ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "add    ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase38() {
    int passed = 1;

    printf("%s     add    ax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "add    ax,0xffff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase39() {
    int passed = 1;

    printf("%s     add    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "add    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase40() {
    int passed = 1;

    printf("%s     add    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "add    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    return passed;
}

static int testcase41() {
    int passed = 1;

    printf("%s     add    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "add    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase42() {
    int passed = 1;

    printf("%s     add    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "add    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase43() {
    int passed = 1;

    printf("%s     add    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "add    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase44() {
    int passed = 1;

    printf("%s     add    eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "add    eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase45() {
    int passed = 1;

    printf("%s     add    eax,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "add    eax,0xffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase46() {
    int passed = 1;

    printf("%s     add    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "add    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase47() {
    int passed = 1;

    printf("%s     add    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "add    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase48() {
    int passed = 1;

    printf("%s     add    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "add    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase49() {
    int passed = 1;

    printf("%s     add    rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "add    rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase50() {
    int passed = 1;

    printf("%s     add    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "add    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase51() {
    int passed = 1;

    printf("%s     add    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "add    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase52() {
    int passed = 1;

    printf("%s     and    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "and    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, { });
    return passed;
}

static int testcase53() {
    int passed = 1;

    printf("%s     and    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "and    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase54() {
    int passed = 1;

    printf("%s     and    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "and    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase55() {
    int passed = 1;

    printf("%s     and    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "and    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase56() {
    int passed = 1;

    printf("%s     and    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "and    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase57() {
    int passed = 1;

    printf("%s     and    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "and    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase58() {
    int passed = 1;

    printf("%s     and    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "and    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase59() {
    int passed = 1;

    printf("%s     and    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "and    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase60() {
    int passed = 1;

    printf("%s     and    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "and    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase61() {
    int passed = 1;

    printf("%s     and    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "and    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase62() {
    int passed = 1;

    printf("%s     and    ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "and    ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase63() {
    int passed = 1;

    printf("%s     and    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "and    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase64() {
    int passed = 1;

    printf("%s     and    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "and    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,3});
    return passed;
}

static int testcase65() {
    int passed = 1;

    printf("%s     and    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "and    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase66() {
    int passed = 1;

    printf("%s     and    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "and    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase67() {
    int passed = 1;

    printf("%s     and    eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "and    eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase68() {
    int passed = 1;

    printf("%s     and    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "and    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase69() {
    int passed = 1;

    printf("%s     and    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "and    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase70() {
    int passed = 1;

    printf("%s     and    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "and    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase71() {
    int passed = 1;

    printf("%s     and    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "and    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase72() {
    int passed = 1;

    printf("%s     and    rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "and    rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase73() {
    int passed = 1;

    printf("%s     and    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "and    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase74() {
    int passed = 1;

    printf("%s     and    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "and    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,15});
    return passed;
}

static int testcase75() {
    int passed = 1;

    printf("%s     andn   eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "andn   eax,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase76() {
    int passed = 1;

    printf("%s     andn   eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "andn   eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase77() {
    int passed = 1;

    printf("%s     andn   eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "andn   eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase78() {
    int passed = 1;

    printf("%s     andn   eax,ecx,edx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov EDX,%2;\n"
        "andn   eax,ecx,edx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inEDX)
        :"rax","ecx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase79() {
    int passed = 1;

    printf("%s     andn   rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "andn   rax,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase80() {
    int passed = 1;

    printf("%s     andn   rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "andn   rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,15});
    return passed;
}

static int testcase81() {
    int passed = 1;

    printf("%s     andn   rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "andn   rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase82() {
    int passed = 1;

    printf("%s     andn   rax,rcx,rdx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov RDX,%2;\n"
        "andn   rax,rcx,rdx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,15});
    return passed;
}

static int testcase83() {
    int passed = 1;

    printf("%s     bextr  eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "bextr  eax,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase84() {
    int passed = 1;

    printf("%s     bextr  eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint16_t inCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CX,%2;\n"
        "bextr  eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCX)
        :"rax","cx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase85() {
    int passed = 1;

    printf("%s     bextr  eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "bextr  eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase86() {
    int passed = 1;

    printf("%s     bextr  eax,ecx,edx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint16_t inDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inDX, 2);
    asm volatile (
        "mov ECX,%1;\n"
        "mov DX,%2;\n"
        "bextr  eax,ecx,edx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inDX)
        :"rax","ecx","dx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase87() {
    int passed = 1;

    printf("%s     bextr  rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "bextr  rax,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,7});
    return passed;
}

static int testcase88() {
    int passed = 1;

    printf("%s     bextr  rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint16_t inCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CX,%2;\n"
        "bextr  rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCX)
        :"rax","cx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8,9});
    return passed;
}

static int testcase89() {
    int passed = 1;

    printf("%s     bextr  rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "bextr  rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,7});
    return passed;
}

static int testcase90() {
    int passed = 1;

    printf("%s     bextr  rax,rcx,rdx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint16_t inDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inDX, 2);
    asm volatile (
        "mov RCX,%1;\n"
        "mov DX,%2;\n"
        "bextr  rax,rcx,rdx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inDX)
        :"rax","rcx","dx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8,9});
    return passed;
}

static int testcase91() {
    int passed = 1;

    printf("%s     blsi   eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "blsi   eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase92() {
    int passed = 1;

    printf("%s     blsi   eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "blsi   eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase93() {
    int passed = 1;

    printf("%s     blsi   rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "blsi   rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase94() {
    int passed = 1;

    printf("%s     blsi   rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "blsi   rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase95() {
    int passed = 1;

    printf("%s     blsmsk eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "blsmsk eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase96() {
    int passed = 1;

    printf("%s     blsmsk eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "blsmsk eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase97() {
    int passed = 1;

    printf("%s     blsmsk rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "blsmsk rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase98() {
    int passed = 1;

    printf("%s     blsmsk rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "blsmsk rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase99() {
    int passed = 1;

    printf("%s     blsr   eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "blsr   eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase100() {
    int passed = 1;

    printf("%s     blsr   eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "blsr   eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase101() {
    int passed = 1;

    printf("%s     blsr   rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "blsr   rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase102() {
    int passed = 1;

    printf("%s     blsr   rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "blsr   rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase103() {
    int passed = 1;

    printf("%s     bswap  eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "bswap  eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {3});
    ASSERT_TAGGED((char *)&outRAX + 1, {2});
    ASSERT_TAGGED((char *)&outRAX + 2, {1});
    ASSERT_TAGGED((char *)&outRAX + 3, {0});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase104() {
    int passed = 1;

    printf("%s     bswap  rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "bswap  rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {7});
    ASSERT_TAGGED((char *)&outRAX + 1, {6});
    ASSERT_TAGGED((char *)&outRAX + 2, {5});
    ASSERT_TAGGED((char *)&outRAX + 3, {4});
    ASSERT_TAGGED((char *)&outRAX + 4, {3});
    ASSERT_TAGGED((char *)&outRAX + 5, {2});
    ASSERT_TAGGED((char *)&outRAX + 6, {1});
    ASSERT_TAGGED((char *)&outRAX + 7, {0});
    return passed;
}

static int testcase105() {
    int passed = 1;

    printf("%s     btc    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "btc    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase106() {
    int passed = 1;

    printf("%s     btc    ax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "btc    ax,0xf;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase107() {
    int passed = 1;

    printf("%s     btc    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "btc    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase108() {
    int passed = 1;

    printf("%s     btc    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "btc    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2});
    return passed;
}

static int testcase109() {
    int passed = 1;

    printf("%s     btc    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "btc    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase110() {
    int passed = 1;

    printf("%s     btc    eax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "btc    eax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase111() {
    int passed = 1;

    printf("%s     btc    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "btc    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase112() {
    int passed = 1;

    printf("%s     btc    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "btc    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase113() {
    int passed = 1;

    printf("%s     btc    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "btc    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase114() {
    int passed = 1;

    printf("%s     btc    rax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "btc    rax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase115() {
    int passed = 1;

    printf("%s     btc    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "btc    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase116() {
    int passed = 1;

    printf("%s     btc    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "btc    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase117() {
    int passed = 1;

    printf("%s     btr    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "btr    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase118() {
    int passed = 1;

    printf("%s     btr    ax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "btr    ax,0xf;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase119() {
    int passed = 1;

    printf("%s     btr    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "btr    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase120() {
    int passed = 1;

    printf("%s     btr    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "btr    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2});
    return passed;
}

static int testcase121() {
    int passed = 1;

    printf("%s     btr    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "btr    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase122() {
    int passed = 1;

    printf("%s     btr    eax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "btr    eax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase123() {
    int passed = 1;

    printf("%s     btr    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "btr    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase124() {
    int passed = 1;

    printf("%s     btr    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "btr    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase125() {
    int passed = 1;

    printf("%s     btr    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "btr    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase126() {
    int passed = 1;

    printf("%s     btr    rax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "btr    rax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase127() {
    int passed = 1;

    printf("%s     btr    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "btr    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase128() {
    int passed = 1;

    printf("%s     btr    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "btr    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase129() {
    int passed = 1;

    printf("%s     bts    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "bts    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase130() {
    int passed = 1;

    printf("%s     bts    ax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "bts    ax,0xf;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase131() {
    int passed = 1;

    printf("%s     bts    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "bts    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase132() {
    int passed = 1;

    printf("%s     bts    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "bts    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2});
    return passed;
}

static int testcase133() {
    int passed = 1;

    printf("%s     bts    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "bts    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase134() {
    int passed = 1;

    printf("%s     bts    eax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "bts    eax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase135() {
    int passed = 1;

    printf("%s     bts    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "bts    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase136() {
    int passed = 1;

    printf("%s     bts    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "bts    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase137() {
    int passed = 1;

    printf("%s     bts    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "bts    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase138() {
    int passed = 1;

    printf("%s     bts    rax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "bts    rax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase139() {
    int passed = 1;

    printf("%s     bts    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "bts    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase140() {
    int passed = 1;

    printf("%s     bts    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "bts    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase141() {
    int passed = 1;

    printf("%s     dec    ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "dec    ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase142() {
    int passed = 1;

    printf("%s     dec    al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "dec    al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase143() {
    int passed = 1;

    printf("%s     dec    ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "dec    ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase144() {
    int passed = 1;

    printf("%s     dec    eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "dec    eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase145() {
    int passed = 1;

    printf("%s     dec    rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "dec    rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase146() {
    int passed = 1;

    printf("%s     div    al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "div    al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase147() {
    int passed = 1;

    printf("%s     div    ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inDX = 0;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inDX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov DX,%3;\n"
        "div    ax;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX),"m"(inDX)
        :"ax","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1,2,3});
    return passed;
}

static int testcase148() {
    int passed = 1;

    printf("%s     div    cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "div    cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase149() {
    int passed = 1;

    printf("%s     div    cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t inDX = 0;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    __gtaint_setn(&inDX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "mov DX,%4;\n"
        "div    cx;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX),"m"(inCX),"m"(inDX)
        :"ax","cx","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1,2,3,4,5});
    return passed;
}

static int testcase150() {
    int passed = 1;

    printf("%s     div    eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov EDX,%3;\n"
        "div    eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX),"m"(inEDX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase151() {
    int passed = 1;

    printf("%s     div    ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "mov EDX,%4;\n"
        "div    ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX),"m"(inECX),"m"(inEDX)
        :"rax","ecx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase152() {
    int passed = 1;

    printf("%s     div    rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RDX,%3;\n"
        "div    rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX),"m"(inRDX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase153() {
    int passed = 1;

    printf("%s     div    rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "mov RDX,%4;\n"
        "div    rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX),"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    return passed;
}

static int testcase154() {
    int passed = 1;

    printf("%s     idiv   al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "idiv   al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase155() {
    int passed = 1;

    printf("%s     idiv   ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inDX = 0;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inDX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov DX,%3;\n"
        "idiv   ax;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX),"m"(inDX)
        :"ax","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1,2,3});
    return passed;
}

static int testcase156() {
    int passed = 1;

    printf("%s     idiv   cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "idiv   cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase157() {
    int passed = 1;

    printf("%s     idiv   cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t inDX = 0;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    __gtaint_setn(&inDX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "mov DX,%4;\n"
        "idiv   cx;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX),"m"(inCX),"m"(inDX)
        :"ax","cx","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1,2,3,4,5});
    return passed;
}

static int testcase158() {
    int passed = 1;

    printf("%s     idiv   eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov EDX,%3;\n"
        "idiv   eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX),"m"(inEDX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase159() {
    int passed = 1;

    printf("%s     idiv   ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "mov EDX,%4;\n"
        "idiv   ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX),"m"(inECX),"m"(inEDX)
        :"rax","ecx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase160() {
    int passed = 1;

    printf("%s     idiv   rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RDX,%3;\n"
        "idiv   rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX),"m"(inRDX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase161() {
    int passed = 1;

    printf("%s     idiv   rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "mov RDX,%4;\n"
        "idiv   rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX),"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
    return passed;
}

static int testcase162() {
    int passed = 1;

    printf("%s     imul   ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "imul   ah;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase163() {
    int passed = 1;

    printf("%s     imul   al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "imul   al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase164() {
    int passed = 1;

    printf("%s     imul   ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "imul   ax;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX)
        :"ax","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1});
    return passed;
}

static int testcase165() {
    int passed = 1;

    printf("%s     imul   ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "imul   ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase166() {
    int passed = 1;

    printf("%s     imul   ax,ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "imul   ax,ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase167() {
    int passed = 1;

    printf("%s     imul   ax,ax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "imul   ax,ax,0xffff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase168() {
    int passed = 1;

    printf("%s     imul   ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "imul   ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    return passed;
}

static int testcase169() {
    int passed = 1;

    printf("%s     imul   ax,cx,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "imul   ax,cx,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase170() {
    int passed = 1;

    printf("%s     imul   ax,cx,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "imul   ax,cx,0xffff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase171() {
    int passed = 1;

    printf("%s     imul   ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "imul   ch;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL),"m"(inCH)
        :"ax","ch"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase172() {
    int passed = 1;

    printf("%s     imul   cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "imul   cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase173() {
    int passed = 1;

    printf("%s     imul   cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "imul   cx;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1,2,3});
    return passed;
}

static int testcase174() {
    int passed = 1;

    printf("%s     imul   cx,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "imul   cx,ax;\n" // <--
        "mov %0,CX;\n"
        :"=m"(outCX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outCX + 0, {0,2});
    ASSERT_TAGGED((char *)&outCX + 1, {0,1,2,3});
    return passed;
}

static int testcase175() {
    int passed = 1;

    printf("%s     imul   cx,ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "imul   cx,ax,0x1;\n" // <--
        "mov %0,CX;\n"
        :"=m"(outCX)
        :"m"(inAX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {0,1});
    return passed;
}

static int testcase176() {
    int passed = 1;

    printf("%s     imul   cx,ax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "imul   cx,ax,0xffff;\n" // <--
        "mov %0,CX;\n"
        :"=m"(outCX)
        :"m"(inAX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {0,1});
    return passed;
}

static int testcase177() {
    int passed = 1;

    printf("%s     imul   cx,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "imul   cx,cx;\n" // <--
        "mov %0,CX;\n"
        :"=m"(outCX)
        :"m"(inCX)
        :"cx"
    );

    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {0,1});
    return passed;
}

static int testcase178() {
    int passed = 1;

    printf("%s     imul   cx,cx,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "imul   cx,cx,0x1;\n" // <--
        "mov %0,CX;\n"
        :"=m"(outCX)
        :"m"(inCX)
        :"cx"
    );

    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {0,1});
    return passed;
}

static int testcase179() {
    int passed = 1;

    printf("%s     imul   cx,cx,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "imul   cx,cx,0xffff;\n" // <--
        "mov %0,CX;\n"
        :"=m"(outCX)
        :"m"(inCX)
        :"cx"
    );

    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {0,1});
    return passed;
}

static int testcase180() {
    int passed = 1;

    printf("%s     imul   eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "imul   eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase181() {
    int passed = 1;

    printf("%s     imul   eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "imul   eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase182() {
    int passed = 1;

    printf("%s     imul   eax,eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "imul   eax,eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase183() {
    int passed = 1;

    printf("%s     imul   eax,eax,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "imul   eax,eax,0xffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase184() {
    int passed = 1;

    printf("%s     imul   eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "imul   eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase185() {
    int passed = 1;

    printf("%s     imul   eax,ecx,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "imul   eax,ecx,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase186() {
    int passed = 1;

    printf("%s     imul   eax,ecx,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "imul   eax,ecx,0xffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase187() {
    int passed = 1;

    printf("%s     imul   ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "imul   ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase188() {
    int passed = 1;

    printf("%s     imul   ecx,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "imul   ecx,eax;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inEAX),"m"(inECX)
        :"eax","rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase189() {
    int passed = 1;

    printf("%s     imul   ecx,eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "imul   ecx,eax,0x1;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inEAX)
        :"eax","rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase190() {
    int passed = 1;

    printf("%s     imul   ecx,eax,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "imul   ecx,eax,0xffffffff;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inEAX)
        :"eax","rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase191() {
    int passed = 1;

    printf("%s     imul   ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "imul   ecx,ecx;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inECX)
        :"rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase192() {
    int passed = 1;

    printf("%s     imul   ecx,ecx,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "imul   ecx,ecx,0x1;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inECX)
        :"rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase193() {
    int passed = 1;

    printf("%s     imul   ecx,ecx,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "imul   ecx,ecx,0xffffffff;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inECX)
        :"rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase194() {
    int passed = 1;

    printf("%s     imul   rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "imul   rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase195() {
    int passed = 1;

    printf("%s     imul   rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "imul   rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase196() {
    int passed = 1;

    printf("%s     imul   rax,rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "imul   rax,rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase197() {
    int passed = 1;

    printf("%s     imul   rax,rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "imul   rax,rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase198() {
    int passed = 1;

    printf("%s     imul   rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "imul   rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase199() {
    int passed = 1;

    printf("%s     imul   rax,rcx,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "imul   rax,rcx,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase200() {
    int passed = 1;

    printf("%s     imul   rax,rcx,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "imul   rax,rcx,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase201() {
    int passed = 1;

    printf("%s     imul   rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "imul   rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase202() {
    int passed = 1;

    printf("%s     imul   rcx,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "imul   rcx,rax;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase203() {
    int passed = 1;

    printf("%s     imul   rcx,rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "imul   rcx,rax,0x1;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRAX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase204() {
    int passed = 1;

    printf("%s     imul   rcx,rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "imul   rcx,rax,0xffffffffffffffff;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRAX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase205() {
    int passed = 1;

    printf("%s     imul   rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "imul   rcx,rcx;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRCX)
        :"rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase206() {
    int passed = 1;

    printf("%s     imul   rcx,rcx,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "imul   rcx,rcx,0x1;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRCX)
        :"rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase207() {
    int passed = 1;

    printf("%s     imul   rcx,rcx,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "imul   rcx,rcx,0xffffffffffffffff;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRCX)
        :"rcx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase208() {
    int passed = 1;

    printf("%s     inc    ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "inc    ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase209() {
    int passed = 1;

    printf("%s     inc    al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "inc    al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase210() {
    int passed = 1;

    printf("%s     inc    ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "inc    ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase211() {
    int passed = 1;

    printf("%s     inc    eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "inc    eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase212() {
    int passed = 1;

    printf("%s     inc    rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "inc    rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase213() {
    int passed = 1;

    printf("%s     mov    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase214() {
    int passed = 1;

    printf("%s     mov    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase215() {
    int passed = 1;

    printf("%s     mov    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov CH,%1;\n"
        "mov    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase216() {
    int passed = 1;

    printf("%s     mov    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase217() {
    int passed = 1;

    printf("%s     mov    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "mov    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase218() {
    int passed = 1;

    printf("%s     mov    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase219() {
    int passed = 1;

    printf("%s     mov    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "mov    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase220() {
    int passed = 1;

    printf("%s     mov    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0});
    return passed;
}

static int testcase221() {
    int passed = 1;

    printf("%s     mov    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase222() {
    int passed = 1;

    printf("%s     mov    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase223() {
    int passed = 1;

    printf("%s     mov    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase224() {
    int passed = 1;

    printf("%s     mov    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase225() {
    int passed = 1;

    printf("%s     movd   eax,mm0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inMM0 = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inMM0, 8);
    asm volatile (
        "movq MM0,%1;\n"
        "movd   eax,mm0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inMM0)
        :"rax","mm0"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase226() {
    int passed = 1;

    printf("%s     movd   eax,mm4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inMM4 = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inMM4, 8);
    asm volatile (
        "movq MM4,%1;\n"
        "movd   eax,mm4;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inMM4)
        :"rax","mm4"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase227() {
    int passed = 1;

    printf("%s     movd   mm0,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outMM0 = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "movd   mm0,eax;\n" // <--
        "movq %0,MM0;\n"
        :"=m"(outMM0)
        :"m"(inEAX)
        :"eax","mm0"
    );

    ASSERT_TAGGED((char *)&outMM0 + 0, {0});
    ASSERT_TAGGED((char *)&outMM0 + 1, {1});
    ASSERT_TAGGED((char *)&outMM0 + 2, {2});
    ASSERT_TAGGED((char *)&outMM0 + 3, {3});
    ASSERT_TAGGED((char *)&outMM0 + 4, { });
    ASSERT_TAGGED((char *)&outMM0 + 5, { });
    ASSERT_TAGGED((char *)&outMM0 + 6, { });
    ASSERT_TAGGED((char *)&outMM0 + 7, { });
    return passed;
}

static int testcase228() {
    int passed = 1;

    printf("%s     movd   mm2,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outMM2 = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "movd   mm2,eax;\n" // <--
        "movq %0,MM2;\n"
        :"=m"(outMM2)
        :"m"(inEAX)
        :"eax","mm2"
    );

    ASSERT_TAGGED((char *)&outMM2 + 0, {0});
    ASSERT_TAGGED((char *)&outMM2 + 1, {1});
    ASSERT_TAGGED((char *)&outMM2 + 2, {2});
    ASSERT_TAGGED((char *)&outMM2 + 3, {3});
    ASSERT_TAGGED((char *)&outMM2 + 4, { });
    ASSERT_TAGGED((char *)&outMM2 + 5, { });
    ASSERT_TAGGED((char *)&outMM2 + 6, { });
    ASSERT_TAGGED((char *)&outMM2 + 7, { });
    return passed;
}

static int testcase229() {
    int passed = 1;

    printf("%s     movq   mm0,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outMM0 = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "movq   mm0,rax;\n" // <--
        "movq %0,MM0;\n"
        :"=m"(outMM0)
        :"m"(inRAX)
        :"rax","mm0"
    );

    ASSERT_TAGGED((char *)&outMM0 + 0, {0});
    ASSERT_TAGGED((char *)&outMM0 + 1, {1});
    ASSERT_TAGGED((char *)&outMM0 + 2, {2});
    ASSERT_TAGGED((char *)&outMM0 + 3, {3});
    ASSERT_TAGGED((char *)&outMM0 + 4, {4});
    ASSERT_TAGGED((char *)&outMM0 + 5, {5});
    ASSERT_TAGGED((char *)&outMM0 + 6, {6});
    ASSERT_TAGGED((char *)&outMM0 + 7, {7});
    return passed;
}

static int testcase230() {
    int passed = 1;

    printf("%s     movq   mm4,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outMM4 = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "movq   mm4,rax;\n" // <--
        "movq %0,MM4;\n"
        :"=m"(outMM4)
        :"m"(inRAX)
        :"rax","mm4"
    );

    ASSERT_TAGGED((char *)&outMM4 + 0, {0});
    ASSERT_TAGGED((char *)&outMM4 + 1, {1});
    ASSERT_TAGGED((char *)&outMM4 + 2, {2});
    ASSERT_TAGGED((char *)&outMM4 + 3, {3});
    ASSERT_TAGGED((char *)&outMM4 + 4, {4});
    ASSERT_TAGGED((char *)&outMM4 + 5, {5});
    ASSERT_TAGGED((char *)&outMM4 + 6, {6});
    ASSERT_TAGGED((char *)&outMM4 + 7, {7});
    return passed;
}

static int testcase231() {
    int passed = 1;

    printf("%s     movq   rax,mm0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inMM0 = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inMM0, 8);
    asm volatile (
        "movq MM0,%1;\n"
        "movq   rax,mm0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inMM0)
        :"rax","mm0"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase232() {
    int passed = 1;

    printf("%s     movq   rax,mm5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inMM5 = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inMM5, 8);
    asm volatile (
        "movq MM5,%1;\n"
        "movq   rax,mm5;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inMM5)
        :"rax","mm5"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase233() {
    int passed = 1;

    printf("%s     movsx  ax,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "movsx  ax,al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase234() {
    int passed = 1;

    printf("%s     movsx  ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "movsx  ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase235() {
    int passed = 1;

    printf("%s     movsx  eax,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "movsx  eax,al;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAL)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase236() {
    int passed = 1;

    printf("%s     movsx  eax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "movsx  eax,ax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase237() {
    int passed = 1;

    printf("%s     movsx  eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "movsx  eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase238() {
    int passed = 1;

    printf("%s     movsx  eax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "movsx  eax,cx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCX)
        :"rax","cx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase239() {
    int passed = 1;

    printf("%s     movsx  rax,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "movsx  rax,al;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAL)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {0});
    ASSERT_TAGGED((char *)&outRAX + 6, {0});
    ASSERT_TAGGED((char *)&outRAX + 7, {0});
    return passed;
}

static int testcase240() {
    int passed = 1;

    printf("%s     movsx  rax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "movsx  rax,ax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, {1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1});
    ASSERT_TAGGED((char *)&outRAX + 7, {1});
    return passed;
}

static int testcase241() {
    int passed = 1;

    printf("%s     movsx  rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "movsx  rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {0});
    ASSERT_TAGGED((char *)&outRAX + 6, {0});
    ASSERT_TAGGED((char *)&outRAX + 7, {0});
    return passed;
}

static int testcase242() {
    int passed = 1;

    printf("%s     movsx  rax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "movsx  rax,cx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCX)
        :"rax","cx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, {1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1});
    ASSERT_TAGGED((char *)&outRAX + 7, {1});
    return passed;
}

static int testcase243() {
    int passed = 1;

    printf("%s     movzx  ax,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "movzx  ax,al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase244() {
    int passed = 1;

    printf("%s     movzx  ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "movzx  ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase245() {
    int passed = 1;

    printf("%s     movzx  eax,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "movzx  eax,al;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAL)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase246() {
    int passed = 1;

    printf("%s     movzx  eax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "movzx  eax,ax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase247() {
    int passed = 1;

    printf("%s     movzx  eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "movzx  eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase248() {
    int passed = 1;

    printf("%s     movzx  eax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "movzx  eax,cx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCX)
        :"rax","cx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase249() {
    int passed = 1;

    printf("%s     movzx  rax,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "movzx  rax,al;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAL)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase250() {
    int passed = 1;

    printf("%s     movzx  rax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "movzx  rax,ax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase251() {
    int passed = 1;

    printf("%s     movzx  rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "movzx  rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase252() {
    int passed = 1;

    printf("%s     movzx  rax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov CX,%1;\n"
        "movzx  rax,cx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inCX)
        :"rax","cx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase253() {
    int passed = 1;

    printf("%s     mul    ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mul    ah;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase254() {
    int passed = 1;

    printf("%s     mul    al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mul    al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase255() {
    int passed = 1;

    printf("%s     mul    ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mul    ax;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX)
        :"ax","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1});
    return passed;
}

static int testcase256() {
    int passed = 1;

    printf("%s     mul    ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "mul    ch;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL),"m"(inCH)
        :"ax","ch"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase257() {
    int passed = 1;

    printf("%s     mul    cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "mul    cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase258() {
    int passed = 1;

    printf("%s     mul    cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    uint16_t outDX = 0;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "mul    cx;\n" // <--
        "mov %0,AX;\n"
        "mov %1,DX;\n"
        :"=m"(outAX),"=m"(outDX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx","dx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outDX + 1, {0,1,2,3});
    return passed;
}

static int testcase259() {
    int passed = 1;

    printf("%s     mul    eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mul    eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase260() {
    int passed = 1;

    printf("%s     mul    ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "mul    ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 4, { });
    ASSERT_TAGGED((char *)&outRDX + 5, { });
    ASSERT_TAGGED((char *)&outRDX + 6, { });
    ASSERT_TAGGED((char *)&outRDX + 7, { });
    return passed;
}

static int testcase261() {
    int passed = 1;

    printf("%s     mul    rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mul    rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase262() {
    int passed = 1;

    printf("%s     mul    rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    uint64_t outRDX = 0;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "mul    rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RDX;\n"
        :"=m"(outRAX),"=m"(outRDX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRDX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase263() {
    int passed = 1;

    printf("%s     mulx   eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov EDX,%2;\n"
        "mulx   eax,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inEDX)
        :"rax","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase264() {
    int passed = 1;

    printf("%s     mulx   eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov EDX,%2;\n"
        "mulx   eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inEDX)
        :"rax","ecx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase265() {
    int passed = 1;

    printf("%s     mulx   eax,ecx,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov EDX,%3;\n"
        "mulx   eax,ecx,eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inEAX),"m"(inEDX)
        :"rax","rcx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase266() {
    int passed = 1;

    printf("%s     mulx   eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%2;\n"
        "mov EDX,%3;\n"
        "mulx   eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inECX),"m"(inEDX)
        :"rax","rcx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase267() {
    int passed = 1;

    printf("%s     mulx   ecx,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov EDX,%3;\n"
        "mulx   ecx,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inEAX),"m"(inEDX)
        :"rax","rcx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase268() {
    int passed = 1;

    printf("%s     mulx   ecx,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%2;\n"
        "mov EDX,%3;\n"
        "mulx   ecx,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inECX),"m"(inEDX)
        :"rax","rcx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase269() {
    int passed = 1;

    printf("%s     mulx   ecx,ecx,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inEDX = 0;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov EDX,%2;\n"
        "mulx   ecx,ecx,eax;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inEAX),"m"(inEDX)
        :"eax","rcx","edx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase270() {
    int passed = 1;

    printf("%s     mulx   ecx,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRCX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov EDX,%2;\n"
        "mulx   ecx,ecx,ecx;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inECX),"m"(inEDX)
        :"rcx","edx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase271() {
    int passed = 1;

    printf("%s     mulx   rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RDX,%2;\n"
        "mulx   rax,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRDX)
        :"rax","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase272() {
    int passed = 1;

    printf("%s     mulx   rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov RDX,%2;\n"
        "mulx   rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase273() {
    int passed = 1;

    printf("%s     mulx   rax,rcx,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RDX,%3;\n"
        "mulx   rax,rcx,rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRAX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase274() {
    int passed = 1;

    printf("%s     mulx   rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%2;\n"
        "mov RDX,%3;\n"
        "mulx   rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase275() {
    int passed = 1;

    printf("%s     mulx   rcx,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RDX,%3;\n"
        "mulx   rcx,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRAX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase276() {
    int passed = 1;

    printf("%s     mulx   rcx,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%2;\n"
        "mov RDX,%3;\n"
        "mulx   rcx,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase277() {
    int passed = 1;

    printf("%s     mulx   rcx,rcx,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRDX = 0;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RDX,%2;\n"
        "mulx   rcx,rcx,rax;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRAX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase278() {
    int passed = 1;

    printf("%s     mulx   rcx,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov RDX,%2;\n"
        "mulx   rcx,rcx,rcx;\n" // <--
        "mov %0,RCX;\n"
        :"=m"(outRCX)
        :"m"(inRCX),"m"(inRDX)
        :"rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRCX + 0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 1, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 2, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 5, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 6, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase279() {
    int passed = 1;

    printf("%s     neg    ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "neg    ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase280() {
    int passed = 1;

    printf("%s     neg    al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "neg    al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase281() {
    int passed = 1;

    printf("%s     neg    ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "neg    ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase282() {
    int passed = 1;

    printf("%s     neg    eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "neg    eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase283() {
    int passed = 1;

    printf("%s     neg    rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "neg    rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase284() {
    int passed = 1;

    printf("%s     not    ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "not    ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase285() {
    int passed = 1;

    printf("%s     not    al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "not    al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase286() {
    int passed = 1;

    printf("%s     not    ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "not    ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase287() {
    int passed = 1;

    printf("%s     not    eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "not    eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase288() {
    int passed = 1;

    printf("%s     not    rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "not    rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase289() {
    int passed = 1;

    printf("%s     or     ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "or     ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase290() {
    int passed = 1;

    printf("%s     or     ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "or     ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase291() {
    int passed = 1;

    printf("%s     or     ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "or     ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase292() {
    int passed = 1;

    printf("%s     or     ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "or     ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase293() {
    int passed = 1;

    printf("%s     or     ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "or     ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase294() {
    int passed = 1;

    printf("%s     or     al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "or     al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase295() {
    int passed = 1;

    printf("%s     or     al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "or     al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase296() {
    int passed = 1;

    printf("%s     or     al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "or     al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase297() {
    int passed = 1;

    printf("%s     or     al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "or     al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase298() {
    int passed = 1;

    printf("%s     or     ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "or     ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase299() {
    int passed = 1;

    printf("%s     or     ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "or     ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase300() {
    int passed = 1;

    printf("%s     or     ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "or     ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase301() {
    int passed = 1;

    printf("%s     or     ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "or     ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,3});
    return passed;
}

static int testcase302() {
    int passed = 1;

    printf("%s     or     ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "or     ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase303() {
    int passed = 1;

    printf("%s     or     eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "or     eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase304() {
    int passed = 1;

    printf("%s     or     eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "or     eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase305() {
    int passed = 1;

    printf("%s     or     eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "or     eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase306() {
    int passed = 1;

    printf("%s     or     eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "or     eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase307() {
    int passed = 1;

    printf("%s     or     rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "or     rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase308() {
    int passed = 1;

    printf("%s     or     rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "or     rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase309() {
    int passed = 1;

    printf("%s     or     rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "or     rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase310() {
    int passed = 1;

    printf("%s     or     rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "or     rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase311() {
    int passed = 1;

    printf("%s     or     rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "or     rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,15});
    return passed;
}

static int testcase312() {
    int passed = 1;

    printf("%s     rcl    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase313() {
    int passed = 1;

    printf("%s     rcl    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase314() {
    int passed = 1;

    printf("%s     rcl    ah,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x2;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase315() {
    int passed = 1;

    printf("%s     rcl    ah,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x4;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase316() {
    int passed = 1;

    printf("%s     rcl    ah,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x5;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase317() {
    int passed = 1;

    printf("%s     rcl    ah,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x6;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase318() {
    int passed = 1;

    printf("%s     rcl    ah,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,0x8;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase319() {
    int passed = 1;

    printf("%s     rcl    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcl    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase320() {
    int passed = 1;

    printf("%s     rcl    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase321() {
    int passed = 1;

    printf("%s     rcl    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase322() {
    int passed = 1;

    printf("%s     rcl    al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase323() {
    int passed = 1;

    printf("%s     rcl    al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase324() {
    int passed = 1;

    printf("%s     rcl    al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase325() {
    int passed = 1;

    printf("%s     rcl    al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase326() {
    int passed = 1;

    printf("%s     rcl    al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase327() {
    int passed = 1;

    printf("%s     rcl    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcl    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase328() {
    int passed = 1;

    printf("%s     rcl    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rcl    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase329() {
    int passed = 1;

    printf("%s     rcl    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase330() {
    int passed = 1;

    printf("%s     rcl    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase331() {
    int passed = 1;

    printf("%s     rcl    ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase332() {
    int passed = 1;

    printf("%s     rcl    ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase333() {
    int passed = 1;

    printf("%s     rcl    ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase334() {
    int passed = 1;

    printf("%s     rcl    ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase335() {
    int passed = 1;

    printf("%s     rcl    ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase336() {
    int passed = 1;

    printf("%s     rcl    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcl    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase337() {
    int passed = 1;

    printf("%s     rcl    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "rcl    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase338() {
    int passed = 1;

    printf("%s     rcl    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase339() {
    int passed = 1;

    printf("%s     rcl    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase340() {
    int passed = 1;

    printf("%s     rcl    eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase341() {
    int passed = 1;

    printf("%s     rcl    eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase342() {
    int passed = 1;

    printf("%s     rcl    eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase343() {
    int passed = 1;

    printf("%s     rcl    eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase344() {
    int passed = 1;

    printf("%s     rcl    eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase345() {
    int passed = 1;

    printf("%s     rcl    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcl    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase346() {
    int passed = 1;

    printf("%s     rcl    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "rcl    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase347() {
    int passed = 1;

    printf("%s     rcl    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase348() {
    int passed = 1;

    printf("%s     rcl    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase349() {
    int passed = 1;

    printf("%s     rcl    rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase350() {
    int passed = 1;

    printf("%s     rcl    rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase351() {
    int passed = 1;

    printf("%s     rcl    rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase352() {
    int passed = 1;

    printf("%s     rcl    rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase353() {
    int passed = 1;

    printf("%s     rcl    rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase354() {
    int passed = 1;

    printf("%s     rcl    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcl    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase355() {
    int passed = 1;

    printf("%s     rcl    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "rcl    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase356() {
    int passed = 1;

    printf("%s     rcr    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase357() {
    int passed = 1;

    printf("%s     rcr    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase358() {
    int passed = 1;

    printf("%s     rcr    ah,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x2;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase359() {
    int passed = 1;

    printf("%s     rcr    ah,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x4;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase360() {
    int passed = 1;

    printf("%s     rcr    ah,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x5;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase361() {
    int passed = 1;

    printf("%s     rcr    ah,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x6;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase362() {
    int passed = 1;

    printf("%s     rcr    ah,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,0x8;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase363() {
    int passed = 1;

    printf("%s     rcr    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rcr    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase364() {
    int passed = 1;

    printf("%s     rcr    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase365() {
    int passed = 1;

    printf("%s     rcr    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase366() {
    int passed = 1;

    printf("%s     rcr    al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase367() {
    int passed = 1;

    printf("%s     rcr    al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase368() {
    int passed = 1;

    printf("%s     rcr    al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase369() {
    int passed = 1;

    printf("%s     rcr    al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase370() {
    int passed = 1;

    printf("%s     rcr    al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase371() {
    int passed = 1;

    printf("%s     rcr    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rcr    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase372() {
    int passed = 1;

    printf("%s     rcr    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rcr    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase373() {
    int passed = 1;

    printf("%s     rcr    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase374() {
    int passed = 1;

    printf("%s     rcr    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase375() {
    int passed = 1;

    printf("%s     rcr    ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase376() {
    int passed = 1;

    printf("%s     rcr    ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase377() {
    int passed = 1;

    printf("%s     rcr    ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase378() {
    int passed = 1;

    printf("%s     rcr    ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase379() {
    int passed = 1;

    printf("%s     rcr    ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase380() {
    int passed = 1;

    printf("%s     rcr    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rcr    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase381() {
    int passed = 1;

    printf("%s     rcr    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "rcr    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase382() {
    int passed = 1;

    printf("%s     rcr    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase383() {
    int passed = 1;

    printf("%s     rcr    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase384() {
    int passed = 1;

    printf("%s     rcr    eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase385() {
    int passed = 1;

    printf("%s     rcr    eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase386() {
    int passed = 1;

    printf("%s     rcr    eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase387() {
    int passed = 1;

    printf("%s     rcr    eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase388() {
    int passed = 1;

    printf("%s     rcr    eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase389() {
    int passed = 1;

    printf("%s     rcr    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rcr    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase390() {
    int passed = 1;

    printf("%s     rcr    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "rcr    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase391() {
    int passed = 1;

    printf("%s     rcr    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase392() {
    int passed = 1;

    printf("%s     rcr    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase393() {
    int passed = 1;

    printf("%s     rcr    rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase394() {
    int passed = 1;

    printf("%s     rcr    rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase395() {
    int passed = 1;

    printf("%s     rcr    rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase396() {
    int passed = 1;

    printf("%s     rcr    rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase397() {
    int passed = 1;

    printf("%s     rcr    rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase398() {
    int passed = 1;

    printf("%s     rcr    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rcr    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase399() {
    int passed = 1;

    printf("%s     rcr    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "rcr    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase400() {
    int passed = 1;

    printf("%s     rex.W adc al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W adc al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase401() {
    int passed = 1;

    printf("%s     rex.W adc al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W adc al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase402() {
    int passed = 1;

    printf("%s     rex.W adc al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W adc al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase403() {
    int passed = 1;

    printf("%s     rex.W adc al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W adc al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase404() {
    int passed = 1;

    printf("%s     rex.W add al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W add al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase405() {
    int passed = 1;

    printf("%s     rex.W add al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W add al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase406() {
    int passed = 1;

    printf("%s     rex.W add al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W add al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase407() {
    int passed = 1;

    printf("%s     rex.W add al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W add al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase408() {
    int passed = 1;

    printf("%s     rex.W and al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W and al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase409() {
    int passed = 1;

    printf("%s     rex.W and al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W and al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase410() {
    int passed = 1;

    printf("%s     rex.W and al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W and al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase411() {
    int passed = 1;

    printf("%s     rex.W and al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W and al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase412() {
    int passed = 1;

    printf("%s     rex.W dec al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W dec al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase413() {
    int passed = 1;

    printf("%s     rex.W div al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rex.W div al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase414() {
    int passed = 1;

    printf("%s     rex.W div cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "rex.W div cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase415() {
    int passed = 1;

    printf("%s     rex.W idiv al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rex.W idiv al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase416() {
    int passed = 1;

    printf("%s     rex.W idiv cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "rex.W idiv cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase417() {
    int passed = 1;

    printf("%s     rex.W imul al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W imul al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase418() {
    int passed = 1;

    printf("%s     rex.W imul cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W imul cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase419() {
    int passed = 1;

    printf("%s     rex.W inc al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W inc al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase420() {
    int passed = 1;

    printf("%s     rex.W mov al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W mov al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase421() {
    int passed = 1;

    printf("%s     rex.W mov al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov CL,%1;\n"
        "rex.W mov al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase422() {
    int passed = 1;

    printf("%s     rex.W mul al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W mul al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase423() {
    int passed = 1;

    printf("%s     rex.W mul cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W mul cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAL),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase424() {
    int passed = 1;

    printf("%s     rex.W neg al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W neg al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase425() {
    int passed = 1;

    printf("%s     rex.W not al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W not al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase426() {
    int passed = 1;

    printf("%s     rex.W or al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W or al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase427() {
    int passed = 1;

    printf("%s     rex.W or al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W or al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase428() {
    int passed = 1;

    printf("%s     rex.W or al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W or al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase429() {
    int passed = 1;

    printf("%s     rex.W or al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W or al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase430() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase431() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase432() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase433() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase434() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase435() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase436() {
    int passed = 1;

    printf("%s     rex.W rcl al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase437() {
    int passed = 1;

    printf("%s     rex.W rcl al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcl al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase438() {
    int passed = 1;

    printf("%s     rex.W rcl al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W rcl al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase439() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase440() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase441() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase442() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase443() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase444() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase445() {
    int passed = 1;

    printf("%s     rex.W rcr al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase446() {
    int passed = 1;

    printf("%s     rex.W rcr al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rcr al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase447() {
    int passed = 1;

    printf("%s     rex.W rcr al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W rcr al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase448() {
    int passed = 1;

    printf("%s     rex.W rol al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase449() {
    int passed = 1;

    printf("%s     rex.W rol al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase450() {
    int passed = 1;

    printf("%s     rex.W rol al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase451() {
    int passed = 1;

    printf("%s     rex.W rol al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase452() {
    int passed = 1;

    printf("%s     rex.W rol al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase453() {
    int passed = 1;

    printf("%s     rex.W rol al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase454() {
    int passed = 1;

    printf("%s     rex.W rol al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase455() {
    int passed = 1;

    printf("%s     rex.W rol al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W rol al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase456() {
    int passed = 1;

    printf("%s     rex.W rol al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W rol al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase457() {
    int passed = 1;

    printf("%s     rex.W ror al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase458() {
    int passed = 1;

    printf("%s     rex.W ror al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase459() {
    int passed = 1;

    printf("%s     rex.W ror al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase460() {
    int passed = 1;

    printf("%s     rex.W ror al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase461() {
    int passed = 1;

    printf("%s     rex.W ror al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase462() {
    int passed = 1;

    printf("%s     rex.W ror al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase463() {
    int passed = 1;

    printf("%s     rex.W ror al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase464() {
    int passed = 1;

    printf("%s     rex.W ror al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W ror al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase465() {
    int passed = 1;

    printf("%s     rex.W ror al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W ror al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase466() {
    int passed = 1;

    printf("%s     rex.W sar al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sar al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase467() {
    int passed = 1;

    printf("%s     rex.W sar al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sar al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase468() {
    int passed = 1;

    printf("%s     rex.W sar al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sar al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase469() {
    int passed = 1;

    printf("%s     rex.W sar al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sar al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase470() {
    int passed = 1;

    printf("%s     rex.W sar al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W sar al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase471() {
    int passed = 1;

    printf("%s     rex.W sbb al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sbb al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase472() {
    int passed = 1;

    printf("%s     rex.W sbb al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sbb al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase473() {
    int passed = 1;

    printf("%s     rex.W sbb al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sbb al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase474() {
    int passed = 1;

    printf("%s     rex.W sbb al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W sbb al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase475() {
    int passed = 1;

    printf("%s     rex.W shl al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase476() {
    int passed = 1;

    printf("%s     rex.W shl al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase477() {
    int passed = 1;

    printf("%s     rex.W shl al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase478() {
    int passed = 1;

    printf("%s     rex.W shl al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase479() {
    int passed = 1;

    printf("%s     rex.W shl al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase480() {
    int passed = 1;

    printf("%s     rex.W shl al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase481() {
    int passed = 1;

    printf("%s     rex.W shl al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase482() {
    int passed = 1;

    printf("%s     rex.W shl al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shl al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase483() {
    int passed = 1;

    printf("%s     rex.W shl al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W shl al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase484() {
    int passed = 1;

    printf("%s     rex.W shr al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase485() {
    int passed = 1;

    printf("%s     rex.W shr al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase486() {
    int passed = 1;

    printf("%s     rex.W shr al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase487() {
    int passed = 1;

    printf("%s     rex.W shr al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase488() {
    int passed = 1;

    printf("%s     rex.W shr al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase489() {
    int passed = 1;

    printf("%s     rex.W shr al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase490() {
    int passed = 1;

    printf("%s     rex.W shr al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase491() {
    int passed = 1;

    printf("%s     rex.W shr al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W shr al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase492() {
    int passed = 1;

    printf("%s     rex.W shr al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W shr al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase493() {
    int passed = 1;

    printf("%s     rex.W sub al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sub al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase494() {
    int passed = 1;

    printf("%s     rex.W sub al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sub al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase495() {
    int passed = 1;

    printf("%s     rex.W sub al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W sub al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase496() {
    int passed = 1;

    printf("%s     rex.W sub al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W sub al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase497() {
    int passed = 1;

    printf("%s     rex.W xadd al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W xadd al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase498() {
    int passed = 1;

    printf("%s     rex.W xadd al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    uint8_t outCL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%2;\n"
        "mov CL,%3;\n"
        "rex.W xadd al,cl;\n" // <--
        "mov %0,AL;\n"
        "mov %1,CL;\n"
        :"=m"(outAL),"=m"(outCL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    ASSERT_TAGGED((char *)&outCL + 0, {0});
    return passed;
}

static int testcase499() {
    int passed = 1;

    printf("%s     rex.W xchg al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W xchg al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase500() {
    int passed = 1;

    printf("%s     rex.W xchg al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    uint8_t outCL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%2;\n"
        "mov CL,%3;\n"
        "rex.W xchg al,cl;\n" // <--
        "mov %0,AL;\n"
        "mov %1,CL;\n"
        :"=m"(outAL),"=m"(outCL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {1});
    ASSERT_TAGGED((char *)&outCL + 0, {0});
    return passed;
}

static int testcase501() {
    int passed = 1;

    printf("%s     rex.W xor al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W xor al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase502() {
    int passed = 1;

    printf("%s     rex.W xor al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W xor al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase503() {
    int passed = 1;

    printf("%s     rex.W xor al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rex.W xor al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase504() {
    int passed = 1;

    printf("%s     rex.W xor al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rex.W xor al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase505() {
    int passed = 1;

    printf("%s     rol    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase506() {
    int passed = 1;

    printf("%s     rol    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase507() {
    int passed = 1;

    printf("%s     rol    ah,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x2;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase508() {
    int passed = 1;

    printf("%s     rol    ah,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x4;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase509() {
    int passed = 1;

    printf("%s     rol    ah,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x5;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase510() {
    int passed = 1;

    printf("%s     rol    ah,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x6;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase511() {
    int passed = 1;

    printf("%s     rol    ah,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,0x8;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase512() {
    int passed = 1;

    printf("%s     rol    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "rol    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase513() {
    int passed = 1;

    printf("%s     rol    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase514() {
    int passed = 1;

    printf("%s     rol    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase515() {
    int passed = 1;

    printf("%s     rol    al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase516() {
    int passed = 1;

    printf("%s     rol    al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase517() {
    int passed = 1;

    printf("%s     rol    al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase518() {
    int passed = 1;

    printf("%s     rol    al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase519() {
    int passed = 1;

    printf("%s     rol    al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase520() {
    int passed = 1;

    printf("%s     rol    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "rol    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase521() {
    int passed = 1;

    printf("%s     rol    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "rol    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase522() {
    int passed = 1;

    printf("%s     rol    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase523() {
    int passed = 1;

    printf("%s     rol    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase524() {
    int passed = 1;

    printf("%s     rol    ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase525() {
    int passed = 1;

    printf("%s     rol    ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase526() {
    int passed = 1;

    printf("%s     rol    ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase527() {
    int passed = 1;

    printf("%s     rol    ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase528() {
    int passed = 1;

    printf("%s     rol    ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase529() {
    int passed = 1;

    printf("%s     rol    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "rol    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase530() {
    int passed = 1;

    printf("%s     rol    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "rol    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase531() {
    int passed = 1;

    printf("%s     rol    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase532() {
    int passed = 1;

    printf("%s     rol    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase533() {
    int passed = 1;

    printf("%s     rol    eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase534() {
    int passed = 1;

    printf("%s     rol    eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase535() {
    int passed = 1;

    printf("%s     rol    eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase536() {
    int passed = 1;

    printf("%s     rol    eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase537() {
    int passed = 1;

    printf("%s     rol    eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase538() {
    int passed = 1;

    printf("%s     rol    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rol    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase539() {
    int passed = 1;

    printf("%s     rol    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "rol    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase540() {
    int passed = 1;

    printf("%s     rol    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase541() {
    int passed = 1;

    printf("%s     rol    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase542() {
    int passed = 1;

    printf("%s     rol    rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase543() {
    int passed = 1;

    printf("%s     rol    rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase544() {
    int passed = 1;

    printf("%s     rol    rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase545() {
    int passed = 1;

    printf("%s     rol    rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase546() {
    int passed = 1;

    printf("%s     rol    rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase547() {
    int passed = 1;

    printf("%s     rol    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rol    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase548() {
    int passed = 1;

    printf("%s     rol    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "rol    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase549() {
    int passed = 1;

    printf("%s     ror    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase550() {
    int passed = 1;

    printf("%s     ror    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase551() {
    int passed = 1;

    printf("%s     ror    ah,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x2;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase552() {
    int passed = 1;

    printf("%s     ror    ah,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x4;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase553() {
    int passed = 1;

    printf("%s     ror    ah,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x5;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase554() {
    int passed = 1;

    printf("%s     ror    ah,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x6;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase555() {
    int passed = 1;

    printf("%s     ror    ah,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,0x8;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase556() {
    int passed = 1;

    printf("%s     ror    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "ror    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase557() {
    int passed = 1;

    printf("%s     ror    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase558() {
    int passed = 1;

    printf("%s     ror    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase559() {
    int passed = 1;

    printf("%s     ror    al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase560() {
    int passed = 1;

    printf("%s     ror    al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase561() {
    int passed = 1;

    printf("%s     ror    al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase562() {
    int passed = 1;

    printf("%s     ror    al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase563() {
    int passed = 1;

    printf("%s     ror    al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase564() {
    int passed = 1;

    printf("%s     ror    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "ror    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase565() {
    int passed = 1;

    printf("%s     ror    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "ror    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase566() {
    int passed = 1;

    printf("%s     ror    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase567() {
    int passed = 1;

    printf("%s     ror    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase568() {
    int passed = 1;

    printf("%s     ror    ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase569() {
    int passed = 1;

    printf("%s     ror    ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase570() {
    int passed = 1;

    printf("%s     ror    ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase571() {
    int passed = 1;

    printf("%s     ror    ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase572() {
    int passed = 1;

    printf("%s     ror    ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase573() {
    int passed = 1;

    printf("%s     ror    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "ror    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase574() {
    int passed = 1;

    printf("%s     ror    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "ror    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase575() {
    int passed = 1;

    printf("%s     ror    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase576() {
    int passed = 1;

    printf("%s     ror    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase577() {
    int passed = 1;

    printf("%s     ror    eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase578() {
    int passed = 1;

    printf("%s     ror    eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase579() {
    int passed = 1;

    printf("%s     ror    eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase580() {
    int passed = 1;

    printf("%s     ror    eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase581() {
    int passed = 1;

    printf("%s     ror    eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase582() {
    int passed = 1;

    printf("%s     ror    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "ror    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase583() {
    int passed = 1;

    printf("%s     ror    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "ror    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase584() {
    int passed = 1;

    printf("%s     ror    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase585() {
    int passed = 1;

    printf("%s     ror    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase586() {
    int passed = 1;

    printf("%s     ror    rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase587() {
    int passed = 1;

    printf("%s     ror    rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase588() {
    int passed = 1;

    printf("%s     ror    rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase589() {
    int passed = 1;

    printf("%s     ror    rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase590() {
    int passed = 1;

    printf("%s     ror    rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase591() {
    int passed = 1;

    printf("%s     ror    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "ror    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase592() {
    int passed = 1;

    printf("%s     ror    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "ror    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase593() {
    int passed = 1;

    printf("%s     rorx   eax,eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rorx   eax,eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase594() {
    int passed = 1;

    printf("%s     rorx   eax,eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rorx   eax,eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase595() {
    int passed = 1;

    printf("%s     rorx   eax,eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rorx   eax,eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase596() {
    int passed = 1;

    printf("%s     rorx   eax,eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rorx   eax,eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase597() {
    int passed = 1;

    printf("%s     rorx   eax,eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rorx   eax,eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase598() {
    int passed = 1;

    printf("%s     rorx   eax,eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "rorx   eax,eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase599() {
    int passed = 1;

    printf("%s     rorx   eax,ecx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "rorx   eax,ecx,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase600() {
    int passed = 1;

    printf("%s     rorx   eax,ecx,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "rorx   eax,ecx,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase601() {
    int passed = 1;

    printf("%s     rorx   eax,ecx,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "rorx   eax,ecx,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase602() {
    int passed = 1;

    printf("%s     rorx   eax,ecx,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "rorx   eax,ecx,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase603() {
    int passed = 1;

    printf("%s     rorx   eax,ecx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "rorx   eax,ecx,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase604() {
    int passed = 1;

    printf("%s     rorx   eax,ecx,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "rorx   eax,ecx,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase605() {
    int passed = 1;

    printf("%s     rorx   rax,rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rorx   rax,rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase606() {
    int passed = 1;

    printf("%s     rorx   rax,rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rorx   rax,rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase607() {
    int passed = 1;

    printf("%s     rorx   rax,rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rorx   rax,rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase608() {
    int passed = 1;

    printf("%s     rorx   rax,rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rorx   rax,rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase609() {
    int passed = 1;

    printf("%s     rorx   rax,rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rorx   rax,rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase610() {
    int passed = 1;

    printf("%s     rorx   rax,rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "rorx   rax,rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase611() {
    int passed = 1;

    printf("%s     rorx   rax,rcx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "rorx   rax,rcx,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase612() {
    int passed = 1;

    printf("%s     rorx   rax,rcx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "rorx   rax,rcx,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase613() {
    int passed = 1;

    printf("%s     rorx   rax,rcx,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "rorx   rax,rcx,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase614() {
    int passed = 1;

    printf("%s     rorx   rax,rcx,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "rorx   rax,rcx,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase615() {
    int passed = 1;

    printf("%s     rorx   rax,rcx,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "rorx   rax,rcx,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase616() {
    int passed = 1;

    printf("%s     rorx   rax,rcx,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "rorx   rax,rcx,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase617() {
    int passed = 1;

    printf("%s     sar    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sar    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase618() {
    int passed = 1;

    printf("%s     sar    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sar    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase619() {
    int passed = 1;

    printf("%s     sar    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sar    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase620() {
    int passed = 1;

    printf("%s     sar    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sar    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase621() {
    int passed = 1;

    printf("%s     sar    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sar    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase622() {
    int passed = 1;

    printf("%s     sar    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sar    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase623() {
    int passed = 1;

    printf("%s     sar    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sar    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase624() {
    int passed = 1;

    printf("%s     sar    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sar    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase625() {
    int passed = 1;

    printf("%s     sar    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "sar    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase626() {
    int passed = 1;

    printf("%s     sar    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sar    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase627() {
    int passed = 1;

    printf("%s     sar    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sar    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase628() {
    int passed = 1;

    printf("%s     sar    ax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sar    ax,0xf;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase629() {
    int passed = 1;

    printf("%s     sar    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sar    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase630() {
    int passed = 1;

    printf("%s     sar    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "sar    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2});
    return passed;
}

static int testcase631() {
    int passed = 1;

    printf("%s     sar    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sar    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase632() {
    int passed = 1;

    printf("%s     sar    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sar    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase633() {
    int passed = 1;

    printf("%s     sar    eax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sar    eax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase634() {
    int passed = 1;

    printf("%s     sar    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sar    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase635() {
    int passed = 1;

    printf("%s     sar    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "sar    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase636() {
    int passed = 1;

    printf("%s     sar    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sar    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase637() {
    int passed = 1;

    printf("%s     sar    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sar    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase638() {
    int passed = 1;

    printf("%s     sar    rax,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sar    rax,0xf;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 4, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 5, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase639() {
    int passed = 1;

    printf("%s     sar    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sar    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase640() {
    int passed = 1;

    printf("%s     sar    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "sar    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase641() {
    int passed = 1;

    printf("%s     sarx   eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sarx   eax,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase642() {
    int passed = 1;

    printf("%s     sarx   eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "sarx   eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase643() {
    int passed = 1;

    printf("%s     sarx   eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "sarx   eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase644() {
    int passed = 1;

    printf("%s     sarx   eax,ecx,edx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov EDX,%2;\n"
        "sarx   eax,ecx,edx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inEDX)
        :"rax","ecx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase645() {
    int passed = 1;

    printf("%s     sarx   rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sarx   rax,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase646() {
    int passed = 1;

    printf("%s     sarx   rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "sarx   rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase647() {
    int passed = 1;

    printf("%s     sarx   rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "sarx   rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase648() {
    int passed = 1;

    printf("%s     sarx   rax,rcx,rdx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov RDX,%2;\n"
        "sarx   rax,rcx,rdx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase649() {
    int passed = 1;

    printf("%s     sbb    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sbb    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase650() {
    int passed = 1;

    printf("%s     sbb    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sbb    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase651() {
    int passed = 1;

    printf("%s     sbb    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sbb    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, { });
    return passed;
}

static int testcase652() {
    int passed = 1;

    printf("%s     sbb    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sbb    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase653() {
    int passed = 1;

    printf("%s     sbb    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "sbb    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase654() {
    int passed = 1;

    printf("%s     sbb    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sbb    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase655() {
    int passed = 1;

    printf("%s     sbb    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sbb    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase656() {
    int passed = 1;

    printf("%s     sbb    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sbb    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase657() {
    int passed = 1;

    printf("%s     sbb    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "sbb    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase658() {
    int passed = 1;

    printf("%s     sbb    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sbb    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase659() {
    int passed = 1;

    printf("%s     sbb    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sbb    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase660() {
    int passed = 1;

    printf("%s     sbb    ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sbb    ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase661() {
    int passed = 1;

    printf("%s     sbb    ax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sbb    ax,0xffff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase662() {
    int passed = 1;

    printf("%s     sbb    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sbb    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase663() {
    int passed = 1;

    printf("%s     sbb    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "sbb    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    return passed;
}

static int testcase664() {
    int passed = 1;

    printf("%s     sbb    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "sbb    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase665() {
    int passed = 1;

    printf("%s     sbb    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sbb    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase666() {
    int passed = 1;

    printf("%s     sbb    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sbb    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase667() {
    int passed = 1;

    printf("%s     sbb    eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sbb    eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase668() {
    int passed = 1;

    printf("%s     sbb    eax,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sbb    eax,0xffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase669() {
    int passed = 1;

    printf("%s     sbb    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sbb    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase670() {
    int passed = 1;

    printf("%s     sbb    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "sbb    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase671() {
    int passed = 1;

    printf("%s     sbb    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sbb    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase672() {
    int passed = 1;

    printf("%s     sbb    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sbb    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase673() {
    int passed = 1;

    printf("%s     sbb    rax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sbb    rax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase674() {
    int passed = 1;

    printf("%s     sbb    rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sbb    rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase675() {
    int passed = 1;

    printf("%s     sbb    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sbb    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase676() {
    int passed = 1;

    printf("%s     sbb    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "sbb    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase677() {
    int passed = 1;

    printf("%s     shl    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase678() {
    int passed = 1;

    printf("%s     shl    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase679() {
    int passed = 1;

    printf("%s     shl    ah,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x2;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase680() {
    int passed = 1;

    printf("%s     shl    ah,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x4;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase681() {
    int passed = 1;

    printf("%s     shl    ah,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x5;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase682() {
    int passed = 1;

    printf("%s     shl    ah,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x6;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase683() {
    int passed = 1;

    printf("%s     shl    ah,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,0x8;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, { });
    return passed;
}

static int testcase684() {
    int passed = 1;

    printf("%s     shl    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shl    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase685() {
    int passed = 1;

    printf("%s     shl    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase686() {
    int passed = 1;

    printf("%s     shl    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase687() {
    int passed = 1;

    printf("%s     shl    al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase688() {
    int passed = 1;

    printf("%s     shl    al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase689() {
    int passed = 1;

    printf("%s     shl    al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase690() {
    int passed = 1;

    printf("%s     shl    al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase691() {
    int passed = 1;

    printf("%s     shl    al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase692() {
    int passed = 1;

    printf("%s     shl    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shl    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase693() {
    int passed = 1;

    printf("%s     shl    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "shl    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase694() {
    int passed = 1;

    printf("%s     shl    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase695() {
    int passed = 1;

    printf("%s     shl    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase696() {
    int passed = 1;

    printf("%s     shl    ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase697() {
    int passed = 1;

    printf("%s     shl    ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase698() {
    int passed = 1;

    printf("%s     shl    ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase699() {
    int passed = 1;

    printf("%s     shl    ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase700() {
    int passed = 1;

    printf("%s     shl    ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase701() {
    int passed = 1;

    printf("%s     shl    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shl    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase702() {
    int passed = 1;

    printf("%s     shl    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "shl    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase703() {
    int passed = 1;

    printf("%s     shl    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase704() {
    int passed = 1;

    printf("%s     shl    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase705() {
    int passed = 1;

    printf("%s     shl    eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase706() {
    int passed = 1;

    printf("%s     shl    eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase707() {
    int passed = 1;

    printf("%s     shl    eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase708() {
    int passed = 1;

    printf("%s     shl    eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase709() {
    int passed = 1;

    printf("%s     shl    eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase710() {
    int passed = 1;

    printf("%s     shl    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shl    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase711() {
    int passed = 1;

    printf("%s     shl    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "shl    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase712() {
    int passed = 1;

    printf("%s     shl    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase713() {
    int passed = 1;

    printf("%s     shl    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase714() {
    int passed = 1;

    printf("%s     shl    rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase715() {
    int passed = 1;

    printf("%s     shl    rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase716() {
    int passed = 1;

    printf("%s     shl    rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase717() {
    int passed = 1;

    printf("%s     shl    rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase718() {
    int passed = 1;

    printf("%s     shl    rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase719() {
    int passed = 1;

    printf("%s     shl    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shl    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase720() {
    int passed = 1;

    printf("%s     shl    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "shl    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase721() {
    int passed = 1;

    printf("%s     shld   ax,ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shld   ax,ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase722() {
    int passed = 1;

    printf("%s     shld   ax,ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shld   ax,ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase723() {
    int passed = 1;

    printf("%s     shld   ax,ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shld   ax,ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase724() {
    int passed = 1;

    printf("%s     shld   ax,ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shld   ax,ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase725() {
    int passed = 1;

    printf("%s     shld   ax,ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shld   ax,ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase726() {
    int passed = 1;

    printf("%s     shld   ax,ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shld   ax,ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase727() {
    int passed = 1;

    printf("%s     shld   ax,ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "shld   ax,ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase728() {
    int passed = 1;

    printf("%s     shld   ax,cx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase729() {
    int passed = 1;

    printf("%s     shld   ax,cx,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {2});
    ASSERT_TAGGED((char *)&outAX + 1, {3});
    return passed;
}

static int testcase730() {
    int passed = 1;

    printf("%s     shld   ax,cx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,3});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase731() {
    int passed = 1;

    printf("%s     shld   ax,cx,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {3});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase732() {
    int passed = 1;

    printf("%s     shld   ax,cx,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outAX + 1, {0,3});
    return passed;
}

static int testcase733() {
    int passed = 1;

    printf("%s     shld   ax,cx,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outAX + 1, {0,3});
    return passed;
}

static int testcase734() {
    int passed = 1;

    printf("%s     shld   ax,cx,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shld   ax,cx,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2,3});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    return passed;
}

static int testcase735() {
    int passed = 1;

    printf("%s     shld   eax,eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shld   eax,eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase736() {
    int passed = 1;

    printf("%s     shld   eax,eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shld   eax,eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase737() {
    int passed = 1;

    printf("%s     shld   eax,eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shld   eax,eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase738() {
    int passed = 1;

    printf("%s     shld   eax,eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shld   eax,eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 1, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase739() {
    int passed = 1;

    printf("%s     shld   eax,eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shld   eax,eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase740() {
    int passed = 1;

    printf("%s     shld   eax,eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shld   eax,eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase741() {
    int passed = 1;

    printf("%s     shld   eax,eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "shld   eax,eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase742() {
    int passed = 1;

    printf("%s     shld   eax,ecx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase743() {
    int passed = 1;

    printf("%s     shld   eax,ecx,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {6});
    ASSERT_TAGGED((char *)&outRAX + 1, {7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase744() {
    int passed = 1;

    printf("%s     shld   eax,ecx,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 1, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase745() {
    int passed = 1;

    printf("%s     shld   eax,ecx,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 1, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase746() {
    int passed = 1;

    printf("%s     shld   eax,ecx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase747() {
    int passed = 1;

    printf("%s     shld   eax,ecx,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase748() {
    int passed = 1;

    printf("%s     shld   eax,ecx,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shld   eax,ecx,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase749() {
    int passed = 1;

    printf("%s     shld   rax,rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shld   rax,rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase750() {
    int passed = 1;

    printf("%s     shld   rax,rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shld   rax,rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase751() {
    int passed = 1;

    printf("%s     shld   rax,rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shld   rax,rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase752() {
    int passed = 1;

    printf("%s     shld   rax,rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shld   rax,rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase753() {
    int passed = 1;

    printf("%s     shld   rax,rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shld   rax,rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase754() {
    int passed = 1;

    printf("%s     shld   rax,rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shld   rax,rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase755() {
    int passed = 1;

    printf("%s     shld   rax,rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "shld   rax,rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase756() {
    int passed = 1;

    printf("%s     shld   rax,rcx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase757() {
    int passed = 1;

    printf("%s     shld   rax,rcx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {6,7});
    return passed;
}

static int testcase758() {
    int passed = 1;

    printf("%s     shld   rax,rcx,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {12});
    ASSERT_TAGGED((char *)&outRAX + 1, {13});
    ASSERT_TAGGED((char *)&outRAX + 2, {14});
    ASSERT_TAGGED((char *)&outRAX + 3, {15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase759() {
    int passed = 1;

    printf("%s     shld   rax,rcx,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {11,12});
    ASSERT_TAGGED((char *)&outRAX + 1, {12,13});
    ASSERT_TAGGED((char *)&outRAX + 2, {13,14});
    ASSERT_TAGGED((char *)&outRAX + 3, {14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase760() {
    int passed = 1;

    printf("%s     shld   rax,rcx,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {11,12});
    ASSERT_TAGGED((char *)&outRAX + 1, {12,13});
    ASSERT_TAGGED((char *)&outRAX + 2, {13,14});
    ASSERT_TAGGED((char *)&outRAX + 3, {14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 6, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 7, {2,3});
    return passed;
}

static int testcase761() {
    int passed = 1;

    printf("%s     shld   rax,rcx,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase762() {
    int passed = 1;

    printf("%s     shld   rax,rcx,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shld   rax,rcx,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,12,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,13,14,15});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,14,15});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,15});
    return passed;
}

static int testcase763() {
    int passed = 1;

    printf("%s     shlx   eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shlx   eax,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase764() {
    int passed = 1;

    printf("%s     shlx   eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shlx   eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase765() {
    int passed = 1;

    printf("%s     shlx   eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "shlx   eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase766() {
    int passed = 1;

    printf("%s     shlx   eax,ecx,edx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov EDX,%2;\n"
        "shlx   eax,ecx,edx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inEDX)
        :"rax","ecx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase767() {
    int passed = 1;

    printf("%s     shlx   rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shlx   rax,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase768() {
    int passed = 1;

    printf("%s     shlx   rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shlx   rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase769() {
    int passed = 1;

    printf("%s     shlx   rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "shlx   rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase770() {
    int passed = 1;

    printf("%s     shlx   rax,rcx,rdx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov RDX,%2;\n"
        "shlx   rax,rcx,rdx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase771() {
    int passed = 1;

    printf("%s     shr    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase772() {
    int passed = 1;

    printf("%s     shr    ah,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase773() {
    int passed = 1;

    printf("%s     shr    ah,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x2;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase774() {
    int passed = 1;

    printf("%s     shr    ah,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x4;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase775() {
    int passed = 1;

    printf("%s     shr    ah,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x5;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase776() {
    int passed = 1;

    printf("%s     shr    ah,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x6;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase777() {
    int passed = 1;

    printf("%s     shr    ah,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,0x8;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, { });
    return passed;
}

static int testcase778() {
    int passed = 1;

    printf("%s     shr    ah,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "shr    ah,1;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase779() {
    int passed = 1;

    printf("%s     shr    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase780() {
    int passed = 1;

    printf("%s     shr    al,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase781() {
    int passed = 1;

    printf("%s     shr    al,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x2;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase782() {
    int passed = 1;

    printf("%s     shr    al,0x4\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x4;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase783() {
    int passed = 1;

    printf("%s     shr    al,0x5\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x5;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase784() {
    int passed = 1;

    printf("%s     shr    al,0x6\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x6;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase785() {
    int passed = 1;

    printf("%s     shr    al,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,0x8;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase786() {
    int passed = 1;

    printf("%s     shr    al,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "shr    al,1;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase787() {
    int passed = 1;

    printf("%s     shr    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "shr    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase788() {
    int passed = 1;

    printf("%s     shr    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase789() {
    int passed = 1;

    printf("%s     shr    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase790() {
    int passed = 1;

    printf("%s     shr    ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase791() {
    int passed = 1;

    printf("%s     shr    ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase792() {
    int passed = 1;

    printf("%s     shr    ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase793() {
    int passed = 1;

    printf("%s     shr    ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase794() {
    int passed = 1;

    printf("%s     shr    ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase795() {
    int passed = 1;

    printf("%s     shr    ax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shr    ax,1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase796() {
    int passed = 1;

    printf("%s     shr    ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "shr    ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2});
    return passed;
}

static int testcase797() {
    int passed = 1;

    printf("%s     shr    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase798() {
    int passed = 1;

    printf("%s     shr    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase799() {
    int passed = 1;

    printf("%s     shr    eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase800() {
    int passed = 1;

    printf("%s     shr    eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase801() {
    int passed = 1;

    printf("%s     shr    eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase802() {
    int passed = 1;

    printf("%s     shr    eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase803() {
    int passed = 1;

    printf("%s     shr    eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase804() {
    int passed = 1;

    printf("%s     shr    eax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shr    eax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase805() {
    int passed = 1;

    printf("%s     shr    eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "shr    eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase806() {
    int passed = 1;

    printf("%s     shr    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase807() {
    int passed = 1;

    printf("%s     shr    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase808() {
    int passed = 1;

    printf("%s     shr    rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase809() {
    int passed = 1;

    printf("%s     shr    rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase810() {
    int passed = 1;

    printf("%s     shr    rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase811() {
    int passed = 1;

    printf("%s     shr    rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase812() {
    int passed = 1;

    printf("%s     shr    rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase813() {
    int passed = 1;

    printf("%s     shr    rax,1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shr    rax,1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase814() {
    int passed = 1;

    printf("%s     shr    rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "shr    rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase815() {
    int passed = 1;

    printf("%s     shrd   ax,ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shrd   ax,ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase816() {
    int passed = 1;

    printf("%s     shrd   ax,ax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shrd   ax,ax,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase817() {
    int passed = 1;

    printf("%s     shrd   ax,ax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shrd   ax,ax,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase818() {
    int passed = 1;

    printf("%s     shrd   ax,ax,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shrd   ax,ax,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase819() {
    int passed = 1;

    printf("%s     shrd   ax,ax,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shrd   ax,ax,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase820() {
    int passed = 1;

    printf("%s     shrd   ax,ax,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "shrd   ax,ax,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase821() {
    int passed = 1;

    printf("%s     shrd   ax,ax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t inCL = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AX,%1;\n"
        "mov CL,%2;\n"
        "shrd   ax,ax,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCL)
        :"ax","cl"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2});
    return passed;
}

static int testcase822() {
    int passed = 1;

    printf("%s     shrd   ax,cx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase823() {
    int passed = 1;

    printf("%s     shrd   ax,cx,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,0x10;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {2});
    ASSERT_TAGGED((char *)&outAX + 1, {3});
    return passed;
}

static int testcase824() {
    int passed = 1;

    printf("%s     shrd   ax,cx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,0x2;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2});
    return passed;
}

static int testcase825() {
    int passed = 1;

    printf("%s     shrd   ax,cx,0x8\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,0x8;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {2});
    return passed;
}

static int testcase826() {
    int passed = 1;

    printf("%s     shrd   ax,cx,0x9\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,0x9;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {2,3});
    return passed;
}

static int testcase827() {
    int passed = 1;

    printf("%s     shrd   ax,cx,0xa\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,0xa;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {2,3});
    return passed;
}

static int testcase828() {
    int passed = 1;

    printf("%s     shrd   ax,cx,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "shrd   ax,cx,cl;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,1,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,2,3});
    return passed;
}

static int testcase829() {
    int passed = 1;

    printf("%s     shrd   eax,eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrd   eax,eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase830() {
    int passed = 1;

    printf("%s     shrd   eax,eax,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrd   eax,eax,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0});
    ASSERT_TAGGED((char *)&outRAX + 3, {1});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase831() {
    int passed = 1;

    printf("%s     shrd   eax,eax,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrd   eax,eax,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase832() {
    int passed = 1;

    printf("%s     shrd   eax,eax,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrd   eax,eax,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 3, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase833() {
    int passed = 1;

    printf("%s     shrd   eax,eax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrd   eax,eax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase834() {
    int passed = 1;

    printf("%s     shrd   eax,eax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrd   eax,eax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase835() {
    int passed = 1;

    printf("%s     shrd   eax,eax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "shrd   eax,eax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase836() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase837() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,0x10\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,0x10;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2});
    ASSERT_TAGGED((char *)&outRAX + 1, {3});
    ASSERT_TAGGED((char *)&outRAX + 2, {4});
    ASSERT_TAGGED((char *)&outRAX + 3, {5});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase838() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,0x11\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,0x11;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 3, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase839() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,0x12\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,0x12;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 3, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase840() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase841() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase842() {
    int passed = 1;

    printf("%s     shrd   eax,ecx,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrd   eax,ecx,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase843() {
    int passed = 1;

    printf("%s     shrd   rax,rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrd   rax,rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase844() {
    int passed = 1;

    printf("%s     shrd   rax,rax,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrd   rax,rax,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase845() {
    int passed = 1;

    printf("%s     shrd   rax,rax,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrd   rax,rax,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0});
    ASSERT_TAGGED((char *)&outRAX + 5, {1});
    ASSERT_TAGGED((char *)&outRAX + 6, {2});
    ASSERT_TAGGED((char *)&outRAX + 7, {3});
    return passed;
}

static int testcase846() {
    int passed = 1;

    printf("%s     shrd   rax,rax,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrd   rax,rax,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase847() {
    int passed = 1;

    printf("%s     shrd   rax,rax,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrd   rax,rax,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 5, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 6, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 7, {3,4});
    return passed;
}

static int testcase848() {
    int passed = 1;

    printf("%s     shrd   rax,rax,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrd   rax,rax,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase849() {
    int passed = 1;

    printf("%s     shrd   rax,rax,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "shrd   rax,rax,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8});
    return passed;
}

static int testcase850() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase851() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,0x2\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,0x2;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase852() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,0x20\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,0x20;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, {8});
    ASSERT_TAGGED((char *)&outRAX + 5, {9});
    ASSERT_TAGGED((char *)&outRAX + 6, {10});
    ASSERT_TAGGED((char *)&outRAX + 7, {11});
    return passed;
}

static int testcase853() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,0x21\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,0x21;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {8,9});
    ASSERT_TAGGED((char *)&outRAX + 5, {9,10});
    ASSERT_TAGGED((char *)&outRAX + 6, {10,11});
    ASSERT_TAGGED((char *)&outRAX + 7, {11,12});
    return passed;
}

static int testcase854() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,0x22\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,0x22;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4,5});
    ASSERT_TAGGED((char *)&outRAX + 1, {5,6});
    ASSERT_TAGGED((char *)&outRAX + 2, {6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {8,9});
    ASSERT_TAGGED((char *)&outRAX + 5, {9,10});
    ASSERT_TAGGED((char *)&outRAX + 6, {10,11});
    ASSERT_TAGGED((char *)&outRAX + 7, {11,12});
    return passed;
}

static int testcase855() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,0x40\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,0x40;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase856() {
    int passed = 1;

    printf("%s     shrd   rax,rcx,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrd   rax,rcx,cl;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase857() {
    int passed = 1;

    printf("%s     shrx   eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "shrx   eax,eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase858() {
    int passed = 1;

    printf("%s     shrx   eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "shrx   eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase859() {
    int passed = 1;

    printf("%s     shrx   eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "shrx   eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase860() {
    int passed = 1;

    printf("%s     shrx   eax,ecx,edx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint32_t inEDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inEDX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "mov EDX,%2;\n"
        "shrx   eax,ecx,edx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inEDX)
        :"rax","ecx","edx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase861() {
    int passed = 1;

    printf("%s     shrx   rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "shrx   rax,rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase862() {
    int passed = 1;

    printf("%s     shrx   rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "shrx   rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase863() {
    int passed = 1;

    printf("%s     shrx   rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "shrx   rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,6,7});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,7});
    return passed;
}

static int testcase864() {
    int passed = 1;

    printf("%s     shrx   rax,rcx,rdx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t inRDX = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inRDX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "mov RDX,%2;\n"
        "shrx   rax,rcx,rdx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inRDX)
        :"rax","rcx","rdx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,7,8});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,8});
    return passed;
}

static int testcase865() {
    int passed = 1;

    printf("%s     sub    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sub    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase866() {
    int passed = 1;

    printf("%s     sub    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sub    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase867() {
    int passed = 1;

    printf("%s     sub    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "sub    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, { });
    return passed;
}

static int testcase868() {
    int passed = 1;

    printf("%s     sub    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sub    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase869() {
    int passed = 1;

    printf("%s     sub    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "sub    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase870() {
    int passed = 1;

    printf("%s     sub    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sub    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase871() {
    int passed = 1;

    printf("%s     sub    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sub    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase872() {
    int passed = 1;

    printf("%s     sub    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "sub    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase873() {
    int passed = 1;

    printf("%s     sub    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "sub    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase874() {
    int passed = 1;

    printf("%s     sub    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sub    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase875() {
    int passed = 1;

    printf("%s     sub    ax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sub    ax,0x1;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase876() {
    int passed = 1;

    printf("%s     sub    ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sub    ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase877() {
    int passed = 1;

    printf("%s     sub    ax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sub    ax,0xffff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase878() {
    int passed = 1;

    printf("%s     sub    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "sub    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase879() {
    int passed = 1;

    printf("%s     sub    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "sub    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    return passed;
}

static int testcase880() {
    int passed = 1;

    printf("%s     sub    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "sub    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase881() {
    int passed = 1;

    printf("%s     sub    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sub    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase882() {
    int passed = 1;

    printf("%s     sub    eax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sub    eax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase883() {
    int passed = 1;

    printf("%s     sub    eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sub    eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase884() {
    int passed = 1;

    printf("%s     sub    eax,0xffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sub    eax,0xffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase885() {
    int passed = 1;

    printf("%s     sub    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "sub    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase886() {
    int passed = 1;

    printf("%s     sub    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "sub    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase887() {
    int passed = 1;

    printf("%s     sub    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sub    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase888() {
    int passed = 1;

    printf("%s     sub    rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sub    rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase889() {
    int passed = 1;

    printf("%s     sub    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "sub    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase890() {
    int passed = 1;

    printf("%s     sub    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "sub    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    return passed;
}

static int testcase891() {
    int passed = 1;

    printf("%s     xadd   ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "xadd   ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase892() {
    int passed = 1;

    printf("%s     xadd   ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xadd   ah,al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase893() {
    int passed = 1;

    printf("%s     xadd   ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%2;\n"
        "mov CH,%3;\n"
        "xadd   ah,ch;\n" // <--
        "mov %0,AH;\n"
        "mov %1,CH;\n"
        :"=m"(outAH),"=m"(outCH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    ASSERT_TAGGED((char *)&outCH + 0, {0});
    return passed;
}

static int testcase894() {
    int passed = 1;

    printf("%s     xadd   al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "xadd   al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase895() {
    int passed = 1;

    printf("%s     xadd   al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    uint8_t outCL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%2;\n"
        "mov CL,%3;\n"
        "xadd   al,cl;\n" // <--
        "mov %0,AL;\n"
        "mov %1,CL;\n"
        :"=m"(outAL),"=m"(outCL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    ASSERT_TAGGED((char *)&outCL + 0, {0});
    return passed;
}

static int testcase896() {
    int passed = 1;

    printf("%s     xadd   ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xadd   ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1});
    return passed;
}

static int testcase897() {
    int passed = 1;

    printf("%s     xadd   ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "xadd   ax,cx;\n" // <--
        "mov %0,AX;\n"
        "mov %1,CX;\n"
        :"=m"(outAX),"=m"(outCX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {0,1,2,3});
    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {1});
    return passed;
}

static int testcase898() {
    int passed = 1;

    printf("%s     xadd   ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outAL = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%2;\n"
        "mov CH,%3;\n"
        "xadd   ch,al;\n" // <--
        "mov %0,AL;\n"
        "mov %1,CH;\n"
        :"=m"(outAL),"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {1});
    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase899() {
    int passed = 1;

    printf("%s     xadd   eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "xadd   eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase900() {
    int passed = 1;

    printf("%s     xadd   eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "xadd   eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inEAX),"m"(inECX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,4,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,4,5,6,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {1});
    ASSERT_TAGGED((char *)&outRCX + 2, {2});
    ASSERT_TAGGED((char *)&outRCX + 3, {3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase901() {
    int passed = 1;

    printf("%s     xadd   rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "xadd   rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7});
    return passed;
}

static int testcase902() {
    int passed = 1;

    printf("%s     xadd   rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "xadd   rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {0,1,8,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {0,1,2,8,9,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {0,1,2,3,8,9,10,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {0,1,2,3,4,8,9,10,11,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {0,1,2,3,4,5,8,9,10,11,12,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {0,1,2,3,4,5,6,8,9,10,11,12,13,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {1});
    ASSERT_TAGGED((char *)&outRCX + 2, {2});
    ASSERT_TAGGED((char *)&outRCX + 3, {3});
    ASSERT_TAGGED((char *)&outRCX + 4, {4});
    ASSERT_TAGGED((char *)&outRCX + 5, {5});
    ASSERT_TAGGED((char *)&outRCX + 6, {6});
    ASSERT_TAGGED((char *)&outRCX + 7, {7});
    return passed;
}

static int testcase903() {
    int passed = 1;

    printf("%s     xchg   ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "xchg   ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase904() {
    int passed = 1;

    printf("%s     xchg   ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xchg   ah,al;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {1});
    ASSERT_TAGGED((char *)&outAX + 1, {0});
    return passed;
}

static int testcase905() {
    int passed = 1;

    printf("%s     xchg   ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%2;\n"
        "mov CH,%3;\n"
        "xchg   ah,ch;\n" // <--
        "mov %0,AH;\n"
        "mov %1,CH;\n"
        :"=m"(outAH),"=m"(outCH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {1});
    ASSERT_TAGGED((char *)&outCH + 0, {0});
    return passed;
}

static int testcase906() {
    int passed = 1;

    printf("%s     xchg   al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "xchg   al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase907() {
    int passed = 1;

    printf("%s     xchg   al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    uint8_t outCL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%2;\n"
        "mov CL,%3;\n"
        "xchg   al,cl;\n" // <--
        "mov %0,AL;\n"
        "mov %1,CL;\n"
        :"=m"(outAL),"=m"(outCL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {1});
    ASSERT_TAGGED((char *)&outCL + 0, {0});
    return passed;
}

static int testcase908() {
    int passed = 1;

    printf("%s     xchg   ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xchg   ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase909() {
    int passed = 1;

    printf("%s     xchg   ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "xchg   ax,cx;\n" // <--
        "mov %0,AX;\n"
        "mov %1,CX;\n"
        :"=m"(outAX),"=m"(outCX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {2});
    ASSERT_TAGGED((char *)&outAX + 1, {3});
    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {1});
    return passed;
}

static int testcase910() {
    int passed = 1;

    printf("%s     xchg   ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outAL = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%2;\n"
        "mov CH,%3;\n"
        "xchg   ch,al;\n" // <--
        "mov %0,AL;\n"
        "mov %1,CH;\n"
        :"=m"(outAL),"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {1});
    ASSERT_TAGGED((char *)&outCH + 0, {0});
    return passed;
}

static int testcase911() {
    int passed = 1;

    printf("%s     xchg   cx,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    uint16_t outCX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%2;\n"
        "mov CX,%3;\n"
        "xchg   cx,ax;\n" // <--
        "mov %0,AX;\n"
        "mov %1,CX;\n"
        :"=m"(outAX),"=m"(outCX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {2});
    ASSERT_TAGGED((char *)&outAX + 1, {3});
    ASSERT_TAGGED((char *)&outCX + 0, {0});
    ASSERT_TAGGED((char *)&outCX + 1, {1});
    return passed;
}

static int testcase912() {
    int passed = 1;

    printf("%s     xchg   eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "xchg   eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase913() {
    int passed = 1;

    printf("%s     xchg   eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "xchg   eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inEAX),"m"(inECX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {1});
    ASSERT_TAGGED((char *)&outRCX + 2, {2});
    ASSERT_TAGGED((char *)&outRCX + 3, {3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase914() {
    int passed = 1;

    printf("%s     xchg   ecx,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%2;\n"
        "mov ECX,%3;\n"
        "xchg   ecx,eax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inEAX),"m"(inECX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {4});
    ASSERT_TAGGED((char *)&outRAX + 1, {5});
    ASSERT_TAGGED((char *)&outRAX + 2, {6});
    ASSERT_TAGGED((char *)&outRAX + 3, {7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {1});
    ASSERT_TAGGED((char *)&outRCX + 2, {2});
    ASSERT_TAGGED((char *)&outRCX + 3, {3});
    ASSERT_TAGGED((char *)&outRCX + 4, { });
    ASSERT_TAGGED((char *)&outRCX + 5, { });
    ASSERT_TAGGED((char *)&outRCX + 6, { });
    ASSERT_TAGGED((char *)&outRCX + 7, { });
    return passed;
}

static int testcase915() {
    int passed = 1;

    printf("%s     xchg   rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "xchg   rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase916() {
    int passed = 1;

    printf("%s     xchg   rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "xchg   rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {8});
    ASSERT_TAGGED((char *)&outRAX + 1, {9});
    ASSERT_TAGGED((char *)&outRAX + 2, {10});
    ASSERT_TAGGED((char *)&outRAX + 3, {11});
    ASSERT_TAGGED((char *)&outRAX + 4, {12});
    ASSERT_TAGGED((char *)&outRAX + 5, {13});
    ASSERT_TAGGED((char *)&outRAX + 6, {14});
    ASSERT_TAGGED((char *)&outRAX + 7, {15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {1});
    ASSERT_TAGGED((char *)&outRCX + 2, {2});
    ASSERT_TAGGED((char *)&outRCX + 3, {3});
    ASSERT_TAGGED((char *)&outRCX + 4, {4});
    ASSERT_TAGGED((char *)&outRCX + 5, {5});
    ASSERT_TAGGED((char *)&outRCX + 6, {6});
    ASSERT_TAGGED((char *)&outRCX + 7, {7});
    return passed;
}

static int testcase917() {
    int passed = 1;

    printf("%s     xchg   rcx,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    uint64_t outRCX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%2;\n"
        "mov RCX,%3;\n"
        "xchg   rcx,rax;\n" // <--
        "mov %0,RAX;\n"
        "mov %1,RCX;\n"
        :"=m"(outRAX),"=m"(outRCX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {8});
    ASSERT_TAGGED((char *)&outRAX + 1, {9});
    ASSERT_TAGGED((char *)&outRAX + 2, {10});
    ASSERT_TAGGED((char *)&outRAX + 3, {11});
    ASSERT_TAGGED((char *)&outRAX + 4, {12});
    ASSERT_TAGGED((char *)&outRAX + 5, {13});
    ASSERT_TAGGED((char *)&outRAX + 6, {14});
    ASSERT_TAGGED((char *)&outRAX + 7, {15});
    ASSERT_TAGGED((char *)&outRCX + 0, {0});
    ASSERT_TAGGED((char *)&outRCX + 1, {1});
    ASSERT_TAGGED((char *)&outRCX + 2, {2});
    ASSERT_TAGGED((char *)&outRCX + 3, {3});
    ASSERT_TAGGED((char *)&outRCX + 4, {4});
    ASSERT_TAGGED((char *)&outRCX + 5, {5});
    ASSERT_TAGGED((char *)&outRCX + 6, {6});
    ASSERT_TAGGED((char *)&outRCX + 7, {7});
    return passed;
}

static int testcase918() {
    int passed = 1;

    printf("%s     xor    ah,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "xor    ah,0x0;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase919() {
    int passed = 1;

    printf("%s     xor    ah,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "xor    ah,0xf;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0});
    return passed;
}

static int testcase920() {
    int passed = 1;

    printf("%s     xor    ah,ah\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "xor    ah,ah;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH)
        :"ah"
    );

    ASSERT_TAGGED((char *)&outAH + 0, { });
    return passed;
}

static int testcase921() {
    int passed = 1;

    printf("%s     xor    ah,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xor    ah,al;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase922() {
    int passed = 1;

    printf("%s     xor    ah,ch\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAH = 1;
    uint8_t inCH = 1;
    uint8_t outAH = 1;
    __gtaint_setn(&inAH, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AH,%1;\n"
        "mov CH,%2;\n"
        "xor    ah,ch;\n" // <--
        "mov %0,AH;\n"
        :"=m"(outAH)
        :"m"(inAH),"m"(inCH)
        :"ah","ch"
    );

    ASSERT_TAGGED((char *)&outAH + 0, {0,1});
    return passed;
}

static int testcase923() {
    int passed = 1;

    printf("%s     xor    al,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "xor    al,0x0;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase924() {
    int passed = 1;

    printf("%s     xor    al,0xf\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "xor    al,0xf;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0});
    return passed;
}

static int testcase925() {
    int passed = 1;

    printf("%s     xor    al,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "xor    al,al;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL)
        :"al"
    );

    ASSERT_TAGGED((char *)&outAL + 0, { });
    return passed;
}

static int testcase926() {
    int passed = 1;

    printf("%s     xor    al,cl\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCL = 1;
    uint8_t outAL = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CL,%2;\n"
        "xor    al,cl;\n" // <--
        "mov %0,AL;\n"
        :"=m"(outAL)
        :"m"(inAL),"m"(inCL)
        :"al","cl"
    );

    ASSERT_TAGGED((char *)&outAL + 0, {0,1});
    return passed;
}

static int testcase927() {
    int passed = 1;

    printf("%s     xor    ax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xor    ax,0x0;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase928() {
    int passed = 1;

    printf("%s     xor    ax,0xff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xor    ax,0xff;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0});
    ASSERT_TAGGED((char *)&outAX + 1, {1});
    return passed;
}

static int testcase929() {
    int passed = 1;

    printf("%s     xor    ax,ax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "xor    ax,ax;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX)
        :"ax"
    );

    ASSERT_TAGGED((char *)&outAX + 0, { });
    ASSERT_TAGGED((char *)&outAX + 1, { });
    return passed;
}

static int testcase930() {
    int passed = 1;

    printf("%s     xor    ax,cx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint16_t inAX = 1;
    uint16_t inCX = 1;
    uint16_t outAX = 1;
    __gtaint_setn(&inAX, 2);
    __gtaint_setn(&inCX, 2);
    asm volatile (
        "mov AX,%1;\n"
        "mov CX,%2;\n"
        "xor    ax,cx;\n" // <--
        "mov %0,AX;\n"
        :"=m"(outAX)
        :"m"(inAX),"m"(inCX)
        :"ax","cx"
    );

    ASSERT_TAGGED((char *)&outAX + 0, {0,2});
    ASSERT_TAGGED((char *)&outAX + 1, {1,3});
    return passed;
}

static int testcase931() {
    int passed = 1;

    printf("%s     xor    ch,al\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint8_t inAL = 1;
    uint8_t inCH = 1;
    uint8_t outCH = 1;
    __gtaint_setn(&inAL, 1);
    __gtaint_setn(&inCH, 1);
    asm volatile (
        "mov AL,%1;\n"
        "mov CH,%2;\n"
        "xor    ch,al;\n" // <--
        "mov %0,CH;\n"
        :"=m"(outCH)
        :"m"(inAL),"m"(inCH)
        :"al","ch"
    );

    ASSERT_TAGGED((char *)&outCH + 0, {0,1});
    return passed;
}

static int testcase932() {
    int passed = 1;

    printf("%s     xor    eax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "xor    eax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase933() {
    int passed = 1;

    printf("%s     xor    eax,0xffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "xor    eax,0xffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase934() {
    int passed = 1;

    printf("%s     xor    eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "xor    eax,eax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase935() {
    int passed = 1;

    printf("%s     xor    eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "mov ECX,%2;\n"
        "xor    eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inECX)
        :"rax","ecx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,4});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,5});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,6});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,7});
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase936() {
    int passed = 1;

    printf("%s     xor    rax,0x0\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "xor    rax,0x0;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase937() {
    int passed = 1;

    printf("%s     xor    rax,0x1\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "xor    rax,0x1;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase938() {
    int passed = 1;

    printf("%s     xor    rax,0xffffffffffffffff\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "xor    rax,0xffffffffffffffff;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0});
    ASSERT_TAGGED((char *)&outRAX + 1, {1});
    ASSERT_TAGGED((char *)&outRAX + 2, {2});
    ASSERT_TAGGED((char *)&outRAX + 3, {3});
    ASSERT_TAGGED((char *)&outRAX + 4, {4});
    ASSERT_TAGGED((char *)&outRAX + 5, {5});
    ASSERT_TAGGED((char *)&outRAX + 6, {6});
    ASSERT_TAGGED((char *)&outRAX + 7, {7});
    return passed;
}

static int testcase939() {
    int passed = 1;

    printf("%s     xor    rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "xor    rax,rax;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX)
        :"rax"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, { });
    ASSERT_TAGGED((char *)&outRAX + 1, { });
    ASSERT_TAGGED((char *)&outRAX + 2, { });
    ASSERT_TAGGED((char *)&outRAX + 3, { });
    ASSERT_TAGGED((char *)&outRAX + 4, { });
    ASSERT_TAGGED((char *)&outRAX + 5, { });
    ASSERT_TAGGED((char *)&outRAX + 6, { });
    ASSERT_TAGGED((char *)&outRAX + 7, { });
    return passed;
}

static int testcase940() {
    int passed = 1;

    printf("%s     xor    rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "mov RCX,%2;\n"
        "xor    rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inRCX)
        :"rax","rcx"
    );

    ASSERT_TAGGED((char *)&outRAX + 0, {0,8});
    ASSERT_TAGGED((char *)&outRAX + 1, {1,9});
    ASSERT_TAGGED((char *)&outRAX + 2, {2,10});
    ASSERT_TAGGED((char *)&outRAX + 3, {3,11});
    ASSERT_TAGGED((char *)&outRAX + 4, {4,12});
    ASSERT_TAGGED((char *)&outRAX + 5, {5,13});
    ASSERT_TAGGED((char *)&outRAX + 6, {6,14});
    ASSERT_TAGGED((char *)&outRAX + 7, {7,15});
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
    add_testcase(testcase12);
    add_testcase(testcase13);
    add_testcase(testcase14);
    add_testcase(testcase15);
    add_testcase(testcase16);
    add_testcase(testcase17);
    add_testcase(testcase18);
    add_testcase(testcase19);
    add_testcase(testcase20);
    add_testcase(testcase21);
    add_testcase(testcase22);
    add_testcase(testcase23);
    add_testcase(testcase24);
    add_testcase(testcase25);
    add_testcase(testcase26);
    add_testcase(testcase27);
    add_testcase(testcase28);
    add_testcase(testcase29);
    add_testcase(testcase30);
    add_testcase(testcase31);
    add_testcase(testcase32);
    add_testcase(testcase33);
    add_testcase(testcase34);
    add_testcase(testcase35);
    add_testcase(testcase36);
    add_testcase(testcase37);
    add_testcase(testcase38);
    add_testcase(testcase39);
    add_testcase(testcase40);
    add_testcase(testcase41);
    add_testcase(testcase42);
    add_testcase(testcase43);
    add_testcase(testcase44);
    add_testcase(testcase45);
    add_testcase(testcase46);
    add_testcase(testcase47);
    add_testcase(testcase48);
    add_testcase(testcase49);
    add_testcase(testcase50);
    add_testcase(testcase51);
    add_testcase(testcase52);
    add_testcase(testcase53);
    add_testcase(testcase54);
    add_testcase(testcase55);
    add_testcase(testcase56);
    add_testcase(testcase57);
    add_testcase(testcase58);
    add_testcase(testcase59);
    add_testcase(testcase60);
    add_testcase(testcase61);
    add_testcase(testcase62);
    add_testcase(testcase63);
    add_testcase(testcase64);
    add_testcase(testcase65);
    add_testcase(testcase66);
    add_testcase(testcase67);
    add_testcase(testcase68);
    add_testcase(testcase69);
    add_testcase(testcase70);
    add_testcase(testcase71);
    add_testcase(testcase72);
    add_testcase(testcase73);
    add_testcase(testcase74);
    add_testcase(testcase75);
    add_testcase(testcase76);
    add_testcase(testcase77);
    add_testcase(testcase78);
    add_testcase(testcase79);
    add_testcase(testcase80);
    add_testcase(testcase81);
    add_testcase(testcase82);
    add_testcase(testcase83);
    add_testcase(testcase84);
    add_testcase(testcase85);
    add_testcase(testcase86);
    add_testcase(testcase87);
    add_testcase(testcase88);
    add_testcase(testcase89);
    add_testcase(testcase90);
    add_testcase(testcase91);
    add_testcase(testcase92);
    add_testcase(testcase93);
    add_testcase(testcase94);
    add_testcase(testcase95);
    add_testcase(testcase96);
    add_testcase(testcase97);
    add_testcase(testcase98);
    add_testcase(testcase99);
    add_testcase(testcase100);
    add_testcase(testcase101);
    add_testcase(testcase102);
    add_testcase(testcase103);
    add_testcase(testcase104);
    add_testcase(testcase105);
    add_testcase(testcase106);
    add_testcase(testcase107);
    add_testcase(testcase108);
    add_testcase(testcase109);
    add_testcase(testcase110);
    add_testcase(testcase111);
    add_testcase(testcase112);
    add_testcase(testcase113);
    add_testcase(testcase114);
    add_testcase(testcase115);
    add_testcase(testcase116);
    add_testcase(testcase117);
    add_testcase(testcase118);
    add_testcase(testcase119);
    add_testcase(testcase120);
    add_testcase(testcase121);
    add_testcase(testcase122);
    add_testcase(testcase123);
    add_testcase(testcase124);
    add_testcase(testcase125);
    add_testcase(testcase126);
    add_testcase(testcase127);
    add_testcase(testcase128);
    add_testcase(testcase129);
    add_testcase(testcase130);
    add_testcase(testcase131);
    add_testcase(testcase132);
    add_testcase(testcase133);
    add_testcase(testcase134);
    add_testcase(testcase135);
    add_testcase(testcase136);
    add_testcase(testcase137);
    add_testcase(testcase138);
    add_testcase(testcase139);
    add_testcase(testcase140);
    add_testcase(testcase141);
    add_testcase(testcase142);
    add_testcase(testcase143);
    add_testcase(testcase144);
    add_testcase(testcase145);
    add_testcase(testcase146);
    add_testcase(testcase147);
    add_testcase(testcase148);
    add_testcase(testcase149);
    add_testcase(testcase150);
    add_testcase(testcase151);
    add_testcase(testcase152);
    add_testcase(testcase153);
    add_testcase(testcase154);
    add_testcase(testcase155);
    add_testcase(testcase156);
    add_testcase(testcase157);
    add_testcase(testcase158);
    add_testcase(testcase159);
    add_testcase(testcase160);
    add_testcase(testcase161);
    add_testcase(testcase162);
    add_testcase(testcase163);
    add_testcase(testcase164);
    add_testcase(testcase165);
    add_testcase(testcase166);
    add_testcase(testcase167);
    add_testcase(testcase168);
    add_testcase(testcase169);
    add_testcase(testcase170);
    add_testcase(testcase171);
    add_testcase(testcase172);
    add_testcase(testcase173);
    add_testcase(testcase174);
    add_testcase(testcase175);
    add_testcase(testcase176);
    add_testcase(testcase177);
    add_testcase(testcase178);
    add_testcase(testcase179);
    add_testcase(testcase180);
    add_testcase(testcase181);
    add_testcase(testcase182);
    add_testcase(testcase183);
    add_testcase(testcase184);
    add_testcase(testcase185);
    add_testcase(testcase186);
    add_testcase(testcase187);
    add_testcase(testcase188);
    add_testcase(testcase189);
    add_testcase(testcase190);
    add_testcase(testcase191);
    add_testcase(testcase192);
    add_testcase(testcase193);
    add_testcase(testcase194);
    add_testcase(testcase195);
    add_testcase(testcase196);
    add_testcase(testcase197);
    add_testcase(testcase198);
    add_testcase(testcase199);
    add_testcase(testcase200);
    add_testcase(testcase201);
    add_testcase(testcase202);
    add_testcase(testcase203);
    add_testcase(testcase204);
    add_testcase(testcase205);
    add_testcase(testcase206);
    add_testcase(testcase207);
    add_testcase(testcase208);
    add_testcase(testcase209);
    add_testcase(testcase210);
    add_testcase(testcase211);
    add_testcase(testcase212);
    add_testcase(testcase213);
    add_testcase(testcase214);
    add_testcase(testcase215);
    add_testcase(testcase216);
    add_testcase(testcase217);
    add_testcase(testcase218);
    add_testcase(testcase219);
    add_testcase(testcase220);
    add_testcase(testcase221);
    add_testcase(testcase222);
    add_testcase(testcase223);
    add_testcase(testcase224);
    add_testcase(testcase225);
    add_testcase(testcase226);
    add_testcase(testcase227);
    add_testcase(testcase228);
    add_testcase(testcase229);
    add_testcase(testcase230);
    add_testcase(testcase231);
    add_testcase(testcase232);
    add_testcase(testcase233);
    add_testcase(testcase234);
    add_testcase(testcase235);
    add_testcase(testcase236);
    add_testcase(testcase237);
    add_testcase(testcase238);
    add_testcase(testcase239);
    add_testcase(testcase240);
    add_testcase(testcase241);
    add_testcase(testcase242);
    add_testcase(testcase243);
    add_testcase(testcase244);
    add_testcase(testcase245);
    add_testcase(testcase246);
    add_testcase(testcase247);
    add_testcase(testcase248);
    add_testcase(testcase249);
    add_testcase(testcase250);
    add_testcase(testcase251);
    add_testcase(testcase252);
    add_testcase(testcase253);
    add_testcase(testcase254);
    add_testcase(testcase255);
    add_testcase(testcase256);
    add_testcase(testcase257);
    add_testcase(testcase258);
    add_testcase(testcase259);
    add_testcase(testcase260);
    add_testcase(testcase261);
    add_testcase(testcase262);
    add_testcase(testcase263);
    add_testcase(testcase264);
    add_testcase(testcase265);
    add_testcase(testcase266);
    add_testcase(testcase267);
    add_testcase(testcase268);
    add_testcase(testcase269);
    add_testcase(testcase270);
    add_testcase(testcase271);
    add_testcase(testcase272);
    add_testcase(testcase273);
    add_testcase(testcase274);
    add_testcase(testcase275);
    add_testcase(testcase276);
    add_testcase(testcase277);
    add_testcase(testcase278);
    add_testcase(testcase279);
    add_testcase(testcase280);
    add_testcase(testcase281);
    add_testcase(testcase282);
    add_testcase(testcase283);
    add_testcase(testcase284);
    add_testcase(testcase285);
    add_testcase(testcase286);
    add_testcase(testcase287);
    add_testcase(testcase288);
    add_testcase(testcase289);
    add_testcase(testcase290);
    add_testcase(testcase291);
    add_testcase(testcase292);
    add_testcase(testcase293);
    add_testcase(testcase294);
    add_testcase(testcase295);
    add_testcase(testcase296);
    add_testcase(testcase297);
    add_testcase(testcase298);
    add_testcase(testcase299);
    add_testcase(testcase300);
    add_testcase(testcase301);
    add_testcase(testcase302);
    add_testcase(testcase303);
    add_testcase(testcase304);
    add_testcase(testcase305);
    add_testcase(testcase306);
    add_testcase(testcase307);
    add_testcase(testcase308);
    add_testcase(testcase309);
    add_testcase(testcase310);
    add_testcase(testcase311);
    add_testcase(testcase312);
    add_testcase(testcase313);
    add_testcase(testcase314);
    add_testcase(testcase315);
    add_testcase(testcase316);
    add_testcase(testcase317);
    add_testcase(testcase318);
    add_testcase(testcase319);
    add_testcase(testcase320);
    add_testcase(testcase321);
    add_testcase(testcase322);
    add_testcase(testcase323);
    add_testcase(testcase324);
    add_testcase(testcase325);
    add_testcase(testcase326);
    add_testcase(testcase327);
    add_testcase(testcase328);
    add_testcase(testcase329);
    add_testcase(testcase330);
    add_testcase(testcase331);
    add_testcase(testcase332);
    add_testcase(testcase333);
    add_testcase(testcase334);
    add_testcase(testcase335);
    add_testcase(testcase336);
    add_testcase(testcase337);
    add_testcase(testcase338);
    add_testcase(testcase339);
    add_testcase(testcase340);
    add_testcase(testcase341);
    add_testcase(testcase342);
    add_testcase(testcase343);
    add_testcase(testcase344);
    add_testcase(testcase345);
    add_testcase(testcase346);
    add_testcase(testcase347);
    add_testcase(testcase348);
    add_testcase(testcase349);
    add_testcase(testcase350);
    add_testcase(testcase351);
    add_testcase(testcase352);
    add_testcase(testcase353);
    add_testcase(testcase354);
    add_testcase(testcase355);
    add_testcase(testcase356);
    add_testcase(testcase357);
    add_testcase(testcase358);
    add_testcase(testcase359);
    add_testcase(testcase360);
    add_testcase(testcase361);
    add_testcase(testcase362);
    add_testcase(testcase363);
    add_testcase(testcase364);
    add_testcase(testcase365);
    add_testcase(testcase366);
    add_testcase(testcase367);
    add_testcase(testcase368);
    add_testcase(testcase369);
    add_testcase(testcase370);
    add_testcase(testcase371);
    add_testcase(testcase372);
    add_testcase(testcase373);
    add_testcase(testcase374);
    add_testcase(testcase375);
    add_testcase(testcase376);
    add_testcase(testcase377);
    add_testcase(testcase378);
    add_testcase(testcase379);
    add_testcase(testcase380);
    add_testcase(testcase381);
    add_testcase(testcase382);
    add_testcase(testcase383);
    add_testcase(testcase384);
    add_testcase(testcase385);
    add_testcase(testcase386);
    add_testcase(testcase387);
    add_testcase(testcase388);
    add_testcase(testcase389);
    add_testcase(testcase390);
    add_testcase(testcase391);
    add_testcase(testcase392);
    add_testcase(testcase393);
    add_testcase(testcase394);
    add_testcase(testcase395);
    add_testcase(testcase396);
    add_testcase(testcase397);
    add_testcase(testcase398);
    add_testcase(testcase399);
    add_testcase(testcase400);
    add_testcase(testcase401);
    add_testcase(testcase402);
    add_testcase(testcase403);
    add_testcase(testcase404);
    add_testcase(testcase405);
    add_testcase(testcase406);
    add_testcase(testcase407);
    add_testcase(testcase408);
    add_testcase(testcase409);
    add_testcase(testcase410);
    add_testcase(testcase411);
    add_testcase(testcase412);
    add_testcase(testcase413);
    add_testcase(testcase414);
    add_testcase(testcase415);
    add_testcase(testcase416);
    add_testcase(testcase417);
    add_testcase(testcase418);
    add_testcase(testcase419);
    add_testcase(testcase420);
    add_testcase(testcase421);
    add_testcase(testcase422);
    add_testcase(testcase423);
    add_testcase(testcase424);
    add_testcase(testcase425);
    add_testcase(testcase426);
    add_testcase(testcase427);
    add_testcase(testcase428);
    add_testcase(testcase429);
    add_testcase(testcase430);
    add_testcase(testcase431);
    add_testcase(testcase432);
    add_testcase(testcase433);
    add_testcase(testcase434);
    add_testcase(testcase435);
    add_testcase(testcase436);
    add_testcase(testcase437);
    add_testcase(testcase438);
    add_testcase(testcase439);
    add_testcase(testcase440);
    add_testcase(testcase441);
    add_testcase(testcase442);
    add_testcase(testcase443);
    add_testcase(testcase444);
    add_testcase(testcase445);
    add_testcase(testcase446);
    add_testcase(testcase447);
    add_testcase(testcase448);
    add_testcase(testcase449);
    add_testcase(testcase450);
    add_testcase(testcase451);
    add_testcase(testcase452);
    add_testcase(testcase453);
    add_testcase(testcase454);
    add_testcase(testcase455);
    add_testcase(testcase456);
    add_testcase(testcase457);
    add_testcase(testcase458);
    add_testcase(testcase459);
    add_testcase(testcase460);
    add_testcase(testcase461);
    add_testcase(testcase462);
    add_testcase(testcase463);
    add_testcase(testcase464);
    add_testcase(testcase465);
    add_testcase(testcase466);
    add_testcase(testcase467);
    add_testcase(testcase468);
    add_testcase(testcase469);
    add_testcase(testcase470);
    add_testcase(testcase471);
    add_testcase(testcase472);
    add_testcase(testcase473);
    add_testcase(testcase474);
    add_testcase(testcase475);
    add_testcase(testcase476);
    add_testcase(testcase477);
    add_testcase(testcase478);
    add_testcase(testcase479);
    add_testcase(testcase480);
    add_testcase(testcase481);
    add_testcase(testcase482);
    add_testcase(testcase483);
    add_testcase(testcase484);
    add_testcase(testcase485);
    add_testcase(testcase486);
    add_testcase(testcase487);
    add_testcase(testcase488);
    add_testcase(testcase489);
    add_testcase(testcase490);
    add_testcase(testcase491);
    add_testcase(testcase492);
    add_testcase(testcase493);
    add_testcase(testcase494);
    add_testcase(testcase495);
    add_testcase(testcase496);
    add_testcase(testcase497);
    add_testcase(testcase498);
    add_testcase(testcase499);
    add_testcase(testcase500);
    add_testcase(testcase501);
    add_testcase(testcase502);
    add_testcase(testcase503);
    add_testcase(testcase504);
    add_testcase(testcase505);
    add_testcase(testcase506);
    add_testcase(testcase507);
    add_testcase(testcase508);
    add_testcase(testcase509);
    add_testcase(testcase510);
    add_testcase(testcase511);
    add_testcase(testcase512);
    add_testcase(testcase513);
    add_testcase(testcase514);
    add_testcase(testcase515);
    add_testcase(testcase516);
    add_testcase(testcase517);
    add_testcase(testcase518);
    add_testcase(testcase519);
    add_testcase(testcase520);
    add_testcase(testcase521);
    add_testcase(testcase522);
    add_testcase(testcase523);
    add_testcase(testcase524);
    add_testcase(testcase525);
    add_testcase(testcase526);
    add_testcase(testcase527);
    add_testcase(testcase528);
    add_testcase(testcase529);
    add_testcase(testcase530);
    add_testcase(testcase531);
    add_testcase(testcase532);
    add_testcase(testcase533);
    add_testcase(testcase534);
    add_testcase(testcase535);
    add_testcase(testcase536);
    add_testcase(testcase537);
    add_testcase(testcase538);
    add_testcase(testcase539);
    add_testcase(testcase540);
    add_testcase(testcase541);
    add_testcase(testcase542);
    add_testcase(testcase543);
    add_testcase(testcase544);
    add_testcase(testcase545);
    add_testcase(testcase546);
    add_testcase(testcase547);
    add_testcase(testcase548);
    add_testcase(testcase549);
    add_testcase(testcase550);
    add_testcase(testcase551);
    add_testcase(testcase552);
    add_testcase(testcase553);
    add_testcase(testcase554);
    add_testcase(testcase555);
    add_testcase(testcase556);
    add_testcase(testcase557);
    add_testcase(testcase558);
    add_testcase(testcase559);
    add_testcase(testcase560);
    add_testcase(testcase561);
    add_testcase(testcase562);
    add_testcase(testcase563);
    add_testcase(testcase564);
    add_testcase(testcase565);
    add_testcase(testcase566);
    add_testcase(testcase567);
    add_testcase(testcase568);
    add_testcase(testcase569);
    add_testcase(testcase570);
    add_testcase(testcase571);
    add_testcase(testcase572);
    add_testcase(testcase573);
    add_testcase(testcase574);
    add_testcase(testcase575);
    add_testcase(testcase576);
    add_testcase(testcase577);
    add_testcase(testcase578);
    add_testcase(testcase579);
    add_testcase(testcase580);
    add_testcase(testcase581);
    add_testcase(testcase582);
    add_testcase(testcase583);
    add_testcase(testcase584);
    add_testcase(testcase585);
    add_testcase(testcase586);
    add_testcase(testcase587);
    add_testcase(testcase588);
    add_testcase(testcase589);
    add_testcase(testcase590);
    add_testcase(testcase591);
    add_testcase(testcase592);
    add_testcase(testcase593);
    add_testcase(testcase594);
    add_testcase(testcase595);
    add_testcase(testcase596);
    add_testcase(testcase597);
    add_testcase(testcase598);
    add_testcase(testcase599);
    add_testcase(testcase600);
    add_testcase(testcase601);
    add_testcase(testcase602);
    add_testcase(testcase603);
    add_testcase(testcase604);
    add_testcase(testcase605);
    add_testcase(testcase606);
    add_testcase(testcase607);
    add_testcase(testcase608);
    add_testcase(testcase609);
    add_testcase(testcase610);
    add_testcase(testcase611);
    add_testcase(testcase612);
    add_testcase(testcase613);
    add_testcase(testcase614);
    add_testcase(testcase615);
    add_testcase(testcase616);
    add_testcase(testcase617);
    add_testcase(testcase618);
    add_testcase(testcase619);
    add_testcase(testcase620);
    add_testcase(testcase621);
    add_testcase(testcase622);
    add_testcase(testcase623);
    add_testcase(testcase624);
    add_testcase(testcase625);
    add_testcase(testcase626);
    add_testcase(testcase627);
    add_testcase(testcase628);
    add_testcase(testcase629);
    add_testcase(testcase630);
    add_testcase(testcase631);
    add_testcase(testcase632);
    add_testcase(testcase633);
    add_testcase(testcase634);
    add_testcase(testcase635);
    add_testcase(testcase636);
    add_testcase(testcase637);
    add_testcase(testcase638);
    add_testcase(testcase639);
    add_testcase(testcase640);
    add_testcase(testcase641);
    add_testcase(testcase642);
    add_testcase(testcase643);
    add_testcase(testcase644);
    add_testcase(testcase645);
    add_testcase(testcase646);
    add_testcase(testcase647);
    add_testcase(testcase648);
    add_testcase(testcase649);
    add_testcase(testcase650);
    add_testcase(testcase651);
    add_testcase(testcase652);
    add_testcase(testcase653);
    add_testcase(testcase654);
    add_testcase(testcase655);
    add_testcase(testcase656);
    add_testcase(testcase657);
    add_testcase(testcase658);
    add_testcase(testcase659);
    add_testcase(testcase660);
    add_testcase(testcase661);
    add_testcase(testcase662);
    add_testcase(testcase663);
    add_testcase(testcase664);
    add_testcase(testcase665);
    add_testcase(testcase666);
    add_testcase(testcase667);
    add_testcase(testcase668);
    add_testcase(testcase669);
    add_testcase(testcase670);
    add_testcase(testcase671);
    add_testcase(testcase672);
    add_testcase(testcase673);
    add_testcase(testcase674);
    add_testcase(testcase675);
    add_testcase(testcase676);
    add_testcase(testcase677);
    add_testcase(testcase678);
    add_testcase(testcase679);
    add_testcase(testcase680);
    add_testcase(testcase681);
    add_testcase(testcase682);
    add_testcase(testcase683);
    add_testcase(testcase684);
    add_testcase(testcase685);
    add_testcase(testcase686);
    add_testcase(testcase687);
    add_testcase(testcase688);
    add_testcase(testcase689);
    add_testcase(testcase690);
    add_testcase(testcase691);
    add_testcase(testcase692);
    add_testcase(testcase693);
    add_testcase(testcase694);
    add_testcase(testcase695);
    add_testcase(testcase696);
    add_testcase(testcase697);
    add_testcase(testcase698);
    add_testcase(testcase699);
    add_testcase(testcase700);
    add_testcase(testcase701);
    add_testcase(testcase702);
    add_testcase(testcase703);
    add_testcase(testcase704);
    add_testcase(testcase705);
    add_testcase(testcase706);
    add_testcase(testcase707);
    add_testcase(testcase708);
    add_testcase(testcase709);
    add_testcase(testcase710);
    add_testcase(testcase711);
    add_testcase(testcase712);
    add_testcase(testcase713);
    add_testcase(testcase714);
    add_testcase(testcase715);
    add_testcase(testcase716);
    add_testcase(testcase717);
    add_testcase(testcase718);
    add_testcase(testcase719);
    add_testcase(testcase720);
    add_testcase(testcase721);
    add_testcase(testcase722);
    add_testcase(testcase723);
    add_testcase(testcase724);
    add_testcase(testcase725);
    add_testcase(testcase726);
    add_testcase(testcase727);
    add_testcase(testcase728);
    add_testcase(testcase729);
    add_testcase(testcase730);
    add_testcase(testcase731);
    add_testcase(testcase732);
    add_testcase(testcase733);
    add_testcase(testcase734);
    add_testcase(testcase735);
    add_testcase(testcase736);
    add_testcase(testcase737);
    add_testcase(testcase738);
    add_testcase(testcase739);
    add_testcase(testcase740);
    add_testcase(testcase741);
    add_testcase(testcase742);
    add_testcase(testcase743);
    add_testcase(testcase744);
    add_testcase(testcase745);
    add_testcase(testcase746);
    add_testcase(testcase747);
    add_testcase(testcase748);
    add_testcase(testcase749);
    add_testcase(testcase750);
    add_testcase(testcase751);
    add_testcase(testcase752);
    add_testcase(testcase753);
    add_testcase(testcase754);
    add_testcase(testcase755);
    add_testcase(testcase756);
    add_testcase(testcase757);
    add_testcase(testcase758);
    add_testcase(testcase759);
    add_testcase(testcase760);
    add_testcase(testcase761);
    add_testcase(testcase762);
    add_testcase(testcase763);
    add_testcase(testcase764);
    add_testcase(testcase765);
    add_testcase(testcase766);
    add_testcase(testcase767);
    add_testcase(testcase768);
    add_testcase(testcase769);
    add_testcase(testcase770);
    add_testcase(testcase771);
    add_testcase(testcase772);
    add_testcase(testcase773);
    add_testcase(testcase774);
    add_testcase(testcase775);
    add_testcase(testcase776);
    add_testcase(testcase777);
    add_testcase(testcase778);
    add_testcase(testcase779);
    add_testcase(testcase780);
    add_testcase(testcase781);
    add_testcase(testcase782);
    add_testcase(testcase783);
    add_testcase(testcase784);
    add_testcase(testcase785);
    add_testcase(testcase786);
    add_testcase(testcase787);
    add_testcase(testcase788);
    add_testcase(testcase789);
    add_testcase(testcase790);
    add_testcase(testcase791);
    add_testcase(testcase792);
    add_testcase(testcase793);
    add_testcase(testcase794);
    add_testcase(testcase795);
    add_testcase(testcase796);
    add_testcase(testcase797);
    add_testcase(testcase798);
    add_testcase(testcase799);
    add_testcase(testcase800);
    add_testcase(testcase801);
    add_testcase(testcase802);
    add_testcase(testcase803);
    add_testcase(testcase804);
    add_testcase(testcase805);
    add_testcase(testcase806);
    add_testcase(testcase807);
    add_testcase(testcase808);
    add_testcase(testcase809);
    add_testcase(testcase810);
    add_testcase(testcase811);
    add_testcase(testcase812);
    add_testcase(testcase813);
    add_testcase(testcase814);
    add_testcase(testcase815);
    add_testcase(testcase816);
    add_testcase(testcase817);
    add_testcase(testcase818);
    add_testcase(testcase819);
    add_testcase(testcase820);
    add_testcase(testcase821);
    add_testcase(testcase822);
    add_testcase(testcase823);
    add_testcase(testcase824);
    add_testcase(testcase825);
    add_testcase(testcase826);
    add_testcase(testcase827);
    add_testcase(testcase828);
    add_testcase(testcase829);
    add_testcase(testcase830);
    add_testcase(testcase831);
    add_testcase(testcase832);
    add_testcase(testcase833);
    add_testcase(testcase834);
    add_testcase(testcase835);
    add_testcase(testcase836);
    add_testcase(testcase837);
    add_testcase(testcase838);
    add_testcase(testcase839);
    add_testcase(testcase840);
    add_testcase(testcase841);
    add_testcase(testcase842);
    add_testcase(testcase843);
    add_testcase(testcase844);
    add_testcase(testcase845);
    add_testcase(testcase846);
    add_testcase(testcase847);
    add_testcase(testcase848);
    add_testcase(testcase849);
    add_testcase(testcase850);
    add_testcase(testcase851);
    add_testcase(testcase852);
    add_testcase(testcase853);
    add_testcase(testcase854);
    add_testcase(testcase855);
    add_testcase(testcase856);
    add_testcase(testcase857);
    add_testcase(testcase858);
    add_testcase(testcase859);
    add_testcase(testcase860);
    add_testcase(testcase861);
    add_testcase(testcase862);
    add_testcase(testcase863);
    add_testcase(testcase864);
    add_testcase(testcase865);
    add_testcase(testcase866);
    add_testcase(testcase867);
    add_testcase(testcase868);
    add_testcase(testcase869);
    add_testcase(testcase870);
    add_testcase(testcase871);
    add_testcase(testcase872);
    add_testcase(testcase873);
    add_testcase(testcase874);
    add_testcase(testcase875);
    add_testcase(testcase876);
    add_testcase(testcase877);
    add_testcase(testcase878);
    add_testcase(testcase879);
    add_testcase(testcase880);
    add_testcase(testcase881);
    add_testcase(testcase882);
    add_testcase(testcase883);
    add_testcase(testcase884);
    add_testcase(testcase885);
    add_testcase(testcase886);
    add_testcase(testcase887);
    add_testcase(testcase888);
    add_testcase(testcase889);
    add_testcase(testcase890);
    add_testcase(testcase891);
    add_testcase(testcase892);
    add_testcase(testcase893);
    add_testcase(testcase894);
    add_testcase(testcase895);
    add_testcase(testcase896);
    add_testcase(testcase897);
    add_testcase(testcase898);
    add_testcase(testcase899);
    add_testcase(testcase900);
    add_testcase(testcase901);
    add_testcase(testcase902);
    add_testcase(testcase903);
    add_testcase(testcase904);
    add_testcase(testcase905);
    add_testcase(testcase906);
    add_testcase(testcase907);
    add_testcase(testcase908);
    add_testcase(testcase909);
    add_testcase(testcase910);
    add_testcase(testcase911);
    add_testcase(testcase912);
    add_testcase(testcase913);
    add_testcase(testcase914);
    add_testcase(testcase915);
    add_testcase(testcase916);
    add_testcase(testcase917);
    add_testcase(testcase918);
    add_testcase(testcase919);
    add_testcase(testcase920);
    add_testcase(testcase921);
    add_testcase(testcase922);
    add_testcase(testcase923);
    add_testcase(testcase924);
    add_testcase(testcase925);
    add_testcase(testcase926);
    add_testcase(testcase927);
    add_testcase(testcase928);
    add_testcase(testcase929);
    add_testcase(testcase930);
    add_testcase(testcase931);
    add_testcase(testcase932);
    add_testcase(testcase933);
    add_testcase(testcase934);
    add_testcase(testcase935);
    add_testcase(testcase936);
    add_testcase(testcase937);
    add_testcase(testcase938);
    add_testcase(testcase939);
    add_testcase(testcase940);
}

