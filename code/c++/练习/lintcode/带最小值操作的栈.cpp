//����Сֵ������ջ
#include <iostream>
#include <stack>
using namespace std;

class MinStack 
{    
public:
    	stack<int>  data;  
    	stack<int>  mins; 
		MinStack() 
	    {
	        // do initialization if necessary
	    }

	    void push(int number) 
	    {
	        // write your code here
	        data.push(number);  
	        cout<<"���:"<<number<<endl;
			if (mins.size() ==0 || mins.top() >=number)//ջ��û������������ǵ�һ��Ԫ�ص�ʱ�򣬻���Ŀǰminsջ����Ԫ�ر�Ҫ����Ĵ�ʱ�� 
			{  
	            mins.push(number);  //��Ԫ����ջ
				cout<<"��ǰ��СԪ��:"<<mins.top()<<endl;
	        }  
	        else 
			{  
	            mins.push(mins.top());  //��������һ��Ԫ�صĸ��� 
	    	}
		}
    
		int pop() 
		{
	        // write your code here
			int temp=data.top();
			data.pop();
			mins.pop();
			cout<<"��ջԪ�أ�"<<temp<<endl;
	    }
	
	    int min() 
		{
	        // write your code here
	        return mins.top();
	        cout<<"������СԪ�أ�"<<mins.top()<<endl;
	    }
};

int main()
{
	MinStack A;
	A.push(1);
	A.pop();
	A.push(2);
	A.push(3);
	A.push(2);
	
	A.min();
	A.push(1);
	A.min();
	
	//��ʾԪ������ 

	return 0;
}

