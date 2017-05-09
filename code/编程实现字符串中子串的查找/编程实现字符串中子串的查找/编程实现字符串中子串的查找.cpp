#include<iostream>
using namespace std;

int find_sub(const char *src, const char *sub)
{
	const char *sb;
	int pos = 0;
	
	if (src == NULL || sub == NULL)
		return -1;
	while ((*src)!='\0')
	{
		sb = sub;
		while (*src == *sb)
		{
			src++;
			sb++;
			if ((*sb) == '\0')
				return pos;
		}
		pos++;
		src++;
	}
	return -1;
}

int main()
{
	const char *src = "hello fantastic world";
	const char *sub = "wor";
	int pos=find_sub(src, sub);
	cout << pos << endl;
	return 0;
}