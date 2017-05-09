#include<iostream>
using namespace std;

int main()
{
	int a, b;

	while (cin >> a >> b)
	{
		cout << a + b << endl;
		cin.ignore();
	}
	return 0;
}