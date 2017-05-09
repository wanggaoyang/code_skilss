#include<iostream>
using namespace std;

char *strcpy1(char *strDest, const char *strSrc)
{
	if (strDest == NULL || strSrc == NULL)
		return NULL;
	if (strlen(strDest) < strlen(strSrc))
		return NULL;
	
	if (strSrc != NULL)
	{
		char *address = strDest;
		while (*strSrc != '\0')
		{
			*strDest = *strSrc;
			strDest++;
			strSrc++;
		}
		return address;      
	}
}

int main()
{
	char Src[] = "hello world";
	char Dest[12] = "hhhhhhhhh";
	//char *Src= "hello world";
	//char *Dest = "hhhhhhhhhhhh";
	char *str=strcpy1(Dest, Src);
	cout << str << endl;
	return 0;
}
