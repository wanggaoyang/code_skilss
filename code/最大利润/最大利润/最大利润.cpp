//股票最大利益
#include <iostream>
#include <vector>
using namespace std;

int getArrMax(int arr[]) 
{
	int Min = arr[0];
	int MaxDif = 0;

	for (int i = 1; i <= sizeof(arr); i++) 
	{
		if (arr[i] < Min) 
		{
			Min = arr[i];
		}
		if (arr[i] - Min > MaxDif) 
		{
			MaxDif = arr[i] - Min;
		}
	}
	return MaxDif;
}

int main() 
{
	int shares[100];
	int i = 0;
	int x;
	
	while (cin >> x)//输入 
	{
		shares[i]=x;
		i++;
		if (cin.get() == '\n')
			break;
	}
	
	int ret = 0;
	ret = getArrMax(shares);
	cout << ret << endl;
	return 0;
}