//有效的括号序列，一看到这种配对的应该就能想到是使用栈的概念
//在c++中可以直接使用模板类 stack,但应该包括其头文件<stack> 
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    int match(char ch)  //匹配函数，左符号都是负值，右符号都是正值 
    {  
        switch (ch)  
        {  
        case '(':  
            return -1;  
        case ')':  
            return 1;  
        case '[':  
            return -2;  
        case ']':  
            return 2;  
        case '{':  
            return -3;  
        case '}':  
            return 3;  
        default:  
            break;  
        }  
        return 0;  
    }  
    bool isValidParentheses(string& s) 
    {
        // Write your code here
        if (s.empty())  //如果字符串为空，返回错误
            return false;
        stack<char> chStack;//定义一个模板类，栈
        for (int i=0;i<s.size();i++) //遍历一遍这个字符串 
        {  
            if (match(s[i]) < 0)  //如果是左符号，则进栈
            {  
                chStack.push(s[i]);  
            } 
            else if (match(s[i]) > 0) //如果是右符号，则出栈 
            {  
                if (chStack.empty()) //出栈前先判断是不是空了
                {  
                    return false;  
                }  
                if (match(chStack.top()) + match(s[i]) == 0) //栈顶元素和当前字符串所指元素正好匹配 
                {  
                    chStack.pop();  //如果能够配对，再弹出
                } 
                else  //否则返回错误
                {  
                    return false;  
                }  
            }  
        }
        if (chStack.empty())//最后在判断一下是不是栈空了，即全部配对了，  
        {  
            return true; //空了返回对 
        }  
        return false;//不空返回错误 
    }
};
