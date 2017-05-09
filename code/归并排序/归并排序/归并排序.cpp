#include<iostream>
#include<vector>
using namespace std;

void MemeryArray(int a[], int n, int b[], int m, int c[])//��������������ϲ���һ��������
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

void MemeryArray2(int a[], int first, int mid, int last, int temp[])//������һ���Ż�������������ϲ�����һ�����鵱�С�
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

	for (int i = 0; i < k; i++)//��temp�������ٷ���a��
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
		mergesort(a, first, mid, temp);    //�������  
		mergesort(a, mid + 1, last, temp); //�ұ�����  
		MemeryArray2(a, first, mid, last, temp); //�ٽ������������кϲ�  
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