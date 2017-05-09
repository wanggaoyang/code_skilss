//�������������н�� 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int data;
	struct Node *next;
}Lnode,*LinkList;

LinkList LinkList_Create()//���������� 
{ 
	LinkList head=(LinkList)malloc(sizeof(LinkList));//������һ��ָ��ͷ������ݽṹ��ָ�룬��Ϊͷ������ռ�
	
	if(head!=NULL)
	{
		head->data=0;          //ͷ��㳤��Ϊ0
		head->next=NULL;   //ͷ���ָ��ָ���
	}
	return head;//��ͷ��㷵��
}
		
void LinkList_Destroy(LinkList list) // ����������
{
    free(list);
}
	
void LinkList_Length(LinkList list) // ��ѯ�����Ⱥ���
{
    LinkList sList = (LinkList)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->data;
    }
    printf("\nԪ������:%d",sList->data);
}

void LinkList_Print(LinkList head) //������ʾ����
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

LinkList LinkList_GetNode(LinkList head,int i)//���Ĳ��Һ��� 
{//�ڴ�ͷ���ĵ�����head�в��ҵ�i����㣬���ҵ���0��i��n����
 //�򷵻ظý��Ĵ洢λ�ã����򷵻�NULL��
    int j;
    LinkList p;
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

void LinkList_Insert(LinkList head,int x,int i)//���½����뺯�� 
{//��ֵΪx���½����뵽��ͷ���ĵ�����head�ĵ�i������λ����
	LinkList current;
    current=LinkList_GetNode(head,i-1);//Ѱ�ҵ�i-1�����
    if (current==NULL)//i<1��i>n+1ʱ����λ��i�д�
        printf("error");
    	LinkList insert=(LinkList)malloc(sizeof(Lnode));
        insert->data=x;insert->next=current->next;current->next=insert;
        head->data++;
}    

void LinkList_Delete(LinkList head,int pos)//ɾ��posλ�õĽ�� 
{
    LinkList current;
    if(pos>=head->data)
    {	printf("�������ȣ�Ĭ��ɾ�����һ��Ԫ��");
    	pos=head->data;
    } 
	current=LinkList_GetNode(head,pos-1);//Ѱ��posǰһ�����
    if (current==NULL)//i<1��i>n+1ʱ����λ��i�д�
        printf("error");
    	current->next=(current->next)->next;
        head->data--;
} 

LinkList swapPairs(LinkList head) //�������������н�� 
{
    // Write your code here
	LinkList pos=head->next;
	if(head==NULL)
        return NULL;
    if(pos->next==NULL)
        return head;
    
    while((pos!=NULL)&&(pos->next!=NULL))//һ���жϵ�ǰָ����������Ƿ�Ϊ�գ�����һΪ�վ�����ѭ�� 
    {
        int temp=0;//��ʱ����������ǰ������һ����е�ֵ 
        temp=pos->data;
        //printf("temp:%d\n",pos->data);
        pos->data=pos->next->data;
        //printf("pos->data:%d\n",pos->data);
        pos->next->data=temp;
        //printf("pos->next->data:%d\n",pos->next->data);
        pos=pos->next;//ָ���¸�Ԫ��,����϶�û����ģ�֮ǰwhile���жϵ��� 
        if(pos->next!=NULL)//�������Ҫ�ж�һ���ǲ��ǵ�ǰ�Ѿ�ָ�����ˣ����˵Ļ���ֱ�������� 
        	pos=pos->next;//ָ���¸�Ԫ��
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
	printf("������Ԫ��������\n");
	scanf("%d",&j);
	for(i=1;i<=j;i++)
	{
		printf("�������%d��Ԫ��:",i);
		scanf("%d",&p);
		LinkList_Insert(head,p,i);//�����в����� 
	}	
	printf("������Ԫ�أ�");
	LinkList_Print(head);
	printf("\n������:%d\n",head->data);
	swapPairs(head);
	printf("������Ԫ�أ�");
	LinkList_Print(head);
	//printf("\nɾ���ڼ���Ԫ�أ�");
	//scanf("%d",&l);
	//LinkList_Delete(head,l);
	//printf("\nɾ��������");
	//LinkList_Length(head);
//	LinkList_ListReverse(head);//�������� 
//	LinkList_Print(head);
	LinkList_Destroy(head);
}
