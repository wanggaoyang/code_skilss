//程序说明，几种排序方法的学习 ,这三种排序方法的时间复杂度都为O（n*n） 
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

/*选择排序*/ 
void selection_sort(vector<int>& A) 
{
    for (int i = 0; i < A.size(); i++)
    {
        int min=A[i]; int min_index=i; 
		for (int j = i; j < A.size(); j++)
        {
            if (A[j] < min)
            {
                min = A[j];
                min_index=j;
            }
        }
        
		if(min_index!=i)//把最小的放到第i个位置
        {
        	int temp=A[i];
        	//A[i]=min;（此句替换下面句也行） 
        	A[i]=A[min_index]; 
        	A[min_index]=temp;

		}
    }  
}

/*插入排序*/
void insertion_sort(vector<int>& A)
{
    for (int i = 1; i < A.size(); i++)//从第二个元素开始 
    {
        if (A[i-1] > A[i])
        {
            int temp = A[i];
            int j = i;
            while (j > 0 && A[j - 1] > temp)
            {
               	A[j] = A[j - 1];
                j--;
            }
            A[j] = temp;
        }
    }
}


int main()
{
	vector <int> A;
	A.push_back(1);
	A.push_back(9);
	A.push_back(8);
	A.push_back(5);
	A.push_back(2);
	//sortIntegers(A);
	//selection_sort(A);
	insertion_sort(A);
	for(int k=0;k<A.size();k++)
	{
		cout<<A[k]<<endl;
	}
	return 0;
}
