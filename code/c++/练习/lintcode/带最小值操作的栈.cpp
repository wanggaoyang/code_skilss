//带最小值操作的栈
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
	        cout<<"入队:"<<number<<endl;
			if (mins.size() ==0 || mins.top() >=number)//栈中没东西，即存的是第一个元素的时候，或者目前mins栈顶的元素比要传入的大时： 
			{  
	            mins.push(number);  //新元素入栈
				cout<<"当前最小元素:"<<mins.top()<<endl;
	        }  
	        else 
			{  
	            mins.push(mins.top());  //否则传入上一个元素的复制 
	    	}
		}
    
		int pop() 
		{
	        // write your code here
			int temp=data.top();
			data.pop();
			mins.pop();
			cout<<"出栈元素："<<temp<<endl;
	    }
	
	    int min() 
		{
	        // write your code here
	        return mins.top();
	        cout<<"最终最小元素："<<mins.top()<<endl;
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
	
	//显示元素数量 

	return 0;
}

