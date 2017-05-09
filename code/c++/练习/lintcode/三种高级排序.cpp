//����˵�������ָ߼����򷽷���ѧϰ ,���������򷽷���ʱ�临�Ӷȶ�ΪO��n�� 
#include <iostream>
#include <vector>
using namespace std;

/*ϣ������*/ 
void shell_sort(vector<int>& A) 
{
    int n=A.size();
    int group,j,temp;
	for (group=n/2;group>=1;group=group/2)//������d����ֱ�Ӳ������� 
    {
		for (int i = group; i < A.size(); i++)//�ӵڶ���Ԫ�ؿ�ʼ��������d�󣬵ڶ���Ԫ��Ϊ��d���ˣ� 
    	{
        	for (j=i-group;j>=0;j=j-group)//����������ʵ���ǲ���������
            {
                if (A[j] > A[j + group])//�����ϸ����ʵ���ǲ��������ˣ�ֻ�ǽ��Ƚϵļ��������group 
                {
                    temp = A[j];
                    A[j] = A[j + group];
                    A[j + group] = temp;
                }
            }	
    	}
    }  
}

/*��������*/ 
void quick_sort(vector<int>& A,int l,int r) //rΪ����A�����һ��Ԫ�ص��±� 
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
		quick_sort(A,l,i-1);//�ݹ飬�Ե�ǰλ�õ�ǰ����������½������� 
		quick_sort(A,i+1,r);
	}
}

�鲢����
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
