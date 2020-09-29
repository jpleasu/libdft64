#include "testcase.h"
static int testcase0() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase1() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase2() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase3() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase4() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase5() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase6() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase7() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase8() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase9() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase10() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase11() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase12() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase13() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase14() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase15() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase16() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase17() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     adc    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"adc    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase18() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase19() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase20() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase21() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase22() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase23() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase24() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase25() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase26() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase27() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase28() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase29() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase30() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase31() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase32() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase33() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase34() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase35() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     add    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"add    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase36() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase37() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase38() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase39() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase40() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase41() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase42() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase43() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase44() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase45() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase46() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase47() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase48() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase49() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase50() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase51() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase52() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase53() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase54() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     and    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"and    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase55() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase56() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase57() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase58() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   eax,ecx,edx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   eax,ecx,edx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase59() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase60() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase61() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase62() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     andn   rax,rcx,rdx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"andn   rax,rcx,rdx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase63() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase64() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase65() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase66() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  eax,ecx,edx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  eax,ecx,edx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 17 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase67() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase68() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase69() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase70() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bextr  rax,rcx,rdx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bextr  rax,rcx,rdx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 17 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase71() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsi   eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsi   eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase72() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsi   eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsi   eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase73() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsi   rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsi   rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase74() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsi   rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsi   rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase75() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsmsk eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsmsk eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase76() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsmsk eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsmsk eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase77() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsmsk rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsmsk rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase78() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsmsk rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsmsk rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase79() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsr   eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsr   eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase80() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsr   eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsr   eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase81() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsr   rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsr   rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase82() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     blsr   rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"blsr   rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase83() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bswap  eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bswap  eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase84() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bswap  rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bswap  rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase85() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase86() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase87() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase88() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase89() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase90() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase91() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase92() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase93() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase94() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase95() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase96() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bt     rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bt     rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase97() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase98() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase99() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase100() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase101() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase102() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase103() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase104() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase105() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase106() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase107() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase108() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btc    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btc    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase109() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase110() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase111() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase112() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase113() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase114() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase115() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase116() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase117() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase118() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase119() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase120() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     btr    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"btr    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase121() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase122() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase123() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase124() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase125() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase126() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase127() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase128() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase129() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase130() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase131() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase132() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bts    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bts    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase133() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase134() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase135() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase136() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   eax,ecx,edx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   eax,ecx,edx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase137() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase138() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase139() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase140() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     bzhi   rax,rcx,rdx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"bzhi   rax,rcx,rdx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase141() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase142() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase143() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase144() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase145() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase146() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase147() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase148() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase149() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase150() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase151() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase152() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase153() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase154() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase155() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase156() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase157() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase158() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmp    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmp    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase159() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase160() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase161() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase162() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase163() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg cl,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg cl,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase164() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg cx,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg cx,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase165() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase166() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase167() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg ecx,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg ecx,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase168() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase169() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase170() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     cmpxchg rcx,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"cmpxchg rcx,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase171() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     dec    al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"dec    al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase172() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     dec    ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"dec    ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase173() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     dec    eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"dec    eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase174() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     dec    rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"dec    rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase175() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase176() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase177() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase178() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 16 17 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 8 9 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase179() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase180() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 8 9 10 11 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase181() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase182() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     div    rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"div    rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase183() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     fnstsw ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"fnstsw ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase184() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     fstsw  ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"fstsw  ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase185() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase186() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase187() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase188() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 16 17 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 8 9 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase189() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase190() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 8 9 10 11 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase191() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase192() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     idiv   rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"idiv   rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase193() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase194() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase195() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase196() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax,ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax,ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase197() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax,ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax,ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase198() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase199() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax,cx,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax,cx,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase200() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ax,cx,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ax,cx,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase201() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase202() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 8 9 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase203() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase204() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx,ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx,ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase205() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx,ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx,ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase206() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase207() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx,cx,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx,cx,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase208() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   cx,cx,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   cx,cx,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase209() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase210() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase211() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax,eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax,eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase212() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax,eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax,eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase213() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase214() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax,ecx,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax,ecx,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase215() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   eax,ecx,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   eax,ecx,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase216() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 8 9 10 11 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase217() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 8 9 10 11 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase218() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx,eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx,eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase219() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx,eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx,eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase220() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase221() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx,ecx,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx,ecx,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase222() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   ecx,ecx,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   ecx,ecx,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase223() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase224() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase225() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax,rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax,rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase226() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax,rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax,rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase227() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase228() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax,rcx,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax,rcx,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase229() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rax,rcx,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rax,rcx,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase230() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase231() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase232() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx,rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx,rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase233() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx,rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx,rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase234() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase235() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx,rcx,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx,rcx,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase236() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     imul   rcx,rcx,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"imul   rcx,rcx,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase237() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     inc    al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"inc    al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase238() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     inc    ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"inc    ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase239() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     inc    eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"inc    eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase240() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     inc    rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"inc    rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase241() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     lar    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"lar    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase242() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     lar    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"lar    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase243() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     lar    eax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"lar    eax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase244() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     lar    eax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"lar    eax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 9 10 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase245() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase246() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase247() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase248() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase249() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase250() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase251() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase252() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase253() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase254() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase255() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase256() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase257() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase258() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase259() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase260() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase261() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mov    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mov    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase262() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movabs rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movabs rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase263() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movabs rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movabs rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase264() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movabs rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movabs rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase265() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movd   eax,mm0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movd   eax,mm0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase266() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movd   eax,mm4\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movd   eax,mm4;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase267() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movd   mm0,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movd   mm0,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase268() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movd   mm2,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movd   mm2,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase269() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movq   mm0,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movq   mm0,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase270() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movq   mm4,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movq   mm4,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase271() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movq   rax,mm0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movq   rax,mm0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase272() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movq   rax,mm5\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movq   rax,mm5;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase273() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movsx  ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movsx  ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase274() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     movzx  ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"movzx  ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase275() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase276() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase277() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase278() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 8 9 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase279() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase280() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 8 9 10 11 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase281() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase282() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mul    rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mul    rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase283() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase284() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase285() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   eax,ecx,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   eax,ecx,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 12 13 14 15 16 17 18 19 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase286() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase287() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   ecx,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   ecx,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 12 13 14 15 16 17 18 19 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase288() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   ecx,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   ecx,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 17 18 19 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase289() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   ecx,ecx,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   ecx,ecx,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 12 13 14 15 16 17 18 19 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase290() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   ecx,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   ecx,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase291() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase292() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase293() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rax,rcx,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rax,rcx,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase294() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase295() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rcx,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rcx,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase296() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rcx,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rcx,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase297() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rcx,rcx,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rcx,rcx,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 16 17 18 19 20 21 22 23 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase298() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     mulx   rcx,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"mulx   rcx,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase299() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     neg    al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"neg    al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase300() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     neg    ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"neg    ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase301() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     neg    eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"neg    eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase302() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     neg    rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"neg    rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase303() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     not    al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"not    al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase304() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     not    ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"not    ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase305() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     not    eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"not    eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase306() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     not    rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"not    rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase307() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase308() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase309() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase310() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase311() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase312() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase313() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase314() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase315() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase316() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase317() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase318() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase319() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase320() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase321() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase322() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase323() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase324() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase325() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     or     rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"or     rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase326() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase327() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase328() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase329() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase330() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase331() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase332() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase333() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase334() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase335() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase336() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase337() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase338() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase339() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase340() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase341() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase342() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase343() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcl    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcl    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase344() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase345() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase346() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase347() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase348() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase349() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase350() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase351() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase352() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase353() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase354() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase355() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase356() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase357() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase358() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase359() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase360() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase361() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rcr    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rcr    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase362() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W adc al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W adc al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase363() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W adc al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W adc al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase364() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W adc al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W adc al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase365() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W adc al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W adc al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase366() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W add al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W add al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase367() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W add al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W add al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase368() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W add al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W add al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase369() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W add al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W add al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase370() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W and al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W and al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase371() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W and al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W and al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase372() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W and al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W and al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase373() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W and al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W and al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase374() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W cmp al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W cmp al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase375() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W cmp al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W cmp al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase376() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W cmp al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W cmp al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase377() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W cmp al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W cmp al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase378() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W cmpxchg al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W cmpxchg al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase379() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W cmpxchg al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W cmpxchg al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase380() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W dec al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W dec al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase381() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W div al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W div al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase382() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W idiv al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W idiv al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase383() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W imul al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W imul al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase384() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W inc al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W inc al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase385() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W mov al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W mov al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase386() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W mov al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W mov al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase387() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W mov al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W mov al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase388() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W mov al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W mov al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase389() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W mul al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W mul al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase390() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W neg al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W neg al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase391() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W not al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W not al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase392() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W or al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W or al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase393() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W or al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W or al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase394() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W or al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W or al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase395() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W or al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W or al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase396() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcl al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcl al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase397() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcl al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcl al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase398() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcl al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcl al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase399() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcl al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcl al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase400() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcl al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcl al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase401() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcr al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcr al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase402() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcr al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcr al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase403() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcr al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcr al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase404() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcr al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcr al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase405() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rcr al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rcr al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase406() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rol al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rol al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase407() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rol al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rol al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase408() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rol al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rol al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase409() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rol al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rol al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase410() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W rol al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W rol al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase411() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W ror al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W ror al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase412() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W ror al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W ror al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase413() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W ror al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W ror al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase414() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W ror al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W ror al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase415() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W ror al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W ror al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase416() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sar al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sar al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase417() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sar al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sar al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase418() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sar al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sar al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase419() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sar al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sar al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase420() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sar al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sar al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase421() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sbb al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sbb al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase422() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sbb al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sbb al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase423() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sbb al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sbb al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase424() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sbb al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sbb al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase425() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W seta al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W seta al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase426() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setae al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setae al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase427() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setb al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setb al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase428() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setbe al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setbe al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase429() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sete al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sete al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase430() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setg al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setg al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase431() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setge al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setge al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase432() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setl al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setl al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase433() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setle al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setle al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase434() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setne al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setne al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase435() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setno al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setno al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase436() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setnp al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setnp al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase437() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setns al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setns al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase438() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W seto al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W seto al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase439() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W setp al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W setp al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase440() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sets al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sets al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase441() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shl al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shl al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase442() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shl al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shl al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase443() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shl al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shl al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase444() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shl al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shl al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase445() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shl al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shl al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase446() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shr al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shr al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase447() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shr al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shr al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase448() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shr al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shr al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase449() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shr al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shr al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase450() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W shr al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W shr al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase451() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sub al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sub al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase452() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sub al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sub al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase453() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sub al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sub al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase454() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W sub al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W sub al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase455() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W test al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W test al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase456() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W test al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W test al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase457() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W test al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W test al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase458() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W test al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W test al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase459() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xadd al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xadd al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase460() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xadd al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xadd al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase461() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xchg al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xchg al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase462() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xchg al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xchg al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase463() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xor al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xor al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase464() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xor al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xor al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase465() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xor al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xor al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase466() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rex.W xor al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rex.W xor al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase467() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase468() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase469() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase470() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase471() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase472() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase473() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase474() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase475() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase476() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase477() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase478() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase479() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase480() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase481() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase482() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase483() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase484() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rol    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rol    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase485() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase486() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase487() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase488() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase489() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase490() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase491() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase492() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase493() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase494() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase495() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase496() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase497() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase498() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase499() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase500() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase501() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase502() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     ror    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"ror    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase503() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   eax,eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   eax,eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase504() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   eax,eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   eax,eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase505() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   eax,ecx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   eax,ecx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase506() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   eax,ecx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   eax,ecx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase507() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   rax,rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   rax,rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase508() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   rax,rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   rax,rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase509() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   rax,rcx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   rax,rcx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase510() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     rorx   rax,rcx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"rorx   rax,rcx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase511() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase512() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase513() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase514() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase515() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase516() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase517() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase518() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase519() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase520() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase521() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase522() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase523() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase524() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase525() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase526() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase527() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase528() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sar    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sar    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase529() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase530() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase531() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase532() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   eax,ecx,edx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   eax,ecx,edx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase533() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase534() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase535() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase536() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sarx   rax,rcx,rdx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sarx   rax,rcx,rdx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase537() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase538() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase539() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase540() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase541() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase542() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase543() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase544() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase545() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase546() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase547() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase548() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase549() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase550() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase551() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase552() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase553() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase554() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase555() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sbb    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sbb    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase556() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     seta   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"seta   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase557() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setae  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setae  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase558() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setb   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setb   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase559() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setbe  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setbe  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase560() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sete   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sete   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase561() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setg   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setg   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase562() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setge  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setge  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase563() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setl   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setl   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase564() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setle  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setle  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase565() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setne  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setne  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase566() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setno  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setno  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase567() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setnp  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setnp  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase568() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setns  al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setns  al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase569() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     seto   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"seto   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase570() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     setp   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"setp   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase571() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sets   al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sets   al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase572() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase573() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase574() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase575() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase576() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase577() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase578() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase579() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase580() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase581() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase582() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase583() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase584() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase585() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase586() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase587() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase588() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase589() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shl    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shl    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase590() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   ax,ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   ax,ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase591() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   ax,ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   ax,ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase592() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   ax,ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   ax,ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase593() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   ax,cx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   ax,cx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase594() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   ax,cx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   ax,cx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase595() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   eax,eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   eax,eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase596() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   eax,eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   eax,eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase597() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   eax,ecx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   eax,ecx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase598() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   eax,ecx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   eax,ecx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase599() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   rax,rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   rax,rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase600() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   rax,rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   rax,rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase601() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   rax,rcx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   rax,rcx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase602() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shld   rax,rcx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shld   rax,rcx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase603() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase604() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase605() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase606() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   eax,ecx,edx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   eax,ecx,edx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase607() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase608() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase609() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase610() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shlx   rax,rcx,rdx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shlx   rax,rcx,rdx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase611() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase612() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    al,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    al,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase613() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase614() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    al,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    al,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase615() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase616() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase617() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase618() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase619() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    ax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    ax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase620() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase621() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase622() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase623() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase624() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    eax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    eax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase625() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase626() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase627() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase628() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shr    rax,1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shr    rax,1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase629() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   ax,ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   ax,ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase630() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   ax,ax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   ax,ax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase631() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   ax,ax,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   ax,ax,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase632() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   ax,cx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   ax,cx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase633() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   ax,cx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   ax,cx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase634() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   eax,eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   eax,eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase635() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   eax,eax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   eax,eax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase636() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   eax,ecx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   eax,ecx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase637() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   eax,ecx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   eax,ecx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase638() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   rax,rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   rax,rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase639() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   rax,rax,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   rax,rax,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase640() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   rax,rcx,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   rax,rcx,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase641() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrd   rax,rcx,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrd   rax,rcx,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase642() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   eax,eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   eax,eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase643() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   eax,eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   eax,eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase644() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   eax,ecx,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   eax,ecx,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase645() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   eax,ecx,edx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   eax,ecx,edx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 8 9 10 11 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase646() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   rax,rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   rax,rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase647() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   rax,rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   rax,rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase648() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   rax,rcx,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   rax,rcx,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase649() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     shrx   rax,rcx,rdx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"shrx   rax,rcx,rdx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 16 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase650() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     smsw   ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"smsw   ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase651() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     smsw   eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"smsw   eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase652() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     smsw   rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"smsw   rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase653() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase654() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase655() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase656() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase657() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase658() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase659() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase660() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase661() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase662() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase663() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase664() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase665() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase666() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase667() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase668() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase669() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase670() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     sub    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"sub    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase671() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase672() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase673() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase674() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase675() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase676() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase677() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase678() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase679() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase680() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase681() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase682() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase683() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase684() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase685() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase686() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     test   rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"test   rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase687() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     verr   ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"verr   ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase688() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     verw   ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"verw   ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase689() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase690() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase691() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase692() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase693() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase694() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase695() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase696() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xadd   rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xadd   rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase697() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase698() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase699() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase700() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase701() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   cx,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   cx,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase702() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase703() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase704() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   ecx,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   ecx,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase705() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase706() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase707() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xchg   rcx,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xchg   rcx,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 0 1 2 3 4 5 6 7 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase708() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    al,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    al,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase709() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    al,0xff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    al,0xff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase710() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    al,al\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    al,al;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase711() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    al,cl\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    al,cl;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase712() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    ax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    ax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase713() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    ax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    ax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase714() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    ax,0xffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    ax,0xffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase715() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    ax,ax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    ax,ax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase716() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    ax,cx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    ax,cx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase717() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    eax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    eax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase718() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    eax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    eax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase719() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    eax,0xffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    eax,0xffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase720() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    eax,eax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    eax,eax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase721() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    eax,ecx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    eax,ecx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 8 9 10 11 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase722() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    rax,0x0\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    rax,0x0;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase723() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    rax,0x1\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    rax,0x1;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase724() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    rax,0xffffffffffffffff\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    rax,0xffffffffffffffff;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase725() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    rax,rax\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    rax,rax;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
}
static int testcase726() {
	volatile uint64_t rax_in, rcx_in, rdx_in;
	volatile uint64_t rax_out, rcx_out, rdx_out;

	rax_in = 0x1;
	rcx_in = 0x1;
	rdx_in = 0x0;

	rax_out = 0x0;
	rcx_out = 0x0;
	rdx_out = 0x0;

	printf("%s:     xor    rax,rcx\n", __func__ );
	fflush(stdout);
	__gtaint_reset();
	__gtaint_setn(&rax_in, sizeof(rax_in));
	__gtaint_setn(&rcx_in, sizeof(rcx_in));
	__gtaint_setn(&rdx_in, sizeof(rdx_in));
	asm volatile (
			"xor    rax,rcx;\n"
			:"=a"(rax_out), "=c"(rcx_out), "=d"(rdx_out)
			:"a"(rax_in), "c"(rcx_in), "d"(rdx_in)
	);
	int passed0, passed1, passed2;
	__gtaint_assert(&rax_out, sizeof(rax_out), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 }", &passed0);
	__gtaint_assert(&rcx_out, sizeof(rcx_out), "{ 8 9 10 11 12 13 14 15 }", &passed1);
	__gtaint_assert(&rdx_out, sizeof(rdx_out), "{ 16 17 18 19 20 21 22 23 }", &passed2);
	return passed0 && passed1 && passed2;
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
}
