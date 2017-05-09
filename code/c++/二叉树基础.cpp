//二叉树基础 
#include <iostream>
using namespace std;

struct BiTNode
{  
 char data;  
 struct BiTNode *lchild, *rchild;//左右孩子  
};

void CreateBiTree(BiTNode* &T);  
void Inorder(BiTNode* &T);  
void PreOrderTraverse(BiTNode* &T);  
void Posorder(BiTNode* &T);  

int main()
{  
	BiTNode* T; 
	cout<<"创建一颗树，其中A->Z字符代表树的数据，用“#”表示空树:"<<endl;  
	CreateBiTree(T);  
	
	cout<<"先序递归遍历："<<endl;  
	PreOrderTraverse(T);  
	cout<<endl;  
	
	cout<<"中序递归遍历："<<endl;  
	Inorder(T);  
	cout<<endl;  
	
	cout<<"后序递归遍历："<<endl;  
	Posorder(T);  
	cout<<endl;  
	  
	return 1;
}  
//=============================================先序递归创建二叉树树  
void CreateBiTree(BiTNode* &T)
{  
	//按先序输入二叉树中结点的值（一个字符），空格字符代表空树，  
	//构造二叉树表表示二叉树T。  
	char ch;
	ch=getchar();//其中getchar（）为逐个读入标准库函数
	if(ch==' ')
		T=NULL;  
	else
	{  
		T=new BiTNode;//产生新的子树  
	    T->data=ch;//由getchar（）逐个读入来  
	    CreateBiTree(T->lchild);//递归创建左子树  
	    CreateBiTree(T->rchild);//递归创建右子树  
 	}  
} 

//===============================================先序递归遍历二叉树  
void PreOrderTraverse(BiTNode* &T)
{   
	if(T)//当结点不为空的时候执行 
  	{ 
  		cout<<T->data;  
  		PreOrderTraverse(T->lchild);
  		PreOrderTraverse(T->rchild);  
    }  
 	else
		cout<<' ';  
} 
//================================================中序遍历二叉树  
void Inorder(BiTNode* &T)
{ 
	if(T)//T=null退层 
	{ 
  		Inorder(T->lchild);//中序遍历左子树  
  		cout<<T->data;//访问参数  
  		Inorder(T->rchild);//中序遍历右子树  
 	}  
 	else 
		cout<<' ';  
}  
//=================================================后序递归遍历二叉树  
void Posorder(BiTNode* &T)
{  
	if(T)
	{
		Posorder(T->lchild);//后序递归遍历左子树  
  		Posorder(T->rchild);//后序递归遍历右子树  
  		cout<<T->data;//访问根结点  
    }  
    else 
		cout<<' ';  
}  
