#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool is_odd(int x)
{
	return x % 2;
}

int delete_odd(vector<int> vec)
{
	stack<int> stack1;
	vector<int>::iterator itor = vec.begin();

	stack1.push(*itor);
	itor++;

	while (itor != vec.end())
	{
		if (!stack1.empty() && is_odd(*itor + stack1.top()))
		{
			stack1.pop();
		}
		else
		{
			stack1.push(*itor);
		}
		itor++;
	}

	int number = 0;
	while (!stack1.empty())
	{
		stack1.pop();
		number++;
	}
	return number;
}

int main()
{
	int size;
	while (cin >> size)
	{
		vector<int> vec;
		int num;
		
		if (size <= 0)
			cout << 0 << endl;

		for (int i = 0; i < size; i++)
		{
			cin >> num;
			vec.push_back(num);
		}

		cout << delete_odd(vec) << endl;
	}
	return 0;
}
