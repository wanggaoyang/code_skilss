#include <iostream>
#define BIT3 (0x1<<3)
#define BIT7 (0x1<<7)
using namespace std;
static int a=1;

void set_bit3(void)
{
	a |= BIT3;
	cout << a << endl;
}

void clear_bit3(void)
{
	a &= ~BIT3;
	cout << a << endl;
}

int calculate(unsigned char c)
{
	int count = 0;
	int i = 0;
	unsigned char comp = BIT7;
	cout << sizeof(c) * 8 << endl;
	for (i = 0; i < sizeof(c) * 8; i++)
	{
		if ((c&comp) != 0)
		{
			count++;
		}
		comp = comp >> 1;
	}
	return count;
}

int main()
{
	set_bit3();
	clear_bit3();
	unsigned char c = 0;
	cin >> c;
	int count=calculate(c);
	cout << count << endl;
	return 0;
}