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
    ListNode* reverseList(ListNode* head) {
        ListNode *ans, *cur;
        if (head == NULL) return NULL;
        stack<int> values;
        while(head != NULL)
        {
            values.push(head->val);
            head = head->next;
        }
        while(not(values.empty()))
        {
            ListNode *temp = new ListNode(values.top());
            if (head == NULL)
            {
                cur = temp;
                head = cur;
            }
            else
            {
                cur->next = temp;
                cur = cur->next;
            }
            values.pop();
        }
        return head;
    }
};
