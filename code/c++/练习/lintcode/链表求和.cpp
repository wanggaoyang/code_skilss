//������ͳ��򣬵����ڱ���������û�кͳ�����ݣ��õĻ����Ե���һ�� 
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
	cout<<head->val<<endl;
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


ListNode *reverse(ListNode *head) //��ת���� 
{
    // write your code here
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
	ListNode *current=head->next;  //�Ȱѱ�ͷ��ȥ��������Ԫ�صķ�ת 
    ListNode *p,*q;    
    p=current->next;   
    while(p->next!=NULL)      //�����ѭ��������p��ָ��Ԫ��һֱ�ǲ����  
    {  
        q=p->next;   
        p->next=q->next;   
        q->next=current->next;   
        current->next=q;   
    }   
    p->next=current;            //�൱�ڳɻ�   
    current=p->next->next;       //��head��Ϊԭhead��next   
    p->next->next=NULL;     //�ϵ���  
	
	head->next=current;//�ٰ�ͷ�����ϣ������� 
    return head; 
}

ListNode *reverseBetween(ListNode *head, int m, int n) //��ת������ǿ�棬���ϵķ����� 
{
    //�����ӣ���ȥ����ͷ
	ListNode *new_head=head->next;
	if (new_head == NULL || m > n) 
    {
        return NULL;
    }

        //ListNode *dummy = new ListNode(0);//���������һ����ͷ��ָ���һ����㣬������λ
        ListNode *dummy = new ListNode;
        dummy->next = new_head;//ͬ�� 
        ListNode *node = dummy;//�µ�ͷ����Ϊ  node 

        for (int i = 1; i != m; ++i) //��node����Ƶ�m��ǰһ����� 
        {
            if (node == NULL) 
            {
                return NULL;
            } 
            else 
            {
                node = node->next;
            }
        }

        ListNode *premNode = node;
        ListNode *mNode = node->next;//mNode��λ��һֱָ��ԭ�������еĵ�m��Ԫ�� 
        ListNode *nNode = mNode, *postnNode = nNode->next;
        for (int i = m; i != n; ++i) //��m��n�Ľ����е��� 
        {
            if (postnNode == NULL) 
            {
                return NULL;
            }

            ListNode *temp = postnNode->next;
            postnNode->next = nNode;
            nNode = postnNode;//nNodeÿ�������ƶ�һ����㣬ֱ��ָ����n���������ƶ� 
            postnNode = temp;
        }
        premNode->next = nNode;//ԭ�Ȳ�����ͷ������������µ�ͷ��� 
        mNode->next = postnNode;//������β�ڵ����ʣ��û��������Ľڵ��� 

        head->next= dummy->next;//���Ǹ����ҵĳ�������Ľṹ�ĵģ�ԭ������ 
		return head;
		//return dummy->next;
    }

ListNode *reverseBetween2(ListNode *head,int m, int n) //��ת������ǿ�棬����������һ�û��ͨ�� 
{
    // write your code here
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
	ListNode *current=head->next;  //�Ȱѱ�ͷ��ȥ��������Ԫ�صķ�ת 
    
	ListNode *newhead=current;//����һ���µı�ͷ 
	for(int k=0;k<m-2;k++)
	{
		newhead=newhead->next;		
	} 
	ListNode *p,*q;
	   
    p=newhead->next;   
    
	if(m==1)
	{
		for(int a=0;a<n-m-1;a++)      //�����ѭ��������p��ָ��Ԫ��һֱ�ǲ����  
		{  
		    q=p->next;   
		    p->next=q->next;   
		    q->next=newhead->next;   
		    newhead->next=q;   
		} 	
	}
	else
	{
		for(int a=0;a<n-m;a++)      //�����ѭ��������p��ָ��Ԫ��һֱ�ǲ����  
	    {  
	        q=p->next;   
	        p->next=q->next;   
	        q->next=newhead->next;   
	        newhead->next=q;   
	    } 
	} 
	
    
	if(m==1)
	{
		ListNode *temp=newhead->next; 
		newhead->next=p->next;  //�൱�ڳɻ�   
		p->next=newhead;       //��head��Ϊԭhead��next   
    	newhead=temp;     
	}    	
	 
	else if(current!=newhead)
	{
		current->next=newhead;
	}
		
	
	head->next=current;//�ٰ�ͷ�����ϣ������� 
    return head; 
}
ListNode *addLists(ListNode *l1, ListNode *l2) 
{
// write your code here
	ListNode *dummy = new ListNode(0);//�½�һ������ͷ�����ڴ洢֮��Ľ�� 
    ListNode *curr = dummy;
    int carry = 0;

    while ((l1 != NULL) || (l2 != NULL) || (carry != 0)) //ֻҪ��һ��û�е��յ㣬��������������յ��ˣ�����carry����һ����λ��ҲҪ�ټ� 
    {//һ����㣬д��1�� 
        int l1_val = (l1 != NULL) ? l1->val : 0;//˭û���յ�Ͱ�˭��ֵ�ó����������ڼ���ʱ����0��ʾ 
        int l2_val = (l2 != NULL) ? l2->val : 0;
        int sum = carry + l1_val + l2_val;
        // update carry
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);

        curr = curr->next;
        if (l1 != NULL) l1 = l1->next;//˭û���յ�˭��������һ�� 
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy->next;
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
	
	ListNode * newhead=reverseBetween(head,1,4); 
	LinkList_Print(newhead);
	
	LinkList_Destroy(head);
	return 0;
	
}
