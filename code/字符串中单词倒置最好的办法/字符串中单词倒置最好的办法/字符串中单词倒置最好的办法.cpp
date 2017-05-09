#include<iostream>
using namespace std;

void RevStr(char *src)
{
	char *start = src, *end = src, *ptr = src;
	while (*ptr++ != '\0')
	{
		if (*ptr == ' ' || *ptr == '\0')
		{
			end = ptr - 1;
			while (start < end)
				swap(*start++, *end--);

			start = ptr + 1;
		}
	}
	start = src, end = ptr - 2;
	
	while (start < end)
		swap(*start++, *end--);
}

int main()
{
	char src[] = "I am your father";
	cout << src << endl;
	RevStr(src);
	cout << src << endl;
	return 0;
}