//ɾ��Ԫ�أ����ƶ������ƣ��������Ĳ������� 
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &A, int elem)
{
    // write your code here
    vector<int>::iterator citor=A.begin();
    int size=A.size();
    int i=0;
    for(i;i<size;i++)
	{
	    if(*citor==elem)
		{
			A.erase(citor);	
		}
		else
			citor++;	
    }
    	return A.size();
}

int main()
{
	return 0;
}
