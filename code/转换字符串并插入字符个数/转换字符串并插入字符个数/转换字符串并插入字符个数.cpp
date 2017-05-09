#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>
using namespace std;

void insert(string str)
{
	vector<string> vec;
	int count = 0;
	int start = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i + 1] == '\0'||str[i] != str[i + 1])
		{
			vec.push_back(str.substr(start, count+1));
			start = i+1;
			count = 0;
			if (str[i + 1] == '\0')
				break;
		}
		else
			count++;
		
	}
	
	for (int i = 0; i < vec.size(); i++)//看一下是否都取出来了
	{
		cout << vec[i] << endl;
	}
	
	string temp;
	for (int i = 0; i < vec.size(); i++)
	{
		int number = vec[i].size();
		char nn = number + '0';//int转成char
		temp = temp + vec[i] + nn;
		cout << temp << endl;
	}
}

int main()
{
	string str = "hhhfffdddwwjiwksw";
	insert(str);
	return 0;
}