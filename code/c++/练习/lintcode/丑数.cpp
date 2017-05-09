#include <iostream>
using namespace std;
bool isUgly(int num) 
{
    // Write your code here
    if(num==0)
    {
		return false;	
	}
	if(num==1)
    {
    	return true;
	}
	while(num%2==0)
	{
		num=num/2;	
	}
	while(num%3==0)
	{
		num=num/3;
	}
	while(num%5==0)
	{
		num=num/5;
	}
	if(num==1)
		return true;
	else
		return false;	
        
}

int main()
{
	cout<<"请输入一个数字："<<endl;
	int num;
	cin>>num;
	cout<<isUgly(num);
	return 0;
}
