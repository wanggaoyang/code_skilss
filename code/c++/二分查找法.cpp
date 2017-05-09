//程序说明，二分查找法 
#include <iostream>
#include <vector>
using namespace std;

/*冒泡排序*/ 
void sortIntegers(vector<int>& A) 
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)//这一层的结果是将数组A中最小的元素放到第i个位置。
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }  
}

int BinarySearch(vector<int>& A , int len, int value)//非递归实现 
{
    //如果传入的数组为空或者数组长度<=0那么就返回-1。
    if(A.size()==0||len<=0)
        return -1;

    int start=0;
    int end=len-1;
    
    while(start<=end)//判断清是否有=
    {
        int mid=start+(end-start)/2;
        if(A[mid]==value)
            return mid;
        else if(value<A[mid])
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}

int main()
{
	vector <int> A;
	A.push_back(1);
	A.push_back(9);
	A.push_back(8);
	A.push_back(5);
	A.push_back(2);
	sortIntegers(A);

	for(int k=0;k<A.size();k++)
	{
		cout<<A[k]<<endl;
	}
	
	int rel=BinarySearch(A ,A.size(),1);
	
	cout<<rel;
	return 0;
}
