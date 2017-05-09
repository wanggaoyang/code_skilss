#include<stdio.h>
#include <string>
using namespace std;

//char *func(char *ptr)
//{
//	ptr += 8;
//	return (ptr);
//}
//int test(int **p)
//{
//	
//	return **p***p***p;
//}
int main()
{
	int i = 0;
	char bword;
	while (i <= 3)
	{
		scanf_s("%c", &bword);
		ungetc(bword, stdout);
		printf("%c", bword);
		ungetc(bword, stdin);
		i++;
	}
	//char grade[] = "dwdad";
	//printf("%.4s", grade);
	return 0;
	
}

