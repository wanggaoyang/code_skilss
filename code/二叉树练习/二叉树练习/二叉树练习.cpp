/*这种结构比较清晰*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct bitree
{
	char val;
	bitree *leftchild;
	bitree *rightchild;
};

/*create*/
bitree *create()
{
	char ch;
	ch = getchar();
	if (ch == ' ')
		return NULL;

	bitree *root = new bitree;
	root->val = ch;
	root->leftchild = create();
	root->rightchild = create();
	return root;
}

void pre(bitree* root)
{
	if (root)//当结点不为空的时候执行 
	{
		cout << root->val;
		pre(root->leftchild);
		pre(root->rightchild);
	}
}

void mid(bitree* root)
{
	if (root)//当结点不为空的时候执行 
	{
		mid(root->leftchild);
		cout << root->val;
		mid(root->rightchild);
	}
}

void back(bitree* root)
{
	if (root)//当结点不为空的时候执行 
	{
		back(root->leftchild);
		back(root->rightchild);
		cout << root->val;
	}
}
//二叉树的层次遍历，又称广度优先遍历
void layer(bitree* root)//为了方便，借助模板类（队列）实现
{
	queue<bitree *> q;
	bitree *ptr = NULL;

	q.push(root);//根节点入队
	while (!q.empty())
	{
		ptr = q.front();
		q.pop();
		cout << ptr->val << " ";

		if (ptr->leftchild != NULL)
		{
			q.push(ptr->leftchild);
		}

		if (ptr->rightchild != NULL)
		{
			q.push(ptr->rightchild);
		}
	}

}

//二叉树的深度优先遍历
void depthFirstSearch(bitree *root) 
{
	stack<bitree *> Stack;  //建立栈
	bitree *node = NULL ;

	Stack.push(root);
	while (!Stack.empty()) 
	{
		node = Stack.top();
		cout<<node->val;  //遍历根结点
		Stack.pop();
		if (node->rightchild) 
		{
			Stack.push(node->rightchild);  //先将右子树压栈
		}
		if (node->leftchild) 
		{
			Stack.push(node->leftchild);  //再将左子树压栈
		}
	}
}

//二叉树的深度
int depth(bitree* root)
{
	int deep = 0;
	if (root)//当结点不为空的时候执行 
	{
		int ldeep = depth(root->leftchild);
		int rdeep = depth(root->rightchild);
		deep = ldeep >= rdeep ? ldeep + 1 : rdeep + 1;
	}
	return deep;
}

int main()
{
	bitree *root = create();
	cout << "二叉树的先序遍历" << endl;
	pre(root);
	cout << endl <<"二叉树的中序遍历" << endl;
	mid(root);
	cout << endl << "二叉树的后序遍历" << endl;
	back(root);
	cout << endl << "二叉树的广度优先遍历"<< endl;
	layer(root);
	cout << endl << "二叉树的深度优先遍历(先序)" << endl;
	depthFirstSearch(root);
	cout << endl << "二叉树的深度" << endl;
	int ret = depth(root);
	cout << ret << endl;
	
	return 0;

}