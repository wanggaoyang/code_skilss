#include <iostream>
#include <string>
using namespace std;

void find_the_first(string str)//�ܻ��ǣ��Լ���ġ�
{
	int ret = -1;
	int length = str.length();
	int mask[200] = { 0 };
	for (int i=0; i < length; i++)//����Ӧ���ַ�ת��ACSII��ֵ����Ϊ������±��������ÿ����һ�Σ������ж�Ӧ��һ��
	{
		mask[(int)str[i]]++;
	}
	for (int k = 0; k < length; k++)//��ȥ����һ�飬ֻ��������1��ֵ���ǵĻ�ֱ�������
	{
		if (mask[(int)str[k]] == 1)
		{
			cout << str[k]<< endl;
			ret = 1;
			return ;
		}
	}
	cout << -1<< endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		find_the_first(str);
	}
	
	
	return 0;
}