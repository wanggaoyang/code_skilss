//����ظ��ַ����Ӵ�,����û����ȫ�����������˼·��һ�µ�
//ͨ��ʹ��map���ܣ����ζ���string��ÿһλ��ÿ��char���֣��ʹ���һ��map[char,1];
//����string="abca"��[a]=1,[b]=1,[c]=1,�ٳ���[a]=1ʱ������֮ǰ�Ѿ����ֹ���1���ͷ����ˣ�֮������ô������ϸ�ڵ����顣 
#include <iostream>
#include <map>
#include <string>
using namespace std;


int lengthOfLongestSubstring(string s) 
{
    // write your code here
    int ret = 0;  
        map<char, int> m;  
        int start = 1;  
        for (int i = 1; i <= s.length(); i++)  
        {  
            char c = s[i - 1];  
            if (m[c] >= start)  
            {  
                start = m[c] + 1;  
                m[c] = i;  
  
            }  
            else  
            {  
                m[c] = i;  
                ret = max(ret, i - start + 1);  
            }  
  
        }  
        return ret;
}

int main()
{
	string begin="abca";
	int rel=lengthOfLongestSubstring(begin);
	cout<<rel;
	return 0;
} 
