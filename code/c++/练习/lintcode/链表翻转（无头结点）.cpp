//����˵�����˷�ת����С����Ϊ�ޱ�ͷ��������һ��headԪ�ؾ���Ϊ��������ĵ�һ��Ԫ����
//��֮ǰ��C�����б������ķ�ת����һ�������и��Ե����㣬���ַ�������һ�¡� 
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

ListNode *reverse(ListNode *head) //����ת 
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
    while(p->next!=NULL)      //�����ѭ��������p��ָ��Ԫ��һֱ�ǲ����  
    {  
        q=p->next;   
        p->next=q->next;   
        q->next=head->next;   
        head->next=q;   
    }   
    p->next=head;            //�൱�ڳɻ�   
    head=p->next->next;       //��head��Ϊԭhead��next   
    p->next->next=NULL;     //�ϵ���   
    return head;     
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
