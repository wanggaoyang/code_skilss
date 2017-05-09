//nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2].

#include <iostream>
#include <vector> 
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
        // Write your code here
    int size1=nums1.size();//数组1中元素数量 
    int size2=nums2.size();//数组2中元素数量
    int s1=0;
    int s2=0;
    vector <int> nums3;//定义一个向量3用于存储相同变量 
    vector <int>::iterator citor3=nums3.begin();//定义叠加器 
    for(s1=0;s1<size1;s1++)
    {
        for(s2=0;s2<size2;s2++)
        {
        	if(nums1[s1]==nums2[s2])//相同的元素放到num3中 
        	{
        		nums3.push_back(nums1[s1]);	
        		citor3++;
			}
		}
	}
	
	
	return nums3;
}

int main()
{
	vector<int> nums1;
	vector<int> nums2;
	vector<int> nums3;
	//nums1[1,2,2,1];
	//nums2[2,2];
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);
	
	nums2.push_back(2);
	nums2.push_back(2);

	
	nums3=intersection(nums1,nums2);
	for(int k=0;k<nums3.size();k++)//打印相同元素 
	{
		cout<<nums3[k]<<endl;
	}
	/*下面对数组中重复元素进行处理*/
	int size3=nums3.size();//数组3中元素数量
	vector <int>::iterator head=nums3.begin();//定义叠加器 
	vector <int>::iterator head1;//定义叠加器 
	for(;head!=nums3.end();head++)
    {
        for(head1=head+1;head1!=nums3.end();)
        {
        	if(*head==*head1)//相同的元素删除
        	{
        		nums3.erase(head1);	
			}
			else
				head1++;
		}	
	} 
	cout<<"h"<<endl;
	for(int k=0;k<nums3.size();k++)//打印相同元素 
	{
		cout<<nums3[k]<<endl;
	}
	
	return 0;
}
