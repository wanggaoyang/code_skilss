//最长无重复字符的子串,程序没有完全看清楚，但是思路是一致的
//通过使用map功能，依次读入string的每一位，每个char出现，就创建一个map[char,1];
//比如string="abca"，[a]=1,[b]=1,[c]=1,再出现[a]=1时，由于之前已经出现过了1，就发现了，之后再怎么处理是细节的事情。 
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
