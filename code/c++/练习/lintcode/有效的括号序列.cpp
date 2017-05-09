//��Ч���������У�һ����������Ե�Ӧ�þ����뵽��ʹ��ջ�ĸ���
//��c++�п���ֱ��ʹ��ģ���� stack,��Ӧ�ð�����ͷ�ļ�<stack> 
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    int match(char ch)  //ƥ�亯��������Ŷ��Ǹ�ֵ���ҷ��Ŷ�����ֵ 
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
        if (s.empty())  //����ַ���Ϊ�գ����ش���
            return false;
        stack<char> chStack;//����һ��ģ���࣬ջ
        for (int i=0;i<s.size();i++) //����һ������ַ��� 
        {  
            if (match(s[i]) < 0)  //���������ţ����ջ
            {  
                chStack.push(s[i]);  
            } 
            else if (match(s[i]) > 0) //������ҷ��ţ����ջ 
            {  
                if (chStack.empty()) //��ջǰ���ж��ǲ��ǿ���
                {  
                    return false;  
                }  
                if (match(chStack.top()) + match(s[i]) == 0) //ջ��Ԫ�غ͵�ǰ�ַ�����ָԪ������ƥ�� 
                {  
                    chStack.pop();  //����ܹ���ԣ��ٵ���
                } 
                else  //���򷵻ش���
                {  
                    return false;  
                }  
            }  
        }
        if (chStack.empty())//������ж�һ���ǲ���ջ���ˣ���ȫ������ˣ�  
        {  
            return true; //���˷��ض� 
        }  
        return false;//���շ��ش��� 
    }
};
