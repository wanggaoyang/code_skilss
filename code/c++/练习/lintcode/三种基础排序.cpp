//����˵�����������򷽷���ѧϰ ,���������򷽷���ʱ�临�Ӷȶ�ΪO��n*n�� 
#include <iostream>
#include <vector>
using namespace std;

/*ð������*/ 
void sortIntegers(vector<int>& A) 
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)//��һ��Ľ���ǽ�����A����С��Ԫ�طŵ���i��λ�á�
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

/*ѡ������*/ 
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
        
		if(min_index!=i)//����С�ķŵ���i��λ��
        {
        	int temp=A[i];
        	//A[i]=min;���˾��滻�����Ҳ�У� 
        	A[i]=A[min_index]; 
        	A[min_index]=temp;

		}
    }  
}

/*��������*/
void insertion_sort(vector<int>& A)
{
    for (int i = 1; i < A.size(); i++)//�ӵڶ���Ԫ�ؿ�ʼ 
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
