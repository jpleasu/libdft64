#include "testcase.h"

static int testbzhi1() {
    int passed = 1;

    printf("%s     bzhi   eax,eax,eax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    asm volatile (
        "mov EAX,%1;\n"
        "bzhi   eax,eax,eax;\n" // <--
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

static int testbzhi2() {
    int passed = 1;

    printf("%s     bzhi   eax,eax,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inEAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inEAX, 4);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov EAX,%1;\n"
        "mov CL,%2;\n"
        "bzhi   eax,eax,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inEAX),"m"(inCL)
        :"rax","cl"
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

static int testbzhi3() {
    int passed = 1;

    printf("%s     bzhi   eax,ecx,ecx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    asm volatile (
        "mov ECX,%1;\n"
        "bzhi   eax,ecx,ecx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX)
        :"rax","ecx"
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

static int testbzhi4() {
    int passed = 1;

    printf("%s     bzhi   eax,ecx,edx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint32_t inECX = 1;
    uint8_t inDL = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inECX, 4);
    __gtaint_setn(&inDL, 1);
    asm volatile (
        "mov ECX,%1;\n"
        "mov DL,%2;\n"
        "bzhi   eax,ecx,edx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inECX),"m"(inDL)
        :"rax","ecx","dl"
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

static int testbzhi5() {
    int passed = 1;

    printf("%s     bzhi   rax,rax,rax\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    asm volatile (
        "mov RAX,%1;\n"
        "bzhi   rax,rax,rax;\n" // <--
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

static int testbzhi6() {
    int passed = 1;

    printf("%s     bzhi   rax,rax,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRAX = 1;
    uint8_t inCL = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRAX, 8);
    __gtaint_setn(&inCL, 1);
    asm volatile (
        "mov RAX,%1;\n"
        "mov CL,%2;\n"
        "bzhi   rax,rax,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRAX),"m"(inCL)
        :"rax","cl"
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

static int testbzhi7() {
    int passed = 1;

    printf("%s     bzhi   rax,rcx,rcx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    asm volatile (
        "mov RCX,%1;\n"
        "bzhi   rax,rcx,rcx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX)
        :"rax","rcx"
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

static int testbzhi8() {
    int passed = 1;

    printf("%s     bzhi   rax,rcx,rdx\n", __func__);fflush(stdout);

    __gtaint_reset();
    uint64_t inRCX = 1;
    uint8_t inDL = 0;
    uint64_t outRAX = 1;
    __gtaint_setn(&inRCX, 8);
    __gtaint_setn(&inDL, 1);
    asm volatile (
        "mov RCX,%1;\n"
        "mov DL,%2;\n"
        "bzhi   rax,rcx,rdx;\n" // <--
        "mov %0,RAX;\n"
        :"=m"(outRAX)
        :"m"(inRCX),"m"(inDL)
        :"rax","rcx","dl"
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

static void __attribute__((noinline, constructor)) init() {
    add_testcase(testbzhi1);
    add_testcase(testbzhi2);
    add_testcase(testbzhi3);
    add_testcase(testbzhi4);
    add_testcase(testbzhi5);
    add_testcase(testbzhi6);
    add_testcase(testbzhi7);
    add_testcase(testbzhi8);
}

