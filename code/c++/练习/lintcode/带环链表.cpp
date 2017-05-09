//���������ʵ�ַ��� :���ÿ���ָ��ķ��� ����ָ�������ָ��ʱ��˵���л� 
bool hasCycle(ListNode *head) 
    {
    // write your code here
        if (NULL == head || NULL == head->next) 
        {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast!= NULL && fast->next!=NULL) //������Ӻ������ fast->next!=NULL �жϣ���ΪfastҪ�����������ܾ���Զ�ˡ� 
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }

        return false;
    }
