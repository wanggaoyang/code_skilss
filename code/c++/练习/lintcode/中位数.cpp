//����˵�������ÿ������������λ������Ѱ 
#include <iostream>
#include <vector>
using namespace std;
/*��������*/ 
void quick_sort(vector<int>& A,int l,int r) //rΪ����A�����һ��Ԫ�ص��±� 
{
    if(l<r)
	{
		int i=l;
    	int j=r;
		int temp=A[i];
		cout<<"A[j]"<<A[j]<<endl;
		while(i<j)
		{
			while(i<j&&A[j]>=temp)
			j--;
			if(i<j)
			{
				A[i]=A[j];
				i++; 
			} 
			
			while(i<j&&A[i]<temp)
				i++;
			if(i<j)
				A[j--]=A[i];
		}
		
		A[i]=temp;
		quick_sort(A,l,i-1);//�ݹ飬�Ե�ǰλ�õ�ǰ����������½������� 
		quick_sort(A,i+1,r);
	}
}

int median(vector<int> &nums) 
{
// write your code here
	int size=nums.size();
	quick_sort(nums,0,size-1);//ע�⣬����һ��Ҫ��size-1������,�����βԪ�ص��±� 
	if(size%2==0)
		//return nums[size/2];
		cout<<nums[size/2-1]<<endl;
	else
		//return nums[(size+1)/2];
		cout<<nums[(size-1)/2]<<endl;
}

int main()
{
	vector <int> A;
	A.push_back(4);
	A.push_back(5);
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	//shell_sort(A);
	//quick_sort(A,0,A.size()-1);
	median(A);
	for(int k=0;k<A.size();k++)
	{
		cout<<A[k]<<endl;
	}
	return 0;
}
