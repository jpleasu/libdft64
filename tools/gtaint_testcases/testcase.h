#ifndef INLINED_TEST_H
#define INLINED_TEST_H
#include <cstdint>
#include <cstdio>

void add_testcase(int (*)());

extern "C" {
void *__gtaint_reset();
void __gtaint_setb(volatile void *addr);
void __gtaint_setn(volatile void *addr, unsigned int n);
void __gtaint_assert(volatile void *addr, unsigned int n, const char *assertion, int *result);
}
#endif // INLINED_TEST_H
