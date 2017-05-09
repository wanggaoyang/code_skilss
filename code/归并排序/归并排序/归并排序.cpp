#include<iostream>
#include<vector>
using namespace std;

void MemeryArray(int a[], int n, int b[], int m, int c[])//将两个有序数组合并到一个数组里
{
	int i, j, k;
	i = j = k = 0;
	while (i < n&&j < m)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}

	while (i < n)
	{
		c[k++] = a[i++];
	}

	while (j < m)
	{
		c[k++] = b[j++];
	}

	for (int i = 0; i < 10; i++)
		cout << c[i] << ' ';
	cout << endl;
}

void MemeryArray2(int a[], int first, int mid, int last, int temp[])//下面做一点优化，把两个数组合并到第一个数组当中。
{
	int i, j, m, l,k;
	i = first;
	j = mid + 1;
	m = mid;
	l = last;
	k = 0;

	while (i <= m&&j <= l)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}

	}

	while (i < m)
	{
		temp[k++] = a[i++];
	}
	while (j < l)
	{
		temp[k++] = a[j++];
	}

	for (int i = 0; i < k; i++)//把temp中数据再放入a中
	{
		a[first + i] = temp[i];
	}

	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序  
		mergesort(a, mid + 1, last, temp); //右边有序  
		MemeryArray2(a, first, mid, last, temp); //再将二个有序数列合并  
	}
}
int main()
{
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	//int b[5] = { 1,3,5,7,9 };
	//int c[5] = { 2,4,6,8,10 };
	//int d[10] = {0};

	int *p = new int[10];
	mergesort(a, 0, 9, p);
	delete[] p;

	//MemeryArray(b, 5, c, 5, d);
	//MemeryArray2(a, 0, 4, 9, d);
	return 0;
}