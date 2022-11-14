    ListNode* middleNode(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr->next != nullptr && fastPtr->next->next != nullptr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if (fastPtr->next == nullptr) return slowPtr;
        else return slowPtr->next;
    }
