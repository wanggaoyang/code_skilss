//��һ��˼·���Ȱ�����ת�����֣��������Ӽ����ٰѽ��ת������ 
//ȱ�㣺����̫���Ļ����Ͳ�������,�ٽ�������ĳ�long long 
#include<iostream>
using namespace std;
#include<vector>

vector<int> plusOne(vector<int>& digits) 
{
    // Write your code here
    int size=digits.size();
    long long val=0;
    long long i=1;
    for(size;size>0;size--)//����ת������ 
    {
        //cout<<val<<endl;
        
		cout<<digits[size-1]<<endl;
		val=val+digits[size-1]*i;
        i=i*10;
        cout<<"i "<<i<<endl;
        cout<<val<<endl;
    }
    //cout<<9*i<<endl;
    val=val+1;
    cout<<"result:"<<val<<endl;
    
    double num=0.1;
    long long c=val;
	while(c>=1)
    {
    	c=c/10;
    	num=num*10;
	}
	cout<<"number:"<<num<<endl;
	
	vector< int> rel;
	long long h=0;
	
	while(val>=1)
		{
			h=val/num;
			rel.push_back(h);	
			val=val-num*h;
			if(val==0)//����λ��0�����ʱ 
				for(num;num>1;num/=10)
				{
					rel.push_back(0);		
				}		
			else
				num=num/10;		
		}
		
	cout<<endl<<"final:";
	for(int p=0;p<rel.size();p++)
		cout<<rel[p]<<" ";
	
}

int main()
{
	vector <int> a;
	a.push_back(9);
	a.push_back(8);
	a.push_back(7);
	a.push_back(6);
	a.push_back(5);
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(0);
	
	plusOne(a);
	
	return 0;
}
