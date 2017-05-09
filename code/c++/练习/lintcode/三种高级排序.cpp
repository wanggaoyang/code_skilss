//程序说明，几种高级排序方法的学习 ,这三种排序方法的时间复杂度都为O（n） 
#include <iostream>
#include <vector>
using namespace std;

/*希尔排序*/ 
void shell_sort(vector<int>& A) 
{
    int n=A.size();
    int group,j,temp;
	for (group=n/2;group>=1;group=group/2)//以增量d进行直接插入排序 
    {
		for (int i = group; i < A.size(); i++)//从第二个元素开始（以增量d后，第二个元素为第d个了） 
    	{
        	for (j=i-group;j>=0;j=j-group)//这里往后其实就是插入排序了
            {
                if (A[j] > A[j + group])//这里的细节其实就是插入排序了，只是将比较的间隔换成了group 
                {
                    temp = A[j];
                    A[j] = A[j + group];
                    A[j + group] = temp;
                }
            }	
    	}
    }  
}

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

归并排序
void Merge(Record r[],Record r1[],int s, int m,int t)
{
	i=s;j=m;k=s;
	while(i<=m&&j<=t)
		if(r[i].key<=r[j.key])
			r1[k++]=r[i++];
		else r1[k++]=r[j++];
	if(i<=m) r1[k++]=r[i++];
		while(i<=m) r1[k++]=r[i++];
	else
		while(j<=t) r1[k++]=r[j++];
}

void MergeSort(Record r[],Record r1[],int s, int m,int t)
{
    if (s==t)	
		r1[s]=r[s];
	else
	{
		m=(s+t)/2;
		MergeSort(r,r2,s,m);
		MergeSort(r,r2,m+1,t);
		Merge(r2,r1,s,m,t);
	}
    

}


int main()
{
	vector <int> A;
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	A.push_back(4);
	A.push_back(5);
	//shell_sort(A);
	quick_sort(A,0,A.size()-1);
	for(int k=0;k<A.size();k++)
	{
		cout<<A[k]<<endl;
	}
	return 0;
}
