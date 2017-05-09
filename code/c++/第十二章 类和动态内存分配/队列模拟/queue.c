#include "queue.h"
#include <cstdlib>

/*�˿��෽������*/ 
void Customer::set(long when)
{
	processtime=std::rand()%3+1;//�趨����ʱ�� 
	arrive=when;//�趨����ʱ�� 
} 

/*�����෽������*/ 
Queue::Queue(int qs) : qsize(qs)//qsizeΪconst���ͣ������ڹ��캯���ڲ���ʼ�� 
{
	front=rear=NULL;
	items=0;
} 

Queue::~Queue()//�������� 
{
	Node *temp;
	while(front !=NULL)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}

bool Queue::isempty() const//�ӿ� 
{
	return items==0;
} 

bool Queue::isfull() const//���� 
{
	return items==qsize;
} 

int Queue::queuecount() const//��ȡ������Ԫ������ 
{
	return items;
} 

bool Queue::enqueue(const Item & item)//��� 
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

bool Queue::dequeue(Item & item)//���� 
{
	if(front==NULL)
		return false;
	item=front->item;//��������������Ƕ��еĳ�Ա���� 
	items--;
	Node *temp=front;//��ɾ����Ԫ��һ����ʱ�洢�ռ�(λ��)������֮��ɾ������ڵ� 
	front=front->next;
	delete temp;//ɾ���ڵ� 
	if(items==0)
		rear=NULL;
	return true;
}


