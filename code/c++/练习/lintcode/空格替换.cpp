#include <iostream>
using namespace std;
 
int replaceBlank(char string[], int length)  
{  
    if (length == 0)  
    {  
        return 0;  
    }  
    int cnt = 0;  
    for (int i = 0; i < length; i++)  
    {  
    	if (string[i] == ' ')  
    	{  
        	cnt++;  
    	}  
    }  
    int longth = length + 2 * cnt;  
    
/*	for (int i = length-1; i >= 0; i--)  //�ҵİ취���Ӻ��濪ʼ��� 
    {  
        cout<<string[i]<<endl;
		if (string[i] == ' ')  
        {  
            string[j--] = '0';  
            string[j--] = '2';  
            string[j--] = '%';  
        } 
		else  
        {  
            string[j] = string[i]; 
            j=j-1;
        }  
    }
*/	
	char rel[20];//�Լ��İ취����ͷ��� 
	int j=0;
	for (int i=0; i <length ; i++)  //��һ��ԭʼ�ַ��� 
    {  
        //cout<<string[i]<<endl;
		if (string[i] == ' ')  //����0�ͽ�0,2,%���η����½������ַ��������У�ÿ����һ���µ��ַ���j++ 
        {  
            rel[j++] = '0';  
            rel[j++] = '2';  
            rel[j++] = '%';  
        } 
		else  
        {  
            rel[j] = string[i]; //����Ͱ�ԭ���ַ����еĶ���ֱ�ӷ���rel�� 
            //cout<<rel[j]<<endl;
            j=j+1;
        }
     	
    }
    for(int k=0;k<longth;k++)
		cout<<rel[k]; 

    return longth;  
}  
int main()
{
	char p[20]="hello world dog";
	int length=replaceBlank(p,15);
	cout<<length<<endl;
	return 0;
}
