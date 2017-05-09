//带环链表的实现方法 :采用快慢指针的方法 ，快指针赶上慢指针时，说明有环 
bool hasCycle(ListNode *head) 
    {
    // write your code here
        if (NULL == head || NULL == head->next) 
        {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast!= NULL && fast->next!=NULL) //如果不加后面这个 fast->next!=NULL 判断，因为fast要走两步，可能就走远了。 
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }

        return false;
    }
