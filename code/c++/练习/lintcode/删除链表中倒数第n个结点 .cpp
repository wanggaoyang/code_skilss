//��������ɾ�������е�����n���ڵ㣬��������Ŀ�е�һ����ֻ����Щ��ʾ��ϸ�ڣ������ڽṹ���У���ͷ��㣬��Ŀ���� 
#include <iostream>
#include <string>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
};

ListNode * LinkList_Create()//���������� 
{ 
	ListNode * head=new ListNode;//������һ��ָ��ͷ������ݽṹ��ָ�룬��Ϊͷ������ռ�
	
	if(head!=NULL)
	{
		head->val=0;          //ͷ��㳤��Ϊ0
		head->next=NULL;   //ͷ���ָ��ָ���
	}
	return head;//��ͷ��㷵��
}
		
void LinkList_Destroy(ListNode * head) // ����������
{
    delete(head);
}
	
void LinkList_Length(ListNode * head) // ��ѯ�����Ⱥ���
{
    ListNode * sList = head;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->val;
    }
    cout<<"Ԫ������: "<<sList->val<<endl;
}

void LinkList_Print(ListNode * head) //������ʾ����
{
	ListNode * current=head->next;
	int length=0;
	length=head->val;
	int i=0;
	while(current!=NULL) 
	{
		for(i=0;i<length;i++)
		{
			cout<<current->val<<" ";
			current=current->next;
		}
	}
}

ListNode * LinkList_GetNode(ListNode * head,int i)//���Ĳ��Һ��� 
{//�ڴ�ͷ���ĵ�����head�в��ҵ�i����㣬���ҵ���0��i��n����
 //�򷵻ظý��Ĵ洢λ�ã����򷵻�NULL��
    int j;
    ListNode * p;
    p=head;j=0;//��ͷ��㿪ʼɨ��
    while(p->next&&j<i)
	{//˳ָ�����ɨ�裬ֱ��p->nextΪNULL��i=jΪֹ
        p=p->next;
        j++;
    }
    if(i==j)
    	return p;//�ҵ��˵�i�����
    	else return NULL;//��i<0��i>0ʱ���Ҳ�����i�����
} 

void LinkList_Insert(ListNode * head,int x,int i)//���½����뺯�� 
{//��ֵΪx���½����뵽��ͷ���ĵ�����head�ĵ�i������λ����
	ListNode * current;
    current=LinkList_GetNode(head,i-1);//Ѱ�ҵ�i-1�����
    if (current==NULL)//i<1��i>n+1ʱ����λ��i�д�
        cout<<"error"<<endl;
    	ListNode * insert=new ListNode;
        insert->val=x;insert->next=current->next;current->next=insert;
        head->val++;
}    

void LinkList_Delete(ListNode * head,int pos)//ɾ��posλ�õĽ�� 
{
    ListNode * current;
    if(pos>=head->val)
    {	
		cout<<"�������ȣ�Ĭ��ɾ�����һ��Ԫ��"<<endl;
    	pos=head->val;
    } 
	current=LinkList_GetNode(head,pos-1);//Ѱ��posǰһ�����
    if (current==NULL)//i<1��i>n+1ʱ����λ��i�д�
        cout<<"error"<<endl;
    	current->next=(current->next)->next;
        head->val--;
} 

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) //�õ���������ĵ�һ�������� 
{
    // write your code here
    ListNode * aim=NULL;
	ListNode * a_point=headA->next;//����ʵ��Ԫ�ؿ�ʼ 
	ListNode * b_point=headB->next;//����ʵ��Ԫ�ؿ�ʼ 

    if(a_point==NULL||b_point==NULL)
    	return NULL;
    for(;a_point!=NULL;a_point=a_point->next)
    {
    	for(b_point=headB;b_point!=NULL;b_point=b_point->next)
    	{
    		if(a_point->val==b_point->val)
    		{
    			aim=a_point;
    			return aim;
    		}
    	}	
    }
    return NULL;
}

ListNode *removeNthFromEnd(ListNode *head, int n) //ɾ�������е�����n����� 
{
    // write your code here
	if(head==NULL)
		return NULL;
	int count=0;
	ListNode * current=head->next;
	for(;current!=NULL;)
	{
		count++;
		current=current->next;
	}
	cout<<count<<endl;
	
	current=head;
//	if(count!=n)
//	{
		for(int i=0;i<count-n;i++)
		{
			current=current->next;	
		}
		ListNode *temp=current->next;
		current->next=current->next->next;
		delete temp;
		temp=NULL;
//	}
/*	else
	{
		ListNode *temp2=head;
		head=head->next;
		delete temp2;
		temp2=NULL;
	}*/  //��������жϲ�Ҫ�ˣ���Ϊ�����head�Ǵ��������Ϣ�ģ�����Ŀ��Ĳ�һ���� 
	head->val--;//��Ŀ��Ҳ��Ҫ��һ���ˡ� 
	return head;
	
}

int main()
{
	ListNode * head=LinkList_Create();
	
	int i=0;
	int j=0;
	int p=0;
	int l=0;
	int n=0;
	
	printf("������������Ԫ��������\n");
	scanf("%d",&j);
	for(i=1;i<=j;i++)
	{
		printf("�������%d��Ԫ��:",i);
		scanf("%d",&p);
		LinkList_Insert(head,p,i);//�����в����� 
	}	

	printf("������Ԫ�أ�");
	LinkList_Print(head);
	printf("\n������:%d\n",head->val);
	
	ListNode * result=removeNthFromEnd(head,2);
	LinkList_Print(result);
	
	LinkList_Destroy(head);
	return 0;
	
}
