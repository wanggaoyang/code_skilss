#include<iostream>
#include<string>
using namespace std;
//˵�����ں�����ʵ���У�������ģ������Ӵ���5����ֻ��һ�������ҳ���Ϊ4�ģ������������ϼ�С�Ӵ��ĳ��Ƚ��в��ҡ�
//��Ҫ�����У�substr,find.
void findCommon(string a, string b) //aΪ���ַ�����bΪ���ַ���
{
	unsigned int len_a = a.length(), len_b = b.length();//���ַ����ĳ���
	unsigned int maxlen = 0;//������ַ����ĳ���
	unsigned int maxindex = 0; //������ַ��������һ���ַ���λ��
	for (unsigned int i = b.length() - 1; i>1; i--)
	{
		for (unsigned int j = 0; j <= b.length() - i; j++)
		{
			string temp;
			int t = 0;
			temp = b.substr(j, i);
			t = a.find(temp);
			if ((t != -1) && (maxlen<temp.length()))//ƥ��ɹ��������бȽ�
			{
				maxlen = temp.length();
				maxindex = i + j;
			}

		}
	}
	cout << b.substr(maxindex - maxlen, maxlen) << endl;
}

int main()
{
	char *str1 = "helloworlddadada";
	char *str2 = "llo";
	char *ret = NULL;
	if (strstr(str1, str2) != NULL)
	{
		ret = strstr(str1, str2);
		cout << ret << endl;
	}

	string str3 = "hello world";
	string str4 = "worlsd";
	int t = str3.find(str4);
	cout << t << endl;

	string str5 = "helloworldibabyhiman";
	string str6 = "llororbaby";
	findCommon(str5,str6);
	return 0;
}