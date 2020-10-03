#ifndef INLINED_TEST_H
#define INLINED_TEST_H
#include <cstdint>
#include <cstdio>
#include <vector>

extern "C" {
void *__gtaint_reset();
void __gtaint_setb(volatile void *addr);
void __gtaint_setn(volatile void *addr, unsigned int n);

const char *__gtaint_getb_str(volatile void *addr);
void __gtaint_assert(volatile void *addr, unsigned int n, const char *assertion, int *result);
int __gtaint_equals(void *addr, size_t memsz, uint32_t *ordered_list, size_t n);
}

bool __gtaint_equals(void *addr, size_t memsz, std::vector<uint32_t> list);
bool __gtaint_equals(void *addr, std::vector<uint32_t> list);

void add_testcase(int (*)());

#define STRINGIFY(x) #x

#define ASSERT_TAGGED(p, ...)                                                                                          \
    if (!__gtaint_equals((p), __VA_ARGS__)) {                                                                          \
        printf("%s:%d %s assertion failed \"%s\", actual is %s\n", __FILE__, __LINE__, __func__,                       \
               STRINGIFY((p tagged __VA_ARGS__)), __gtaint_getb_str(p));                                               \
        fflush(stdout);                                                                                                \
        passed = 0;                                                                                                    \
    }

/*
int example_test() {
    int passed = 1;
    ASSERT("this simplifies my life" && 1);
    ASSERT("this is the only way to do it" && 0);
    return passed;
}

 */

#endif // INLINED_TEST_H
