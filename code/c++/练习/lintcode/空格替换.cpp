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
    
/*	for (int i = length-1; i >= 0; i--)  //找的办法，从后面开始输出 
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
	char rel[20];//自己的办法，从头输出 
	int j=0;
	for (int i=0; i <length ; i++)  //过一遍原始字符串 
    {  
        //cout<<string[i]<<endl;
		if (string[i] == ' ')  //遇到0就将0,2,%依次放入新建立的字符串队伍中，每加入一个新的字符，j++ 
        {  
            rel[j++] = '0';  
            rel[j++] = '2';  
            rel[j++] = '%';  
        } 
		else  
        {  
            rel[j] = string[i]; //否则就把原来字符串中的东西直接放入rel中 
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
