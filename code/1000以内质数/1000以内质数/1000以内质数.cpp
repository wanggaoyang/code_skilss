#include<iostream>
using namespace std;

int is_prime(int num);

int main()
{
	int num = 1000;
	int count = 0;
	for (int i = 2; i <= num; i++)
	{
		
		if (is_prime(i))
		{
			if (count < 10)
			{
				cout << i << ' ';
				count++;
			}	
			else
			{
				cout << endl;
				cout << i << ' ';
				count = 0;
			}	
		}	
	}

	
	return 0;
}

int is_prime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}