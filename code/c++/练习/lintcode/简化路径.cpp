//简化路径程序，网上的程序，对内容里/./..的不同点还不是很清楚。 
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string& path) 
{
    // Write your code here
	stack<string> st;  
    string cur = "";  
    path+="/";  
    for(int i=0;i<path.length();i++)  
    {  
        if(path[i]=='/')  
        {  
            if(cur=="..")  
            {  
                if(!st.empty())  
                    st.pop();  
            }  
            else if(cur=="."){}  
            else if(cur.length()>0)  
            {  
                st.push(cur);  
            }  
            cur = "";  
        }  
        else  
            cur+=path[i];  
    }  
    string ret = "";  
    while(!st.empty())  
    {  
        ret = "/"+st.top()+ret;  
        st.pop();  
    }  
    if(ret.length()==0)  
        ret = "/";  
    return ret;  
}

int main()
{
	string str="/a/./b/../../c/";
	string str2=simplifyPath(str);
	cout<<str2<<endl; 
	return 0;
}
