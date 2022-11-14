    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        ListNode* left = head;
        int cnt = 1;

        while (right->next != nullptr)
        {
            right = right->next;
            cnt++;
        }
        
        if (cnt == n) return head->next;

        for (int i = 0; i < cnt - n - 1; i++) left = left->next;

        if (left->next->next != nullptr) left->next = left->next->next;
        else left->next = nullptr; 
        return head;
    }
