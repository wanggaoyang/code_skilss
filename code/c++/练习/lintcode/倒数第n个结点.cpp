//���������е�����n����� ������ֻд��ʵ�ַ��� 
ListNode *nthToLast(ListNode *head, int n)
{
    // write your code here
    if(head==NULL)
        return NULL;
    ListNode *result=head;
    int count=1;
    while(head->next!=NULL)//��¼һ���м������
    {
        head=head->next;
        count++;
    }
    for(int i=0;i<count-n;i++)
    {
        result=result->next;
    }
    return result;
}
