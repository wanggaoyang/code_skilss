#include<iostream>
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;

void swap(char *x, char *y)
{
	char *temp;
	temp = x;
	x = y;
	y = temp;

}
int main()
{
	char *ap = "hello world";
	char *bp = "hi baby";

	swap(ap, bp);
	cout << ap << endl;
	cout << bp << endl;

}