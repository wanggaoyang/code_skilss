#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {}
};
ListNode * Create(void)
{
	ListNode *head = new ListNode(0);
	return head;
}
void Destroy(ListNode *head)
{
	delete head;
}
int Length(ListNode *head)
{
	ListNode *current = head;
	int count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}

	return count;
}
void Show(ListNode *head)
{
	ListNode *current = head;
	while (current)
	{
		cout << current->val;
		current = current->next;
	}
	cout << endl;
}
ListNode * Find(ListNode *head, int pos)
{
	ListNode *current = head;
	int i = 0;
	while (current&&i<pos)
	{
		current = current->next;
		i++;
	}
	if (i == pos)
		return current;
	else
		return NULL;
}
void Insert(ListNode *head, int pos, int x)
{
	ListNode *insert = new ListNode(-1);
	ListNode *current = Find(head, pos - 1);

	if (insert == NULL)
		return;

	insert->val = x;
	insert->next = current->next;
	current->next = insert;
}
ListNode * Reverse(ListNode* head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	ListNode *q, *p;
	p = head->next;

	while (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		q->next = head->next;
		head->next = q;
	}

	p->next = head;
	head = p->next->next;
	p->next->next = NULL;

	return head;
}

void Bubble_Sort(ListNode* head)
{
	ListNode* tail = NULL;
	ListNode* addhead = new ListNode(0);
	addhead->next = head;
	while (tail != addhead->next)
	{
		ListNode* pre = addhead;
		ListNode* cur = pre->next;
		while (cur != tail && cur->next != tail)
		{
			if (cur->val > cur->next->val)
			{
				//交换当前节点和后一个节点
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = cur;
			}
			pre = pre->next;
			cur = pre->next;
		}  
		tail = cur;
	}
}

int main()
{
	ListNode *head = new ListNode(4);
	Insert(head, 1, 1);
	Insert(head, 2, 3);
	Insert(head, 3, 7);
	Insert(head, 4, 5);

	Show(head);

	Show(Reverse(head));

	Bubble_Sort(head);
	Show(head);
}
*/

struct Node
{
	int value;
	Node* next;
}; 

void Sort(Node* head)
{
	Node* tail = NULL; 
	while (tail != head->next)
	{
		Node* pre = head;
		Node* cur = pre->next;
		while (cur != tail && cur->next != tail)
		{
			if (cur->value > cur->next->value)
			{
				//交换当前节点和后一个节点
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = cur;
			}
			pre = pre->next;
			cur = pre->next;
		}  
		tail = cur;
	}
}
void main()
{
	Node* head = new Node();
	Node* cur = head; //使用带表头的链表
	int n = 9;
	//初始化链表数据
	for (int i = n; i >0; i--)
	{
		Node* node = new Node();
		node->value = i;
		cur->next = node;
		cur = node;
	} //排序 
	Sort(head);
	
	while (head != NULL)
	{
		cout << head->value;
		head = head->next;
	}
}