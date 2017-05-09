#include <iostream>
using namespace std;

void swap(char* &p1, char* &p2)
{
	char *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

void swap2(char* p1, char* p2)
{
	char *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

int main()
{
	char *p1 = "hello world";
	char *p2 = "hi baby its me";
	swap(p1, p2);
	cout << p1 << endl;
	cout << p2 << endl;

	swap2(p1,p2);
	cout << p1 << endl;
	cout << p2 << endl;
}