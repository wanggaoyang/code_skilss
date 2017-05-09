#include <iostream>  
using namespace std;
const int M = 3;
const int N = 3;

int main()
{
	int a[M][N] = { {1,2,3},{4,5,6},{7,8,9} };
	int *p = a[0];
	/*ÏÔÊ¾³õÊ¼¾ØÕó*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	/*±ä»»ºó¾ØÕó*/
	int b[M][N] = { 0 };//ÄæÊ±Õë
	int c[M][N] = { 0 };//Ë³Ê±Õë
	
	for (int i = 0; i < M; i++) // M = 3   
	{
		for (int j = N - 1,k=0; j >= 0; j--,k++) // N = 3  
		{
			b[i][j] = *(p + i + j*M);
			c[i][k] = *(p + i + j*M);
		}
	}
	/*ÏÔÊ¾ÄæÊ±Õë¾ØÕó*/
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	/*ÏÔÊ¾Ë³Ê±Õë¾ØÕó*/
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}