class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    void quick_sort(vector<int>& A,int l,int r) //快速排序
    {
        if(l<r)
        {
        	int i=l;
            int j=r;
        	int temp=A[i];
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
    int kthLargestElement(int k, vector<int> nums) 
    {
        // write your code here
        int size=nums.size();
        quick_sort(nums,0,size-1);
        return nums[size-k];
        
    }
};
