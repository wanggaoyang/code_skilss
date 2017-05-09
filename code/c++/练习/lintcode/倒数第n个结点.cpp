//返回链表中倒数第n个结点 ，这里只写了实现方法 
ListNode *nthToLast(ListNode *head, int n)
{
    // write your code here
    if(head==NULL)
        return NULL;
    ListNode *result=head;
    int count=1;
    while(head->next!=NULL)//记录一共有几个结点
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
