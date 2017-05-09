/*���ֽṹ�Ƚ�����*/
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
	if (root)//����㲻Ϊ�յ�ʱ��ִ�� 
	{
		cout << root->val;
		pre(root->leftchild);
		pre(root->rightchild);
	}
}

void mid(bitree* root)
{
	if (root)//����㲻Ϊ�յ�ʱ��ִ�� 
	{
		mid(root->leftchild);
		cout << root->val;
		mid(root->rightchild);
	}
}

void back(bitree* root)
{
	if (root)//����㲻Ϊ�յ�ʱ��ִ�� 
	{
		back(root->leftchild);
		back(root->rightchild);
		cout << root->val;
	}
}
//�������Ĳ�α������ֳƹ�����ȱ���
void layer(bitree* root)//Ϊ�˷��㣬����ģ���ࣨ���У�ʵ��
{
	queue<bitree *> q;
	bitree *ptr = NULL;

	q.push(root);//���ڵ����
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

//��������������ȱ���
void depthFirstSearch(bitree *root) 
{
	stack<bitree *> Stack;  //����ջ
	bitree *node = NULL ;

	Stack.push(root);
	while (!Stack.empty()) 
	{
		node = Stack.top();
		cout<<node->val;  //���������
		Stack.pop();
		if (node->rightchild) 
		{
			Stack.push(node->rightchild);  //�Ƚ�������ѹջ
		}
		if (node->leftchild) 
		{
			Stack.push(node->leftchild);  //�ٽ�������ѹջ
		}
	}
}

//�����������
int depth(bitree* root)
{
	int deep = 0;
	if (root)//����㲻Ϊ�յ�ʱ��ִ�� 
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
	cout << "���������������" << endl;
	pre(root);
	cout << endl <<"���������������" << endl;
	mid(root);
	cout << endl << "�������ĺ������" << endl;
	back(root);
	cout << endl << "�������Ĺ�����ȱ���"<< endl;
	layer(root);
	cout << endl << "��������������ȱ���(����)" << endl;
	depthFirstSearch(root);
	cout << endl << "�����������" << endl;
	int ret = depth(root);
	cout << ret << endl;
	
	return 0;

}