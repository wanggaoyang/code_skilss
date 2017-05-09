#include <iostream>
#include <string>
#include <stack>
using namespace std;

string tfm(int num)//Êý×Ö×ª×Ö·û´®
{
	char ret[10]="";
	stack<char> vec;
	static int i = 0;
	while (num)
	{
		vec.push((num % 10) + '0');
		num /= 10;
	}

	while(!vec.empty())
	{
		ret[i++] = vec.top();
		vec.pop();
	}
	ret[i] = '\0';
	return ret;
}

int tfm2(const char *str)//×Ö·û´®×ªÊý×Ö
{
	int temp=0;
	while (*str != 0)
	{
		temp = temp * 10 + (*str - '0');
		str++;
	}
	return temp;
}

int main()
{
	int num = 123;
	string ret=tfm(num);
	cout << ret << endl;

	char p[10] = "";
	cin.getline(p, 20);
	int ret_num = tfm2(p);
	cout << ret_num << endl;
	return 0;
}