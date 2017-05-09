#include <iostream>
#include <cctype>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class T>
T compare(T a[]);

int main(int argc, char** argv) 
{
	int com1[5]={0,1,2,3,4};
	double com2[5]={1.1,1.2,1.3,1.4,1.5};
	int c1;
	c1=compare(com1);
	cout<<c1<<endl;
	
	double c2;
	c2=compare(com2);
	cout<<c2<<endl;
	return 0;
}

template <class T>
T compare(T a[])
{
	T max=a[0];
	int i=0;
	for(;i<5;i++)
	{
		if(a[i+1]>a[i])
			max=a[i+1];
		max=a[i];
	}
	return max;
}
