#include<iostream>
#include<stdlib.h>
using namespace std;


int main()
{
	int *ch = new int[10];
	delete(ch);
	delete(ch);
}