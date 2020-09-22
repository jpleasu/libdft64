#include <cstdint>
#include <cstdio>
#include <vector>

static std::vector<int (*)()> testcases;
void add_testcase(int (*testcase)()) {
	testcases.push_back(testcase);
}

extern "C" {
// reset tagmap
void* __attribute__((optimize("O0"))) __gtaint_reset() {
	return nullptr; // clear rax
}

// set a new tag at the given address
void __attribute__((optimize("O0"))) __gtaint_setb(volatile void *addr) {
}

// set n new tags starting at the given address
void __attribute__((optimize("O0"))) __gtaint_setn(volatile void *addr,
		unsigned int n) {
}

// assert that taint at p is equal to assertion
void __attribute__((optimize("O0"))) __gtaint_assert(volatile void *addr,
		unsigned int n, const char *assertion, int *result) {
}

}

int main(int argc, char **argv) {
	volatile int passed;

	for (int (*testcase)() : testcases) {
		passed += testcase();
	}

	printf("%d/%d testcases passed\n", passed, testcases.size());

	return 0;
}
