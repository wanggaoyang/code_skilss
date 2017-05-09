#include <iostream>
#include <string>
using namespace std;

void find_the_first(string str)//很机智，自己想的。
{
	int ret = -1;
	int length = str.length();
	int mask[200] = { 0 };
	for (int i=0; i < length; i++)//将对应的字符转成ACSII码值，作为数组的下标存起来，每出现一次，数组中对应加一。
	{
		mask[(int)str[i]]++;
	}
	for (int k = 0; k < length; k++)//再去遍历一遍，只看内容是1的值，是的话直接输出。
	{
		if (mask[(int)str[k]] == 1)
		{
			cout << str[k]<< endl;
			ret = 1;
			return ;
		}
	}
	cout << -1<< endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		find_the_first(str);
	}
	
	
	return 0;
}