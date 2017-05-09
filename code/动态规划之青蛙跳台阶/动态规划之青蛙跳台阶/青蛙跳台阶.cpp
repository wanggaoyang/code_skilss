//和斐波那契数一样，递归实现就行
#include <iostream>
using namespace std;

int jump(int num)
{
	if (num == 1)
		return 1;
	else if (num == 2)
		return 2;
	else
		return jump(num - 1) + jump(num - 2);
}

int main()
{
	int num;
	while (cin >> num)
	{
		int ret = jump(num);
		cout << ret << endl;
	}
	return 0;
}