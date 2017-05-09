//程序说明：此翻转链表小程序为无表头链表，即第一个head元素就作为整个链表的第一个元素了
//与之前用C语言中编的链表的反转程序不一样，各有各自的亮点，两种方法都看一下。 
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

ListNode *reverse(ListNode *head) //链表翻转 
{
    // write your code here
    if (head==NULL)
	{
        return NULL;
    }
    if(head->next==NULL)
    {
    	return head;	
	}
    ListNode *p,*q;    
    p=head->next;   
    while(p->next!=NULL)      //在这个循环过程中p所指的元素一直是不变的  
    {  
        q=p->next;   
        p->next=q->next;   
        q->next=head->next;   
        head->next=q;   
    }   
    p->next=head;            //相当于成环   
    head=p->next->next;       //新head变为原head的next   
    p->next->next=NULL;     //断掉环   
    return head;     
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
