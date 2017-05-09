#include<iostream>
#include<vector>
using namespace std;

class three_niubi_sort
{
private:
	vector<int> vec;
	int length;

public:
	three_niubi_sort(vector<int> _list, int _len);//类的构造函数
//	void shell_sort();
	void quick_sort(int l, int r);
	void show();
};

three_niubi_sort::three_niubi_sort(vector<int> _list, int _len)//构造函数定义
{
	for (int i = 0; i < _len; i++)
	{
		vec.push_back(_list[i]);
		cout << vec[i] << ' ';
	}
	cout << endl;
	this->length = _len;
}

void three_niubi_sort::quick_sort(int l,int r)
{

	if (l < r)
	{
		int i = l;
		int j = r;
		int temp = vec[i];

		while (i<j&&vec[j]>temp)
			j--;
		if (i < j)
		{
			vec[i] = vec[j];
			i++;
		}
		while (i < j&&vec[i] < temp)
			i++;
		if (i < j)
		{
			vec[j] = vec[i];
			j--;
		}

		vec[i] = temp;
		quick_sort( l, i - 1);
		quick_sort( i + 1, r);
	}

}

void three_niubi_sort::show()
{
	for (int i = 0; i < length; i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}

//void quick_sort(vector<int> & vec, int l, int r)
//{
//	if (l < r)
//	{
//		int i = l; int j = r;
//		int temp = vec[i];
//		while (i<j&&vec[j]>temp)
//			j--;
//		if (i < j)
//		{
//			vec[i] = vec[j];
//			i++;
//		}
//		while (i < j&&vec[i] < temp)
//			i++;
//		if (i < j)
//		{
//			vec[j] = vec[i];
//			j--;
//		}
//
//		vec[i] = temp;
//		quick_sort(vec, l, i-1);
//		quick_sort(vec, i + 1, r);
//	}
//}
int main()
{
	vector <int> A;
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	A.push_back(4);
	A.push_back(5);
	//shell_sort(A);

	three_niubi_sort sort(A, 5);
	sort.quick_sort(0,4);
	sort.show();
	return 0;
}