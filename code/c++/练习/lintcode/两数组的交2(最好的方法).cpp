//���Ű���ѧ���ĸ�Ч������������Ľ��ķ������ȶ�������������
//��ͬʱ�����Ƚ��������飬��ľʹ����½��ĵ����������� 
//�ͽ�1��ȣ�������������while�ж϶��� 
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
	    
	const int nSize1 = nums1.size();//��¼����1��С 
	const int nSize2 = nums2.size();//��¼����2��С
	    
	int nPointer1 = 0;
	int nPointer2 = 0;
	while(nPointer1 < nSize1 && nPointer2 < nSize2)//������ָ�붼û�е���� 
	{
		if(nums1[nPointer1] < nums2[nPointer2])//���ָ��1��ֵС��ָ��2ָ���ֵ����ָ��1ָ����һ�� 
	    	nPointer1 ++;

		else if(nums1[nPointer1] > nums2[nPointer2])//���ָ��2��ֵС��ָ��1ָ���ֵ����ָ��2ָ����һ�� 
			nPointer2 ++;

		else//(nums1[nPointer1] == nums2[nPointer2])//���ָ����ָ����ָ��ֵ����ˣ������ResultArray������ 
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
	for(int k=0;k<nums3.size();k++)//��ӡ��ͬԪ�� 
	{
		cout<<nums3[k]<<endl;
	}
	
	return 0;
}
