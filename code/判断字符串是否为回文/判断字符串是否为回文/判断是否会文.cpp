#include<iostream>
#include<string>
using namespace std;

int IsRevStr(char *str)
{
	char *start = str, *end = str, *ptr = str;
	int count = 0;
	while (*ptr != '\0')
	{
		ptr++;
		count++;
	}	
	end = ptr - 1;
	if (count % 2 != 0)
	{
		while ((start != end) && (*start == *end))
		{
			start++;
			end--;
		}
		if (start == end)
			return 1;
		else
			return 0;
	}
	else
	{
		while (((start+1) != end) && (*start == *end))
		{
			start++;
			end--;
		}
		if ((start+1) == end&&(*start==*end))
			return 1;
		else
			return 0;
	}
	
}

int main()
{
	char *str = "levvel";
	int ret=IsRevStr(str);
	cout << ret << endl;
}