//����˵������Ϊɾ��������ָ����Ԫ�أ�������������ϸ��ע 
 
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

void deleteNode(ListNode *node) //ɾ�������� 
{
    // write your code here
    ListNode *tmp = node->next;
	node->val=node->next->val;//˼·����ָ���ڵ����һ���ڵ�����ݸ�����ǰ�ڵ㣬�൱����������ͬ�Ľڵ��ˣ���ɾ����һ����㼴�� 
	node->next=node->next->next;
	
	delete tmp;//ɾ���¸����
	tmp=NULL;//��дҪ�淶 
}

ListNode *removeElements(ListNode *head, int val) 
{
	// Write your code here
    if(head==NULL)//��һ�������ͷ����ǿ�
    	return NULL;
    
	while(head->val==val)//�ڶ��������һ��ʼ��������n��Ҫɾ����Ԫ�أ�n>=1
    {
    	if(head->next==NULL)//�������ֻ��n��Ҫɾ��Ԫ�أ�ɾ��ֱ�ӷ���NULL
			return NULL;
		head=head->next;
	}
	//�����������������£�
	ListNode *pos=head;	//����һ�������α��ָ�룬�������Ԫ�أ�headָ�벻��
	while(pos->next!=NULL)
	{
		if((pos->next)->val==val)//����Ҫɾ����Ԫ�صĻ���ɾ�����ͷſռ�
		{
			ListNode *tmp;
			tmp=pos->next;
			pos->next=pos->next->next; //ָ�����¸�
			
			delete tmp;
			tmp=NULL;	
		}
		else
			pos=pos->next;
	} 
	return head;//��󷵻�����
} 

void print(ListNode *head) //������ʾ����
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
