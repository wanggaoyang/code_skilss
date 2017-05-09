//将二叉树拆成链表
//递归方式实现，没看透 
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
void PreOrderTraverse(BiTNode* &T);  
BiTNode* ConvertToLink(BiTNode* T);

int main()
{  
	BiTNode* T; 
	cout<<"创建一颗树，其中A->Z字符代表树的数据，用“#”表示空树:"<<endl;  
	CreateBiTree(T);  
	
	cout<<"先序递归遍历："<<endl;  
	PreOrderTraverse(T);  
	cout<<endl;  
	
	ConvertToLink(T);  
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
    
} 

BiTNode* ConvertToLink(BiTNode* T) // utility function  
{// return value is the tail of the linked list  
    if(T==NULL)  
        return NULL;  
  	cout<<"当前T左："<<T->data<<endl; 
    BiTNode* leftLinkTail = ConvertToLink(T->lchild); // tail of left linked list
	cout<<"当前T右："<<T->data<<endl; 
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
