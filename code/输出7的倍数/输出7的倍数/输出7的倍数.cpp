#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 7 == 0)
			cout << '*' << ' ';
		else if ((i-7)%10==0)
			cout << '*' << ' ';
		else if((i-70)>0&&(i-70)<10)
			cout<< '*' << ' ';
		else
			cout << i << ' ';
	}
	cout << endl;
	return 0;
}