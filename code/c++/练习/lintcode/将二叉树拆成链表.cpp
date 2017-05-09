//���������������
//�ݹ鷽ʽʵ�֣�û��͸ 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct BiTNode
{  
 char data;  
 struct BiTNode *lchild, *rchild;//���Һ���  
};

void CreateBiTree(BiTNode* &T);    
void PreOrderTraverse(BiTNode* &T);  
BiTNode* ConvertToLink(BiTNode* T);

int main()
{  
	BiTNode* T; 
	cout<<"����һ����������A->Z�ַ������������ݣ��á�#����ʾ����:"<<endl;  
	CreateBiTree(T);  
	
	cout<<"����ݹ������"<<endl;  
	PreOrderTraverse(T);  
	cout<<endl;  
	
	ConvertToLink(T);  
	return 1;
}  
//=============================================����ݹ鴴����������  
void CreateBiTree(BiTNode* &T)
{  
	//����������������н���ֵ��һ���ַ������ո��ַ����������  
	//������������ʾ������T��  
	char ch;
	ch=getchar();//����getchar����Ϊ��������׼�⺯��
	if(ch==' ')
		T=NULL;  
	else
	{  
		T=new BiTNode;//�����µ�����  
	    T->data=ch;//��getchar�������������  
	    CreateBiTree(T->lchild);//�ݹ鴴��������  
	    CreateBiTree(T->rchild);//�ݹ鴴��������  
 	}  
} 

//===============================================�ǵݹ��������������  
void PreOrderTraverse(BiTNode* &T)
{   
	stack<BiTNode*> s;  
    BiTNode* cur=T;  
    vector<char> ret;  
          
    while(cur||!s.empty())//ջ�в��ջ�ǰָ��ǿ�
    {  
        if(cur)
        {  
            ret.push_back(cur->data);  
            s.push(cur);  
            cur=cur->lchild;  
        }
        else
        {  
            cur=s.top();  
            s.pop();  
            cur=cur->rchild;  
        }  
    }  
    
} 

BiTNode* ConvertToLink(BiTNode* T) // utility function  
{// return value is the tail of the linked list  
    if(T==NULL)  
        return NULL;  
  	cout<<"��ǰT��"<<T->data<<endl; 
    BiTNode* leftLinkTail = ConvertToLink(T->lchild); // tail of left linked list
	cout<<"��ǰT�ң�"<<T->data<<endl; 
    BiTNode* rightLinkTail = ConvertToLink(T->rchild); // tail of left linked list  
      
    if(leftLinkTail != NULL)  
    {  
        leftLinkTail->rchild = T->rchild;  
        T->rchild = T->lchild;  
    }  
      
    T->lchild = NULL;  
  
    if(rightLinkTail!= NULL)  
        return rightLinkTail;  
    else if(leftLinkTail != NULL)  
        return leftLinkTail;  
    else  
        return T;  
}  
