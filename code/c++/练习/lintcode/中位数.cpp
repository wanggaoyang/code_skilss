//程序说明，利用快速排序进行中位数的找寻 
#include <iostream>
#include <vector>
using namespace std;
/*快速排序*/ 
void quick_sort(vector<int>& A,int l,int r) //r为向量A中最后一个元素的下标 
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
		quick_sort(A,l,i-1);//递归，对当前位置的前后的序列重新进行排序 
		quick_sort(A,i+1,r);
	}
}

int median(vector<int> &nums) 
{
// write your code here
	int size=nums.size();
	quick_sort(nums,0,size-1);//注意，这里一定要是size-1！！！,这才是尾元素的下标 
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
