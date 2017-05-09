//摆动排序，先用sort排好，再将下标为偶数的数组对应值和前一个值交换 
#include<iostream>
#include <vector>
#include<algorithm>//sort函数库 
using namespace std;

void swap(int &a,int &b)
    {
    	int temp;
    	temp=a;
    	a=b;
    	b=temp;
    }
    
void wiggleSort(vector<int>& nums) 
{
    // Write your code here
    sort(nums.begin(),nums.end());
    int size=nums.size();
    for(int i=1;i<size;i++)
    {
        if(i%2==0)
        		swap(nums[i],nums[i-1]);
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
	
	wiggleSort(A);
	for(int k=0;k<A.size();k++)
		cout<<A[k]<<endl;
	return 0;
}
