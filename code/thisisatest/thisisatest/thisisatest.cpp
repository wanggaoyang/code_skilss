#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverse(string str)
{
	stack<string> stack;
	int length = str.size();
	int start = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' '||str[i+1] == '\0')
		{
			string temp = str.substr(start, i-start+1);
			cout << temp << ' ';
			stack.push(temp);
			start = i+1;
		}
	}
	
	cout << endl;
	int len = stack.size();
	
	str.clear();
	
	string temp;
	for (int i = 0; i < len; i++)
	{
		temp = stack.top();
		if(i==0)
			str = str + temp+' ';
		else
			str = str + temp;
		stack.pop();
	}
	cout << str;
	return str;
}

int main()
{

	string hi = "this is a new world";
	reverse(hi);
	return 0;
}