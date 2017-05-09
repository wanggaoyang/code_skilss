#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>& A, int len, int value)//非递归实现 
{
	//如果传入的数组为空或者数组长度<=0那么就返回-1。
	if (sizeof(A) == 0 || len <= 0)
		return -1;

	int start = 0;
	int end = len - 1;

	while (start <= end)//判断清是否有=
	{
		int mid = start + (end - start) / 2;
		if (A[mid] == value)
			return mid;
		else if (value<A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main()
{
	int find_num;
	int number;
	int temp;
	vector<int> vec;

	cin >> find_num >> number;
	for(int i=0;i<number;i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	
	int ret;
	ret = BinarySearch(vec, number, find_num);//返回索引

	cout << ret << endl;
	return 0;
}