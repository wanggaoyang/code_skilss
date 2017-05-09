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
	vector<string> save;//���ڴ洢��׺ת��׺��� 
	stack <string>  st; //�洢���ű��� 
	stack <int>    st2;//�洢���ս�� 
	map<string,int> level;//ӳ�䣬ʹ+-*/���������ȼ��ж�Ӧ��ϵ 
		
public: 
	/*string_to_int����*/ //stringתint 
	int str_to_int(string & str)
	{
		return atoi(str.c_str());	
	}
	
	/*���ȼ����庯��*/
	void init()//Ϊʲôֻ�ܶ����ں���� 
	{
		
		level["+"]=1;  
		level["-"]=1;  
	         
	    level["*"]=2;  
	    level["/"]=2;  
	         
	    level["("]=3;  
	}

	/*��׺���ʽת��׺���ʽ����*/
	void transform(vector<string> &expression)
	{
		if(expression.size()==0)
			return;
			
		int i=0;
	
		while(i<expression.size())//�������ַ�����û������� 
		{
			if(expression[i]>="0"&&expression[i]<="999")//������ʱ ,  ������������������һ�����⣬�ַ����ȴ�С�ȵ���ʲô�� 
				save.push_back(expression[i]);//ֱ�Ӵ������� 
			
			else if(expression[i]=="+"||expression[i]=="-"||expression[i]=="*"||expression[i]=="/")//�Ƿ���ʱ 
			{
				while(!st.empty()&&level[expression[i]]<=level[st.top()]&&st.top()!="(")//��ջ�����Ž������ȼ��Ƚ�
				{//��������������жϣ����գ����ȼ����ʹ�ʱջ��Ԫ�ز���Ϊ������ջ��Ԫ��Ϊ������ֱ�ӽ��䵯������Ϊ�����ܳ�����save������  
					save.push_back(st.top());//ջ��Ԫ�����ȼ��ߵĻ��Ƚ�ջ��Ԫ���������� 
					st.pop();	//�ٴ�ջ�е��� 
				} 
				st.push(expression[i]);//����expression[i]��ջ 	
			}
			else if(expression[i]=="(")
				st.push(expression[i]);//������ֱ�ӽ�ջ
			else if(expression[i]==")")
			{ 
				while(!st.empty()&&st.top()!="(")
				{
					save.push_back(st.top());//ջ��Ԫ�������� 
					st.pop(); //�󵯳� 
				}
				st.pop(); //ֱ�ӵ���  
			} 
			else 
			{
				cout<<"error!"<<endl;
				break;
			} 
			i++;							
		}
		while(!st.empty())//�����ʽ������� 
	    {
			save.push_back(st.top());//ջ��Ԫ��������
			st.pop(); //�󵯳�
	        
	    }
		for(int k=0;k<save.size();k++)
			cout<<save[k];	
	} 

	/*������㺯��*/
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
			
	/*ʹ�ú���*/
	int evaluateExpression(vector<string> &expression) 
	{
	    // write your code here
	    init();//�������Ҫ��ִ�а�����Ȼ������ȼ�˭֪���� 
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
