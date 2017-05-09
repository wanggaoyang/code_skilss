#include<iostream>
using namespace std;

struct test {
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 4;

}*pbit;

int main()
{
	test test;
	test.a = 1;
	test.b = 7;
	test.c = 15;
	printf("%d,%d,%d\n", test.a, test.b, test.c);

	pbit = &test;
	pbit->a = 0;
	pbit->b &= 4;
	pbit->c |= 1;
	printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);
}