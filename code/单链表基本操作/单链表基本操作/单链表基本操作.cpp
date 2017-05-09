#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)//合并两个已经排序好的单链表（可以参考合并两排序好的数组）
{
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->val <= pHead2->val)
		{
			ListNode *temp = new ListNode(0);
			temp->val = pHead1->val;
			temp->next = NULL;
			cur->next = temp;
			cur = temp;

			pHead1 = pHead1->next;
		}

		else
		{
			ListNode *temp = new ListNode(0);
			temp->val = pHead2->val;
			temp->next = NULL;
			cur->next = temp;
			cur = temp;

			pHead2 = pHead2->next;
		}
	}
	
	while (pHead1 != NULL)
	{
		ListNode *temp = new ListNode(0);
		temp->val = pHead1->val;
		temp->next = NULL;
		cur->next = temp;
		cur = temp;

		pHead1 = pHead1->next;
	}

	while (pHead2 != NULL)
	{
		ListNode *temp = new ListNode(0);
		temp->val = pHead2->val;
		temp->next = NULL;
		cur->next = temp;
		cur = temp;

		pHead2 = pHead2->next;
	}
	return head->next;
}

int main()
{
	ListNode *head = new ListNode(0);
	Insert(head, 1, 1);
	Insert(head, 2, 2);
	Insert(head, 3, 3);
	Insert(head, 4, 4);
	Show(head);

	ListNode *head2 = new ListNode(1);
	Insert(head2, 1, 2);
	Insert(head2, 2, 3);
	Insert(head2, 3, 4);
	Insert(head2, 4, 5);
	Insert(head2, 5, 6);
	Insert(head2, 6, 7);
	Show(head2);

	Show(Merge(head, head2));
}