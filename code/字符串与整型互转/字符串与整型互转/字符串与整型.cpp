#include<iostream>
using namespace std;
/* char to int*/
int char_to_int(char ch[])
{
	int i = 0, sum = 0;
	while (ch[i])
	{
		sum = sum * 10 + (ch[i] - '0');
		i++;
	}
	return sum;
}

void int_to_char(int num)
{
	int i = 0;
	char temp[7];
	while (num)
	{
		temp[i] = num % 10 + '0';
		i++;
		num = num / 10;
	}
	temp[i] = '\0';
	cout << "string" << temp << endl;

	i = i - 1;
	int j = 0;
	char str[7];
	while (i >= 0)
	{
		str[j] = temp[i];
		j++;
		i--;
	}

	str[j] = '\0';
	cout << "string"<< str << endl;
}

int main()
{
	char a[7] = { "12345" };
	int num=char_to_int(a);

	cout << "int"<< num << endl;

	int_to_char(num);
}