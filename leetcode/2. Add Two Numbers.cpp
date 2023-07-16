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
        if (l1 == NULL and l2 == NULL) return NULL;
        int sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
        ListNode* ans = new ListNode(sum % 10);
        if ((l1 == NULL or l1->next == NULL) and (l2 == NULL or l2->next == NULL) and sum / 10 > 0) 
            ans->next = new ListNode(sum / 10);
        else {
            if (sum / 10 > 0) l1 != NULL and l1->next != NULL ? 
                l1->next->val += sum / 10 : l2->next->val += sum / 10;
            ans->next = addTwoNumbers(l1 == NULL ? l1 : l1->next, l2 == NULL ? l2 : l2->next);
        }
        return ans;
    }
};
