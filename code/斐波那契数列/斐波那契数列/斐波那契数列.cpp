#include<iostream>
using namespace std;
//�ݹ鷽�������ܴ�ʱ�����˷ѿռ䣬�������ջ�����
int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return Fibonacci(n - 1)+ Fibonacci(n - 2);

}

//ѭ������
int Fibonacci2(int n)
{
	if (n == 1||n == 2)
		return 1;
	int p = 1, q = 1;
	int sum = 0;
	for (int i = 0; i < n-2; i++)
	{
		sum = p + q;
		p = q;
		q = sum;
	}
	return sum;
}
int main()
{
	int ret = Fibonacci(7);
	cout << ret << endl;

	ret = Fibonacci2(7);
	cout << ret << endl;
	return 0;
}