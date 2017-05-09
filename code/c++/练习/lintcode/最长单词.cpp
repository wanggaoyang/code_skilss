//程序介绍： 先将传入的dictionary内的字符串长度全部记录到向量length中，后遍历找出最长的长度记为max。
//再遍历一遍，看看有哪些值等于max,直接将向量dictionary中对应下标的字符串存入result向量中并返回。 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void longestWords(vector<string> &dictionary)
    {
        int size=dictionary.size();
		int i=0;
		vector <int> length;//初始化一个存放下标的向量
		vector <string> result;//初始化一个存放结果的向量
		
		for(;i<size;i++)//先记录向量dictionary里每个元素的长度 
		{
			length.push_back(dictionary[i].size()); 
		} 

		int max=0;
		for(int i=0;i<size;i++)
		{
			if(length[i]>=max)
				max=length[i];		
		}
		cout<<"最大长度:"<<max<<endl;
		
		for(int i=0;i<size;i++)
		{
			if(length[i]==max)
				result.push_back(dictionary[i]);		
		}
		
		cout<<"最大长度的字符串有："<<endl;	
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
