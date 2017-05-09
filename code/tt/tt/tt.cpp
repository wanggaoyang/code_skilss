#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

const int MAXSIZE = 10;
typedef struct stack
{
	int a[MAXSIZE];
	int top;
}S;

S* create()
{
	S *head = new S;
	return head;
}
void init(S* head)
{
	head->top = 0;
}

void insert(S* head, int num)
{
	if (head->top != (MAXSIZE - 1))
	{
		head->a[head->top] = num;
		head->top++;
	}
	else
		cout << "error" << endl;
}

void pop(S *head)
{
	if (head->top != -1)
	{
		head->top--;
		int temp = head->a[head->top];
		cout << temp << endl;
		
	}
	else
		cout << "empty" << endl;
}

int main()
{
	S *head = create();
	init(head);

	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);

	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
}