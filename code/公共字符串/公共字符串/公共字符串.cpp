#include <iostream>  
#include <string>  
using namespace std;

int getCommonStrLength(string s1, string s2)
{
	int count = 0;
	int len1 = s1.length();
	int len2 = s2.length();
	int i, j;
	//将st1中所有的字母变小写    
	for (i = 0; i<len1; i++)
	{
		if (isupper(s1[i]))
			s1[i] = tolower(s1[i]);

	}
	i = 0;
	//将st2中所有的字母变小写    
	for (j = 0; j<len2; j++)
	{
		if (isupper(s2[j]))
			s2[j] = tolower(s2[j]);

	}

	if (s1 == " " || s2 == " ")
		return 0;

	for (int i = 0; i<len1; i++)
	{
		for (int j = 0; j<len2; j++)
		{
			int number = 0;
			if (i == len1 || j == len2)
				break;

			while (s1[i] == s2[j])
			{
				i++; j++;
				number++;

				count = count>number ? count : number;

				if (i == len1 || j == len2)
					break;
				if (count == len1 || count == len2)
					return count;
			}
		}
	}
	return count;
}

int main()
{
	string s, str1, str2;
	getline(cin, s);

	int pos = s.find(' ');//存储第一个空格的位置  
	cout << pos << endl;

	int len = s.length();
	//while(s[++position]!=' '&&position<len);  
	cout << len << endl;
	str1 = s.substr(0, pos);

	str2 = s.substr(pos + 1, len - pos - 1);

	cout << getCommonStrLength(str1, str2) << endl;
	return 0;

}



