#include <cassert>
#include <cstdint>
#include <cstdio>
#include <vector>

[[gnu::noinline]] int get(char *p, size_t off) {
    return p[off];
}

extern "C" {
// reset tagmap
void *__attribute__((optimize("O0"))) __gtaint_reset() {
    return nullptr; // clear rax
}

// set a new tag at the given address
void __attribute__((optimize("O0"))) __gtaint_setb(void *addr) {
}

// set n new tags starting at the given address
void __attribute__((optimize("O0"))) __gtaint_setn(void *addr, unsigned int n) {
}

// return 1 if the sets of tags on [addr, addr+memsz) equals the tages in the ordered list of length n
int __attribute__((optimize("O0"))) __gtaint_equals(void *addr, size_t memsz, uint32_t *ordered_list, size_t n) {
    return 0;
}
}

bool __gtaint_equals(void *addr, size_t memsz, std::vector<uint32_t> l) {
    return __gtaint_equals(addr, memsz, l.data(), l.size());
}

template <typename T>
[[gnu::noinline]] T ret(T a) {
    return a;
}

int main(int argc, char **argv) {
    char buff[1024] = { 0 };
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (sz > sizeof(buff))
        sz = sizeof(buff);

    fread(buff, 1, sz, fp);

    int z = get(buff, 14);
    if (z > 30)
        printf(">\n");
    else
        printf("<\n");

    if (get(buff, 7) + get(buff, 8) != 0) {
        printf("xxx\n");
    }

    __gtaint_reset();
    __gtaint_setb(buff + 7);
    __gtaint_setb(buff + 8);
    if (get(buff, 7) + get(buff, 8) != 0) {
        printf("xxx\n");
    }
    assert(__gtaint_equals(buff + 7, 1, { 0 }));
    assert(!__gtaint_equals(buff + 7, 1, { 1 }));

    __gtaint_reset();
    __gtaint_setn(buff + 9, 2);
    if (get(buff, 9) + get(buff, 10) != 0) {
        printf("xxx\n");
    }

    return 0;
}
