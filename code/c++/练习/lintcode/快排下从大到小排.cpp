//���źʹӴ�С�� 
#include<iostream>
#include <vector>
#include<algorithm>//sort������ 
using namespace std;

void quick_sort(vector<int>& A,int l,int r) //��������
{
    if(l<r)
    {
        int i=l;
        int j=r;
        int temp=A[i];
        while(i<j)
        {
        	while(i<j&&A[j]<=temp)
        	j--;
        	if(i<j)
        	{
        		A[i]=A[j];
        		i++; 
        	} 
        			
        	while(i<j&&A[i]>temp)
        		i++;
        	if(i<j)
        		A[j--]=A[i];
        }
        		
        A[i]=temp;
        quick_sort(A,l,i-1);//�ݹ飬�Ե�ǰλ�õ�ǰ����������½������� 
        quick_sort(A,i+1,r);
    }
}

int main()
{
	vector <int> A;
	A.push_back(6);
	A.push_back(8);
	A.push_back(9);
	A.push_back(1);
	A.push_back(3);
	A.push_back(7);
	A.push_back(5);
	A.push_back(2);
	
	quick_sort(A,0,A.size()-1);

	for(int k=0;k<A.size();k++)
		cout<<A[k]<<endl;
	return 0;
}
