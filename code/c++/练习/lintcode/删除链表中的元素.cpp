//程序说明：此为删除链表中指定的元素，方法见下面详细标注 
 
#include <iostream>
using namespace std;

class ListNode 
{
 public:
    int val;
    ListNode *next;
    ListNode(int val) 
	{
         this->val = val;
         this->next = NULL;
    }
};

void deleteNode(ListNode *node) //删除链表结点 
{
    // write your code here
    ListNode *tmp = node->next;
	node->val=node->next->val;//思路：把指定节点的下一个节点的内容赋给当前节点，相当于有两个相同的节点了，再删除下一个结点即可 
	node->next=node->next->next;
	
	delete tmp;//删除下个结点
	tmp=NULL;//书写要规范 
}

ListNode *removeElements(ListNode *head, int val) 
{
	// Write your code here
    if(head==NULL)//第一种情况，头结点是空
    	return NULL;
    
	while(head->val==val)//第二种情况，一开始就是连续n个要删除的元素，n>=1
    {
    	if(head->next==NULL)//如果链中只含n个要删的元素，删完直接返回NULL
			return NULL;
		head=head->next;
	}
	//最后的情况，正常情况下：
	ListNode *pos=head;	//创建一个类似游标的指针，负责遍历元素，head指针不变
	while(pos->next!=NULL)
	{
		if((pos->next)->val==val)//是需要删除的元素的话就删掉，释放空间
		{
			ListNode *tmp;
			tmp=pos->next;
			pos->next=pos->next->next; //指向下下个
			
			delete tmp;
			tmp=NULL;	
		}
		else
			pos=pos->next;
	} 
	return head;//最后返回链表
} 

void print(ListNode *head) //链表显示函数
{
	ListNode* current=head->next;
	int i=0;
	while(current!=NULL) 
	{
		printf("%d ",current->val);
		current=current->next;
	}
}

int main()
{
	ListNode one(1);
	
	return 0;
}
