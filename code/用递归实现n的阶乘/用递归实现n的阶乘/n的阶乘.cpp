#include<iostream>
using namespace std;

int mul(int num)
{
	if (num > 1)
		return num*mul(num - 1);
	else
		return 1;
}

int main()
{
	int ret=mul(6);
	cout << ret;
}