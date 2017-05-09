#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>& A, int len, int value)//�ǵݹ�ʵ�� 
{
	//������������Ϊ�ջ������鳤��<=0��ô�ͷ���-1��
	if (sizeof(A) == 0 || len <= 0)
		return -1;

	int start = 0;
	int end = len - 1;

	while (start <= end)//�ж����Ƿ���=
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
	ret = BinarySearch(vec, number, find_num);//��������

	cout << ret << endl;
	return 0;
}