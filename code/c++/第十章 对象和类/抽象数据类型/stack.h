#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX=10};
	Item items[MAX];
	int top;
	
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item) ;//新元素入栈，但不能对其内容进行修改 
	bool pop(Item & item) ;
};

#endif 
