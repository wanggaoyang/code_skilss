//链表求和程序，但是在本例子里面没有和程序兼容，用的话可以调节一下 
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


ListNode *reverse(ListNode *head) //翻转链表 
{
    // write your code here
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
	ListNode *current=head->next;  //先把表头给去掉，进行元素的反转 
    ListNode *p,*q;    
    p=current->next;   
    while(p->next!=NULL)      //在这个循环过程中p所指的元素一直是不变的  
    {  
        q=p->next;   
        p->next=q->next;   
        q->next=current->next;   
        current->next=q;   
    }   
    p->next=current;            //相当于成环   
    current=p->next->next;       //新head变为原head的next   
    p->next->next=NULL;     //断掉环  
	
	head->next=current;//再把头给加上，并返回 
    return head; 
}

ListNode *reverseBetween(ListNode *head, int m, int n) //翻转链表（加强版，网上的方法） 
{
    //老样子，先去掉表头
	ListNode *new_head=head->next;
	if (new_head == NULL || m > n) 
    {
        return NULL;
    }

        //ListNode *dummy = new ListNode(0);//是这里添加一个表头，指向第一个结点，用于移位
        ListNode *dummy = new ListNode;
        dummy->next = new_head;//同上 
        ListNode *node = dummy;//新的头结点称为  node 

        for (int i = 1; i != m; ++i) //将node结点移到m的前一个结点 
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
        ListNode *mNode = node->next;//mNode的位置一直指着原来队列中的第m个元素 
        ListNode *nNode = mNode, *postnNode = nNode->next;
        for (int i = m; i != n; ++i) //将m到n的结点进行倒序 
        {
            if (postnNode == NULL) 
            {
                return NULL;
            }

            ListNode *temp = postnNode->next;
            postnNode->next = nNode;
            nNode = postnNode;//nNode每次往后移动一个结点，直到指到第n个结点结束移动 
            postnNode = temp;
        }
        premNode->next = nNode;//原先不动的头结点接上逆序后新的头结点 
        mNode->next = postnNode;//逆序后的尾节点接上剩下没参与逆序的节点们 

        head->next= dummy->next;//这是根据我的程序里面的结构改的，原句如下 
		return head;
		//return dummy->next;
    }

ListNode *reverseBetween2(ListNode *head,int m, int n) //翻转链表（加强版，但这个方法我还没调通） 
{
    // write your code here
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
	ListNode *current=head->next;  //先把表头给去掉，进行元素的反转 
    
	ListNode *newhead=current;//定义一个新的表头 
	for(int k=0;k<m-2;k++)
	{
		newhead=newhead->next;		
	} 
	ListNode *p,*q;
	   
    p=newhead->next;   
    
	if(m==1)
	{
		for(int a=0;a<n-m-1;a++)      //在这个循环过程中p所指的元素一直是不变的  
		{  
		    q=p->next;   
		    p->next=q->next;   
		    q->next=newhead->next;   
		    newhead->next=q;   
		} 	
	}
	else
	{
		for(int a=0;a<n-m;a++)      //在这个循环过程中p所指的元素一直是不变的  
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
		newhead->next=p->next;  //相当于成环   
		p->next=newhead;       //新head变为原head的next   
    	newhead=temp;     
	}    	
	 
	else if(current!=newhead)
	{
		current->next=newhead;
	}
		
	
	head->next=current;//再把头给加上，并返回 
    return head; 
}
ListNode *addLists(ListNode *l1, ListNode *l2) 
{
// write your code here
	ListNode *dummy = new ListNode(0);//新建一个链表头，用于存储之后的结果 
    ListNode *curr = dummy;
    int carry = 0;

    while ((l1 != NULL) || (l2 != NULL) || (carry != 0)) //只要有一个没有到终点，如果两个链表都到终点了，但是carry还有一个进位，也要再加 
    {//一个结点，写上1。 
        int l1_val = (l1 != NULL) ? l1->val : 0;//谁没到终点就把谁的值拿出来，否则在计算时就用0表示 
        int l2_val = (l2 != NULL) ? l2->val : 0;
        int sum = carry + l1_val + l2_val;
        // update carry
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);

        curr = curr->next;
        if (l1 != NULL) l1 = l1->next;//谁没到终点谁就往后走一格 
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
	
	printf("请输入链表中元素数量：\n");
	scanf("%d",&j);
	for(i=1;i<=j;i++)
	{
		printf("请输入第%d个元素:",i);
		scanf("%d",&p);
		LinkList_Insert(head,p,i);//链表中插入结点 
	}	

	printf("链表中元素：");
	LinkList_Print(head);
	printf("\n链表长度:%d\n",head->val);
	
	ListNode * newhead=reverseBetween(head,1,4); 
	LinkList_Print(newhead);
	
	LinkList_Destroy(head);
	return 0;
	
}
