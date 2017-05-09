#include<iostream>
using namespace std;

int main()
{
	char str[] = "33363557773456789";
	int i, j = 0;
	for (i = 0; str[i]; i++)
		if (str[i] != str[i - 1]&&str[i]!=str[i+1])
			str[j++] = str[i];
	str[j] = 0;
	cout << str << endl;
	return 0;
}