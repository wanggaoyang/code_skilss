#include <iostream>  
using namespace std;
const int M = 3;
const int N = 3;

int main()
{
	int a[M][N] = { {1,2,3},{4,5,6},{7,8,9} };
	int *p = a[0];
	/*��ʾ��ʼ����*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	/*�任�����*/
	int b[M][N] = { 0 };//��ʱ��
	int c[M][N] = { 0 };//˳ʱ��
	
	for (int i = 0; i < M; i++) // M = 3   
	{
		for (int j = N - 1,k=0; j >= 0; j--,k++) // N = 3  
		{
			b[i][j] = *(p + i + j*M);
			c[i][k] = *(p + i + j*M);
		}
	}
	/*��ʾ��ʱ�����*/
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	/*��ʾ˳ʱ�����*/
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}