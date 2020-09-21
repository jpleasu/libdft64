#include<cstdio>
#include<cstdint>

[[gnu::noinline]]
int get(char *p, size_t off) {
	return p[off];
}

extern "C" {
void* __attribute__((optimize("O0"))) __gtaint_reset() {
	return nullptr; // clear rax
}

void __attribute__((optimize("O0"))) __gtaint_setb(void *addr) {
}
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

	return 0;
}
