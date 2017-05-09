#include <iostream>
#include <string>
#include <map>
using namespace std;
//��������ǰ��Ӵ��ַ�˳��ͬ��������ĸ���У��ڶ��ֽⷨ�ǣ�ֻ�����Ӵ��е��ַ������ð��Ӵ���˳��ֻҪĸ�������Ӵ����ַ����ɡ�
bool IsAllCharExist(char *pShortString, char *pLongString)
{
	//if (text == '\0' || find == '\0')
		//return false;
	
	int pShortString_len = strlen(pShortString);
	int pLongString_len = strlen(pLongString);
	//if (text_len < find_len)
	//	return false;
	
	char *s = pLongString;
	char *p = s;
	char *q = pShortString;
	while (*p != '\0')
	{
		if (*p == *q)
		{
			p++;
			q++;
		}
		else
		{
			s++;
			p = s;
			q = pShortString;
		}
		if (*q == '\0')
		{
			return true;
		}
	}
	return false;
}

//������
bool IsAllCharExist2(string str1, string str2)
{
	int len1 = str1.size(), len2 = str2.size();
	map<char, int>map;
	for (int i = 0; i<len2; ++i)
		map[str2[i]] = 1;
	for (int i = 0; i<len1; ++i)
		if (map[str1[i]] != 1)return false;
	return true;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		char *p1 = NULL;
		char *p2 = NULL;
		p1 = &str1[0];
		p2 = &str2[0];
		
		bool ret;
		ret= IsAllCharExist(p1, p2);
		
		if (ret==true)
			cout <<"true"<<endl;
		else
			cout << "false"<<endl;
	}
	return 0;
}

