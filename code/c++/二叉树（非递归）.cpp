//���������� 
//�ǵݹ鷽ʽʵ�ֶ�������ǰ�������ʵ����ʹ�õ���ջ�ĸ���
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
//void Inorder(BiTNode* &T);  
void PreOrderTraverse(BiTNode* &T);  
//void Posorder(BiTNode* &T);  

int main()
{  
	BiTNode* T; 
	cout<<"����һ����������A->Z�ַ������������ݣ��á�#����ʾ����:"<<endl;  
	CreateBiTree(T);  
	
	cout<<"����ݹ������"<<endl;  
	PreOrderTraverse(T);  
	cout<<endl;  
	
//	cout<<"����ݹ������"<<endl;  
//	Inorder(T);  
//	cout<<endl;  
	
//	cout<<"����ݹ������"<<endl;  
//	Posorder(T);  
//	cout<<endl;  
	  
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
    for(int k=0;k<ret.size();k++)
		cout<<ret[k]; 
} 
//================================================�������������  
/*
void Inorder(BiTNode* &T)
{ 
	if(T)//T=null�˲� 
	{ 
  		Inorder(T->lchild);//�������������  
  		cout<<T->data;//���ʲ���  
  		Inorder(T->rchild);//�������������  
 	}  
 	else 
		cout<<" ";  
}  
//=================================================����ݹ����������  
void Posorder(BiTNode* &T)
{  
	if(T)
	{
		Posorder(T->lchild);//����ݹ����������  
  		Posorder(T->rchild);//����ݹ����������  
  		cout<<T->data;//���ʸ����  
    }  
    else 
		cout<<"";  
}  */
