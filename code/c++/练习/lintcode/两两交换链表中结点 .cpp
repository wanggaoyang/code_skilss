//两两交换链表中结点 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int data;
	struct Node *next;
}Lnode,*LinkList;

LinkList LinkList_Create()//链表创建函数 
{ 
	LinkList head=(LinkList)malloc(sizeof(LinkList));//创建了一个指向头结点数据结构的指针，并为头结点分配空间
	
	if(head!=NULL)
	{
		head->data=0;          //头结点长度为0
		head->next=NULL;   //头结点指针指向空
	}
	return head;//将头结点返回
}
		
void LinkList_Destroy(LinkList list) // 销毁链表函数
{
    free(list);
}
	
void LinkList_Length(LinkList list) // 查询链表长度函数
{
    LinkList sList = (LinkList)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->data;
    }
    printf("\n元素数量:%d",sList->data);
}

void LinkList_Print(LinkList head) //链表显示函数
{
	LinkList current=head->next;
	int length=0;
	length=head->data;
	int i=0;
	while(current!=NULL) 
	{
		for(i=0;i<length;i++)
		{
			printf("%d ",current->data);
			current=current->next;
		}
	}
}

LinkList LinkList_GetNode(LinkList head,int i)//结点的查找函数 
{//在带头结点的单链表head中查找第i个结点，若找到（0≤i≤n），
 //则返回该结点的存储位置，否则返回NULL。
    int j;
    LinkList p;
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

void LinkList_Insert(LinkList head,int x,int i)//将新结点插入函数 
{//将值为x的新结点插入到带头结点的单链表head的第i个结点的位置上
	LinkList current;
    current=LinkList_GetNode(head,i-1);//寻找第i-1个结点
    if (current==NULL)//i<1或i>n+1时插入位置i有错
        printf("error");
    	LinkList insert=(LinkList)malloc(sizeof(Lnode));
        insert->data=x;insert->next=current->next;current->next=insert;
        head->data++;
}    

void LinkList_Delete(LinkList head,int pos)//删除pos位置的结点 
{
    LinkList current;
    if(pos>=head->data)
    {	printf("超过长度，默认删除最后一个元素");
    	pos=head->data;
    } 
	current=LinkList_GetNode(head,pos-1);//寻找pos前一个结点
    if (current==NULL)//i<1或i>n+1时插入位置i有错
        printf("error");
    	current->next=(current->next)->next;
        head->data--;
} 

LinkList swapPairs(LinkList head) //两两交换链表中结点 
{
    // Write your code here
	LinkList pos=head->next;
	if(head==NULL)
        return NULL;
    if(pos->next==NULL)
        return head;
    
    while((pos!=NULL)&&(pos->next!=NULL))//一下判断当前指针的下面结点是否为空，有任一为空就跳出循环 
    {
        int temp=0;//临时变量交换当前结点和下一结点中的值 
        temp=pos->data;
        //printf("temp:%d\n",pos->data);
        pos->data=pos->next->data;
        //printf("pos->data:%d\n",pos->data);
        pos->next->data=temp;
        //printf("pos->next->data:%d\n",pos->next->data);
        pos=pos->next;//指向下个元素,这个肯定没问题的，之前while中判断到了 
        if(pos->next!=NULL)//但这个还要判断一下是不是当前已经指到空了，空了的话就直接跳出了 
        	pos=pos->next;//指向下个元素
    }

    return head;
}

int main()
{
	LinkList head=LinkList_Create();
	int i=0;
	int j=0;
	int p=0;
	int l=0;
	int n=0;
	LinkList ret;
	printf("请输入元素数量：\n");
	scanf("%d",&j);
	for(i=1;i<=j;i++)
	{
		printf("请输入第%d个元素:",i);
		scanf("%d",&p);
		LinkList_Insert(head,p,i);//链表中插入结点 
	}	
	printf("链表中元素：");
	LinkList_Print(head);
	printf("\n链表长度:%d\n",head->data);
	swapPairs(head);
	printf("链表中元素：");
	LinkList_Print(head);
	//printf("\n删除第几个元素：");
	//scanf("%d",&l);
	//LinkList_Delete(head,l);
	//printf("\n删除后链表：");
	//LinkList_Length(head);
//	LinkList_ListReverse(head);//链表逆序 
//	LinkList_Print(head);
	LinkList_Destroy(head);
}
