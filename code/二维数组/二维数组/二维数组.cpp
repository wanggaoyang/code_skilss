#include <iostream>
#include <vector>
using namespace std;

void show(int a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	vector<vector<int> > vec(3);

	vec[0].push_back(1);
	vec[0].push_back(2);
	vec[0].push_back(3);

	vec[1].push_back(4);
	vec[1].push_back(5);
	vec[1].push_back(6);

	vec[2].push_back(7);
	vec[2].push_back(8);
	vec[2].push_back(9);
	
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}	

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.size();
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << ' ';
		cout << endl;
	}
	
	show(a);
	return 0;
}