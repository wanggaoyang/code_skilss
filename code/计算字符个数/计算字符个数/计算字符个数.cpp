#include <iostream>
#include <string>
using namespace std;

int find_number(string str,char ch)
{
	for (int k = 0; k < str.length(); k++)//先把大小写统一了
	{
		if (isupper(str[k]))
			str[k] = tolower(str[k]);
	}
	int count = 0;
	for (int i = 0; i < str.length(); i++)//再去计算字符个数
	{
		if (str[i] == ch)
			count++;
	}
	return count;
}

int main()
{
	string s;
	int ret = 0;
	while (getline(cin, s))
	{
		char ch;
		cin>>ch;
		ret=find_number(s,ch);
		cout << ret << endl;
		cin.ignore();
	}
	
	return 0;
}
