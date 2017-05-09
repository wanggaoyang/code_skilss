#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <stdlib.h>
using namespace std;

class Solution 
{  
private:
	vector<string> save;//用于存储中缀转后缀结果 
	stack <string>  st; //存储符号变量 
	stack <int>    st2;//存储最终结果 
	map<string,int> level;//映射，使+-*/符号与优先级有对应关系 
		
public: 
	/*string_to_int函数*/ //string转int 
	int str_to_int(string & str)
	{
		return atoi(str.c_str());	
	}
	
	/*优先级定义函数*/
	void init()//为什么只能定义在函数里？ 
	{
		
		level["+"]=1;  
		level["-"]=1;  
	         
	    level["*"]=2;  
	    level["/"]=2;  
	         
	    level["("]=3;  
	}

	/*中缀表达式转后缀表达式函数*/
	void transform(vector<string> &expression)
	{
		if(expression.size()==0)
			return;
			
		int i=0;
	
		while(i<expression.size())//当整个字符串还没输入结束 
		{
			if(expression[i]>="0"&&expression[i]<="999")//是数字时 ,  ！！！！！这里遗留一个问题，字符串比大小比的是什么？ 
				save.push_back(expression[i]);//直接存入向量 
			
			else if(expression[i]=="+"||expression[i]=="-"||expression[i]=="*"||expression[i]=="/")//是符号时 
			{
				while(!st.empty()&&level[expression[i]]<=level[st.top()]&&st.top()!="(")//与栈顶符号进行优先级比较
				{//这里包含了三个判断，不空，优先级，和此时栈顶元素不能为（，若栈顶元素为（，则直接将其弹出，因为（不能出现在save向量中  
					save.push_back(st.top());//栈顶元素优先级高的话先将栈顶元素入向量， 
					st.pop();	//再从栈中弹出 
				} 
				st.push(expression[i]);//再让expression[i]进栈 	
			}
			else if(expression[i]=="(")
				st.push(expression[i]);//左括号直接进栈
			else if(expression[i]==")")
			{ 
				while(!st.empty()&&st.top()!="(")
				{
					save.push_back(st.top());//栈顶元素入向量 
					st.pop(); //后弹出 
				}
				st.pop(); //直接弹出  
			} 
			else 
			{
				cout<<"error!"<<endl;
				break;
			} 
			i++;							
		}
		while(!st.empty())//当表达式输入结束 
	    {
			save.push_back(st.top());//栈顶元素入向量
			st.pop(); //后弹出
	        
	    }
		for(int k=0;k<save.size();k++)
			cout<<save[k];	
	} 

	/*结果计算函数*/
	int calculate()
	{
		cout<<endl;
		int i=0;
		if(save.size()==0)
			return 0;
		while(i<save.size())
		{
			if(save[i]<="999"&&save[i]>="0")
			{  
	            st2.push(str_to_int(save[i]));
				i++; 
	            continue;  
	        }
			int a=st2.top();  
            st2.pop();  
            int b=st2.top();  
            st2.pop();  
            if(save[i]=="+")  
                st2.push(b+a);  
            else if(save[i]=="-")  
                st2.push(b-a);  
            else if(save[i]=="*")  
                st2.push(b*a);  
            else  
                st2.push(b/a);
			i++;   
        }  
        return st2.top();   	
	}
			
	/*使用函数*/
	int evaluateExpression(vector<string> &expression) 
	{
	    // write your code here
	    init();//这个函数要先执行啊，不然你的优先级谁知道！ 
		transform(expression);
	    int rel=calculate();
	    return rel;
	}
};

int main()
{
	Solution ali;
	vector<string> hibabe;
	hibabe.push_back("2");
	hibabe.push_back("*");
	hibabe.push_back("6");
	hibabe.push_back("-");
	hibabe.push_back("(");
	hibabe.push_back("23");
	//hibabe.push_back("2");
	hibabe.push_back("+");
	hibabe.push_back("7");
	hibabe.push_back(")");
	hibabe.push_back("/");
	hibabe.push_back("(");
	hibabe.push_back("1");
	hibabe.push_back("+");
	hibabe.push_back("2");
	hibabe.push_back(")");
	int result=ali.evaluateExpression(hibabe);
	cout<<endl<<"result: "<<result<<endl;
	return 0;
}
