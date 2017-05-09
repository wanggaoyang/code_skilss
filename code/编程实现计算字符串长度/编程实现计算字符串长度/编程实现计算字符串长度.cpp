#include<iostream>
using namespace std;

int calculate_String(const char *str)
{
	if (str == NULL)
		return 0;
	int length = 0;
	while (*str++ != '\0')
		length++;
	return length;
}

int main()
{
	char *str = "hello world";
	int ret = calculate_String(str);
	cout << ret << endl;
}