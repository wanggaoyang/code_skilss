//哈希函数
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*public int hashCode(char[] key,int HASH_SIZE) 
{
    long sum = (int)key[0];//sum * 33可能会超出int范围
    for(int i = 1; i < key.length; i++) 
	{
        sum = sum * 33 % HASH_SIZE + (int)key[i];//即使求余，否则超出long范围
    }
    return (int)(sum % HASH_SIZE);
}*/

int hashCode(string key,int HASH_SIZE) 
{
    // write your code here
    int size=key.size();
    long long sum=(int)(key[0]);
	cout<<"key[0]="<<key[0]<<endl;//char型强制转换成整形，并赋值给sum
	cout<<"sum="<<sum<<endl;
	for(int i=1;i<size;i++)
	{
		sum=sum*33%HASH_SIZE+(int)key[i];//这里要取余HASH_SIZE是因为若输入的字符串很长的话，sum*33会很大，超过了	
	} //long 的范围，导致结果出错，如果sum中含有2607的公倍数，也不影响最后的结果！ 
	return (int)(sum%HASH_SIZE);//如果sum本身小于2607或者就不是2607的公倍数，就算%2607也不改变其值 

}
int main()
{
	string key="abcdefghijklmnopqrstuvwxyz";
	int rel=hashCode(key,2607);
	cout<<rel;
	return 0;
}
