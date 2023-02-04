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
    int* val = NULL;
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        if (val == NULL or *val != head->val) {
            val = &head->val;
            head->next = deleteDuplicates(head->next);
            return head;
        }
        val = &head->val;
        return deleteDuplicates(head->next);
    }
};
