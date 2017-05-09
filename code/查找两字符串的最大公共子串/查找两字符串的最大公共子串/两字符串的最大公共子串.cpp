#include<iostream>
#include<string>
using namespace std;
//说明：在函数的实现中，先找最长的（假设子串长5），只有一个；再找长度为4的，有两个；不断减小子串的长度进行查找。
//主要函数有：substr,find.
void findCommon(string a, string b) //a为长字符串，b为短字符串
{
	unsigned int len_a = a.length(), len_b = b.length();//两字符串的长度
	unsigned int maxlen = 0;//最长公共字符串的长度
	unsigned int maxindex = 0; //最长公共字符串的最后一个字符的位置
	for (unsigned int i = b.length() - 1; i>1; i--)
	{
		for (unsigned int j = 0; j <= b.length() - i; j++)
		{
			string temp;
			int t = 0;
			temp = b.substr(j, i);
			t = a.find(temp);
			if ((t != -1) && (maxlen<temp.length()))//匹配成功，并进行比较
			{
				maxlen = temp.length();
				maxindex = i + j;
			}

		}
	}
	cout << b.substr(maxindex - maxlen, maxlen) << endl;
}

int main()
{
	char *str1 = "helloworlddadada";
	char *str2 = "llo";
	char *ret = NULL;
	if (strstr(str1, str2) != NULL)
	{
		ret = strstr(str1, str2);
		cout << ret << endl;
	}

	string str3 = "hello world";
	string str4 = "worlsd";
	int t = str3.find(str4);
	cout << t << endl;

	string str5 = "helloworldibabyhiman";
	string str6 = "llororbaby";
	findCommon(str5,str6);
	return 0;
}