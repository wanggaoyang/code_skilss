#include<iostream>
#include<vector>
using namespace std;

int deletenum(vector<int> &vec)
{
	vector<int>::iterator citor = vec.begin();
	int num = vec.size();
	for (int i = 0; i < num; i++)
	{
		vector<int>::iterator citor_next = citor+1;
		if ((i + 1) <= num && (((*citor + *citor_next) % 2) != 0))
		{
			citor=vec.erase(citor);
			citor=vec.erase(citor);
		}
		else
			citor++;
	}

	return vec.size();
}

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(4);
	vec.push_back(5);

	int ret=deletenum(vec);
	cout << ret << endl;
	return 0;
}
