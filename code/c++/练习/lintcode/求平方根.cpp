//程序说明，通过牛顿迭代法来计算sqrt 
#include <iostream>
using namespace std;

long sqrt(int x)
{
	long val=1000000000;
	long last=0; 
	do
	{
		last=val;
		cout<<"val:"<<val<<"+"<<"x/val:"<<x/val;
		val=(val+x/val)/2;
		cout<<"="<<val<<endl;
	}while((last-val)>1);
	return val;

}
int main()
{
	long rel=sqrt(999999999);
	cout<<"结果：";
	cout<<rel;
	return 0;
}

