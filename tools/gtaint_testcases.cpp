#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <vector>

#include "gtaint_testcases/testcase.h"

static std::vector<int (*)()> testcases;
void add_testcase(int (*testcase)()) {
    testcases.push_back(testcase);
}

extern "C" {
void *__attribute__((optimize("O0"))) __gtaint_reset() {
    return nullptr; // clear rax
}

void __attribute__((optimize("O0"))) __gtaint_setb(volatile void *addr) {
}

void __attribute__((optimize("O0"))) __gtaint_setn(volatile void *addr, unsigned int n) {
}

const char *__gtaint_getb_str(volatile void *addr) {
    return nullptr;
}

void __attribute__((optimize("O0")))
__gtaint_assert(volatile void *addr, unsigned int n, const char *assertion, int *result) {
}

int __attribute__((optimize("O0"))) __gtaint_equals(void *addr, size_t memsz, uint32_t *ordered_list, size_t n) {
    return 0;
}
}
bool __gtaint_equals(void *addr, size_t memsz, std::vector<uint32_t> l) {
    bool result;
    std::sort(l.begin(), l.end());
    result = __gtaint_equals(addr, memsz, l.data(), l.size());
    return result;
}

bool __gtaint_equals(void *addr, std::vector<uint32_t> l) {
    return __gtaint_equals(addr, 1, l);
}

int main(int argc, char **argv) {
    volatile int passed;

    for (int (*testcase)() : testcases) {
        passed += testcase();
    }

    printf("%d/%d testcases passed\n", passed, testcases.size());

    return 0;
}
