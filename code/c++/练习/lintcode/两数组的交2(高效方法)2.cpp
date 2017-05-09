//nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2].

#include <iostream>
#include <vector> 
using namespace std;

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        // Write your code here
        int size1=nums1.size();
   	    int size2=nums2.size();
	    const int max=(size1>size2?size1:size2);
	    int arr[max]={0};//定义一个空数组
	    vector <int> nums3;
	
	    for(int k=0;k<size1;k++)
	    {
		    arr[nums1[k]]=1;
    	} 
	    for(int i=0;i<size1;i++)
	    {
		    cout<<arr[i]<<endl;
	    }
	
	    for(int t=0;t<size2;t++)
	    {
		    if(arr[nums2[t]]==1)
		    	{
				    nums3.push_back(nums2[t]);
				    arr[nums2[t]]=0;
		    	}
	    } 
	    return nums3;
    }

int main()
{
	vector<int> nums1(2,1,4);
	vector<int> nums2(1,1);

//	nums1.push_back(1);
//	nums1.push_back(2);
//	nums1.push_back(2);
//	nums1.push_back(1);
	
	//nums2.push_back(2);
	//nums2.push_back(2);

	
	vector<int> nums3=intersection(nums1,nums2);
	cout<<"the result is: "<<endl;
	for(int k=0;k<nums3.size();k++)//打印相同元素 
	{
		cout<<nums3[k]<<endl;
	}
	
	return 0;
}
