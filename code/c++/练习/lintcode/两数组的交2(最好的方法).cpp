//跟张阿狸学来的高效的求两个数组的交的方法。先对两个数组排序。
//再同时遍历比较两个数组，大的就存在新建的第三个数组中 
//和交1相比，少了最后的两个while判断而已 
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
// Write your code here
    vector<int> ResultArray;
        
    sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	    
	const int nSize1 = nums1.size();//记录队列1大小 
	const int nSize2 = nums2.size();//记录队列2大小
	    
	int nPointer1 = 0;
	int nPointer2 = 0;
	while(nPointer1 < nSize1 && nPointer2 < nSize2)//当两个指针都没有到最后 
	{
		if(nums1[nPointer1] < nums2[nPointer2])//如果指针1的值小于指针2指向的值，则指针1指向下一个 
	    	nPointer1 ++;

		else if(nums1[nPointer1] > nums2[nPointer2])//如果指针2的值小于指针1指向的值，则指针2指向下一个 
			nPointer2 ++;

		else//(nums1[nPointer1] == nums2[nPointer2])//如果指两个指针所指的值相等了，则存在ResultArray队列中 
		{
			int tmpVal = nums1[nPointer1];
		    ResultArray.push_back(nums1[nPointer1]);
		    nPointer1++;
		    nPointer2++;
		}

	}
	return ResultArray;
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
	
	return 0;
}
