/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        int temp = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int val1, val2;

            if(l1 == NULL) val1 = 0;
            else val1 = l1->val;

            if(l2 == NULL) val2 = 0;
            else val2 = l2->val;

            int val3 = val1 + val2 + temp;

            cur->val = (val3) % 10;
            temp = (val3) / 10;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;

            if (l1 != NULL || l2 != NULL)
            {
                ListNode *ptrNext = new ListNode();
                cur->next = ptrNext;
                cur = cur->next;
            }
            else if (temp == 1)
            {
                ListNode *ptrNext = new ListNode();
                cur->next = ptrNext;
                cur = cur->next;
                cur->val = temp;
            }
        }

        return head;
    }
};
