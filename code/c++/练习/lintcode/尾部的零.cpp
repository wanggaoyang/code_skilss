//β������
#include <iostream>
#include <cmath>
using namespace std;
//���취��������ʱ�����ƣ�ÿ����һ��5����++��  
long long trailingZeros(long long n)
{
	if(n==0)
		return 0;
	long long i;
	int count=0;
	for(i=1;i<=n;i++)
	{
		int p=i;
		while(p%5==0)
		{
			count++;
			p=p/5;
		}
	}    
	return count;    
}
//�취�ܴ��� 
long long trailingZeros2(long long n)
{
	long count = 0;

	for(int i = 5; i <= n; i=i*5) 
	{
        count += n / i;//ע��ǿ������ת��
    }
        return count;
}

int main()
{
	long long rel=trailingZeros2(100);
	cout<<rel;
	return 0;
}
