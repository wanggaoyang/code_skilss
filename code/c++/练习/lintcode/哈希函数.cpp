//��ϣ����
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*public int hashCode(char[] key,int HASH_SIZE) 
{
    long sum = (int)key[0];//sum * 33���ܻᳬ��int��Χ
    for(int i = 1; i < key.length; i++) 
	{
        sum = sum * 33 % HASH_SIZE + (int)key[i];//��ʹ���࣬���򳬳�long��Χ
    }
    return (int)(sum % HASH_SIZE);
}*/

int hashCode(string key,int HASH_SIZE) 
{
    // write your code here
    int size=key.size();
    long long sum=(int)(key[0]);
	cout<<"key[0]="<<key[0]<<endl;//char��ǿ��ת�������Σ�����ֵ��sum
	cout<<"sum="<<sum<<endl;
	for(int i=1;i<size;i++)
	{
		sum=sum*33%HASH_SIZE+(int)key[i];//����Ҫȡ��HASH_SIZE����Ϊ��������ַ����ܳ��Ļ���sum*33��ܴ󣬳�����	
	} //long �ķ�Χ�����½���������sum�к���2607�Ĺ�������Ҳ��Ӱ�����Ľ���� 
	return (int)(sum%HASH_SIZE);//���sum����С��2607���߾Ͳ���2607�Ĺ�����������%2607Ҳ���ı���ֵ 

}
int main()
{
	string key="abcdefghijklmnopqrstuvwxyz";
	int rel=hashCode(key,2607);
	cout<<rel;
	return 0;
}
