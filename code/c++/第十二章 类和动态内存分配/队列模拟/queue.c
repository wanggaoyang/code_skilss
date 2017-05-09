#include "queue.h"
#include <cstdlib>

/*顾客类方法定义*/ 
void Customer::set(long when)
{
	processtime=std::rand()%3+1;//设定交易时间 
	arrive=when;//设定到达时间 
} 

/*队列类方法定义*/ 
Queue::Queue(int qs) : qsize(qs)//qsize为const类型，不能在构造函数内部初始化 
{
	front=rear=NULL;
	items=0;
} 

Queue::~Queue()//析构函数 
{
	Node *temp;
	while(front !=NULL)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}

bool Queue::isempty() const//队空 
{
	return items==0;
} 

bool Queue::isfull() const//队满 
{
	return items==qsize;
} 

int Queue::queuecount() const//获取队列中元素数量 
{
	return items;
} 

bool Queue::enqueue(const Item & item)//入队 
{
	if(isfull())
		return false;
	Node *add=new Node;
	add->item=item;
	add->next=NULL;
	items++; 
	if(front==NULL)
		front=add;
	else
		rear->next=add;
	rear=add;
	return true;
}

bool Queue::dequeue(Item & item)//出队 
{
	if(front==NULL)
		return false;
	item=front->item;//这个函数本来就是队列的成员函数 
	items--;
	Node *temp=front;//给删除的元素一个临时存储空间(位置)，便于之后删除这个节点 
	front=front->next;
	delete temp;//删除节点 
	if(items==0)
		rear=NULL;
	return true;
}


