#include<iostream>
#include<string>
#include<stack>
#include <vector>
using namespace std;

int main()
{
	/*��һ
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}*/
	//����
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