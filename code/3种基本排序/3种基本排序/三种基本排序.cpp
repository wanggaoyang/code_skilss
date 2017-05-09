#include <iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i; j < vec.size(); j++)
		{
			if (vec[i] > vec[j])
			{
				int temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}
void insert_sort(vector<int> &vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int j = 0;
		while (j < i&&vec[j] < vec[i])
			j++;
		if (j < i)
		{
			int k = i;
			int temp = vec[i];
			while (k > j)
			{
				vec[k] = vec[k - 1];
				k--;
			}
			vec[j] = temp;
		}
	}
}
void select_sort(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int min = vec[i]; int min_index = i;
		for (int j = i; j < vec.size(); j++)
		{
			if (vec[j] < min)
			{
				min = vec[j];
				min_index = j;
			}
		}

		if (min != vec[i])
		{
			int temp = vec[i];
			vec[i] = min;
			vec[min_index] = temp;
		}
	}
}
int main()
{
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);

	//bubble_sort(vec);
	//insert_sort(vec);
	select_sort(vec);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
	return 0;
}