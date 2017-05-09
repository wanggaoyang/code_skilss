//二叉树基础 （前序和中序） 
//非递归方式实现二叉树的前序遍历，实际是使用到了栈的概念
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct BiTNode
{  
 char data;  
 struct BiTNode *lchild, *rchild;//左右孩子  
};

void CreateBiTree(BiTNode* &T);  
void inorderTraverse(BiTNode* &T); //中序遍历 
void PreOrderTraverse(BiTNode* &T);  //前序遍历 
void postorderTraverse(BiTNode* &T); //后序遍历 

int main()
{  
	BiTNode* T; 
	cout<<"创建一颗树，其中A->Z字符代表树的数据，用“#”表示空树:"<<endl;  
	CreateBiTree(T);  
	
	cout<<"先序递归遍历："<<endl;  
	PreOrderTraverse(T);  
	cout<<endl;  
	
	cout<<"中序递归遍历："<<endl;  
	inorderTraverse(T); 
	cout<<endl;  
	
	cout<<"后序递归遍历："<<endl;  
	postorderTraverse(T);  
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

//===============================================非递归先序遍历二叉树  
void PreOrderTraverse(BiTNode* &T)
{   
	stack<BiTNode*> s;  
    BiTNode* cur=T;  
    vector<char> ret;  
          
    while(cur||!s.empty())//栈中不空或当前指针非空
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
//================================================中序遍历二叉树  
void inorderTraverse(BiTNode* &T) 
{
    // write your code here
    stack<BiTNode*> s;  
    BiTNode* cur=T;  
    vector<char> ret;  
          
    while(cur||!s.empty())//栈中不空或当前指针非空
    {  
        if(cur)
        {  
            s.push(cur); 
            cur=cur->lchild;
        }
        else
        {  
            cur=s.top();  
            ret.push_back(cur->data);  
            s.pop();  
            cur=cur->rchild;  
        }  
    }  
    for(int k=0;k<ret.size();k++)
		cout<<ret[k];
}
//=================================================后序递归遍历二叉树  
//后序用的是递归的方法，参看lintcode上的代码吧
 
