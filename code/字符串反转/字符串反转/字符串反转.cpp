#include<iostream>
#include<string>
#include<stack>
#include <vector>
using namespace std;

int main()
{
	/*法一
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}*/
	//法二
	stack<char> ch_stack;
	char ch;
	while ((ch=getchar())!='\n') {
		ch_stack.push(ch);
	}

	while (!ch_stack.empty())
	{
		cout << ch_stack.top();
		ch_stack.pop();
	}
	return 0;
}