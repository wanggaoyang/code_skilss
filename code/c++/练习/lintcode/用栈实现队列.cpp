//用栈实现队列，此程序为用栈来实现队列的基本操作 
#include <iostream>
#include <stack>
using namespace std;

class Queue 
{
private:
	int size=0;
public:
    stack<int> stack1;
    stack<int> stack2;

    void Show()//显示元素数量 
	{
		cout<<"元素数量:"<<size<<endl; 
	} 
	void Size()//元素数量 
    {
    	size=0;	
	}
	Queue() 
    {
    // do intialization if necessary
            
    }

    void push(int element) 
    {
        // write your code here
        stack1.push(element);
        size++;
        cout<<"入队:"<<element<<endl; 
    }
    
    int pop() 
    {
        // write your code here
        size--;
		if (stack2.empty()) 
        {
            while (!stack1.empty()) 
            {
                 int elem = stack1.top();
                 stack1.pop();
                 stack2.push(elem);
            }
        }
        int elem = stack2.top();
        stack2.pop();
        cout<<"出队:"<<elem<<endl; 
        return elem;
    }

    int top() 
    {
        // write your code here
        if (stack2.empty()) 
        {
            while (!stack1.empty()) 
            {
                int elem = stack1.top();
                stack1.pop();
                stack2.push(elem);
            }
        }
        return stack2.top();
    }
};

int main()
{
	Queue A;
	A.push(1);
	A.push(2);
	A.push(3);
	A.push(4);
	A.push(5);
	
	A.Show();//显示元素数量 
	
	A.pop();
	A.pop();
	A.pop();
	A.pop();
	
	A.Show();//显示元素数量 

	
	
	return 0;
}

