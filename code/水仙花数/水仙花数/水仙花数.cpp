#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vec;
	int start, end;
	while (cin >> start >> end)
	{
		for (int i = start; i <= end; i++)
		{
			
			int number = i;
			int num = i;
			int gewei = num % 10;
			num = num / 10;
			int shiwei = num % 10;
			num = num / 10;
			int baiwei = num;
					
			if ((gewei*gewei*gewei + baiwei*baiwei*baiwei + shiwei*shiwei*shiwei) == number)
				vec.push_back(number);
		}
		if (!vec.empty())
			for (int i = 0; i < vec.size(); i++)
				cout << vec[i] << ' ';
		else
			cout << "no" ;
		cout << endl;
		vec.clear();
	}
	return 0;
}