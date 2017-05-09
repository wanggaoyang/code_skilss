#include <iostream>
#include <string>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
};

ListNode * LinkList_Create()//链表创建函数 
{ 
	ListNode * head=new ListNode;//创建了一个指向头结点数据结构的指针，并为头结点分配空间
	
	if(head!=NULL)
	{
		head->val=0;          //头结点长度为0
		head->next=NULL;   //头结点指针指向空
	}
	return head;//将头结点返回
}
		
void LinkList_Destroy(ListNode * head) // 销毁链表函数
{
    delete(head);
}
	
void LinkList_Length(ListNode * head) // 查询链表长度函数
{
    ListNode * sList = head;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->val;
    }
    cout<<"元素数量: "<<sList->val<<endl;
}

void LinkList_Print(ListNode * head) //链表显示函数
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

ListNode * LinkList_GetNode(ListNode * head,int i)//结点的查找函数 
{//在带头结点的单链表head中查找第i个结点，若找到（0≤i≤n），
 //则返回该结点的存储位置，否则返回NULL。
    int j;
    ListNode * p;
    p=head;j=0;//从头结点开始扫描
    while(p->next&&j<i)
	{//顺指针向后扫描，直到p->next为NULL或i=j为止
        p=p->next;
        j++;
    }
    if(i==j)
    	return p;//找到了第i个结点
    	else return NULL;//当i<0或i>0时，找不到第i个结点
} 

void LinkList_Insert(ListNode * head,int x,int i)//将新结点插入函数 
{//将值为x的新结点插入到带头结点的单链表head的第i个结点的位置上
	ListNode * current;
    current=LinkList_GetNode(head,i-1);//寻找第i-1个结点
    if (current==NULL)//i<1或i>n+1时插入位置i有错
        cout<<"error"<<endl;
    	ListNode * insert=new ListNode;
        insert->val=x;insert->next=current->next;current->next=insert;
        head->val++;
}    

void LinkList_Delete(ListNode * head,int pos)//删除pos位置的结点 
{
    ListNode * current;
    if(pos>=head->val)
    {	
		cout<<"超过长度，默认删除最后一个元素"<<endl;
    	pos=head->val;
    } 
	current=LinkList_GetNode(head,pos-1);//寻找pos前一个结点
    if (current==NULL)//i<1或i>n+1时插入位置i有错
        cout<<"error"<<endl;
    	current->next=(current->next)->next;
        head->val--;
} 

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    // write your code here
    ListNode * aim=NULL;
	ListNode * a_point=headA->next;//都从实际元素开始 
	ListNode * b_point=headB->next;//都从实际元素开始 

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

int main()
{
	ListNode * head1=LinkList_Create();
	ListNode * head2=LinkList_Create();
	
	int i=0;
	int j=0;
	int p=0;int q=0;
	int l=0;
	int n=0;int m=0;
	
	printf("请输入链表1中元素数量：\n");
	scanf("%d",&j);
	for(i=1;i<=j;i++)
	{
		printf("请输入第%d个元素:",i);
		scanf("%d",&p);
		LinkList_Insert(head1,p,i);//链表中插入结点 
	}	
	
	printf("请输入链表2中元素数量：\n");
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		printf("请输入第%d个元素:",i);
		scanf("%d",&q);
		LinkList_Insert(head2,q,i);//链表中插入结点 
	}
	
	printf("链表1中元素：");
	LinkList_Print(head1);
	printf("\n链表1长度:%d\n",head1->val);
	
	printf("链表2中元素：");
	LinkList_Print(head2);
	printf("\n链表2长度:%d\n",head2->val);
	
	ListNode *ret=getIntersectionNode(head1,head2) ;
	cout<<"重复元素为："<<ret->val;
	 
	
	
	LinkList_Destroy(head1);
	LinkList_Destroy(head2);
}
