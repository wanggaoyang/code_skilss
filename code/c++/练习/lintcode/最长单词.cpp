//������ܣ� �Ƚ������dictionary�ڵ��ַ�������ȫ����¼������length�У�������ҳ���ĳ��ȼ�Ϊmax��
//�ٱ���һ�飬��������Щֵ����max,ֱ�ӽ�����dictionary�ж�Ӧ�±���ַ�������result�����в����ء� 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void longestWords(vector<string> &dictionary)
    {
        int size=dictionary.size();
		int i=0;
		vector <int> length;//��ʼ��һ������±������
		vector <string> result;//��ʼ��һ����Ž��������
		
		for(;i<size;i++)//�ȼ�¼����dictionary��ÿ��Ԫ�صĳ��� 
		{
			length.push_back(dictionary[i].size()); 
		} 

		int max=0;
		for(int i=0;i<size;i++)
		{
			if(length[i]>=max)
				max=length[i];		
		}
		cout<<"��󳤶�:"<<max<<endl;
		
		for(int i=0;i<size;i++)
		{
			if(length[i]==max)
				result.push_back(dictionary[i]);		
		}
		
		cout<<"��󳤶ȵ��ַ����У�"<<endl;	
		for(int i=0;i<result.size();i++)
			cout<<result[i]<<endl;
    }

int main()
{
	vector <string> a;
	a.push_back("dog");
	a.push_back("google");
	a.push_back("facebook");
	a.push_back("internationalization");
	a.push_back("blabla");
	
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<endl;
	
	longestWords(a);
	
	
/*	Solution p;
	vector <string> b;
	b=p.longestWords(a);*/
	return 0;
}
