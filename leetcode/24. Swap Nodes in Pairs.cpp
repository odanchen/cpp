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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode *left = head;
        ListNode *right = head->next;
        
        while(right != NULL) {
            swap(left->val, right->val);
            if (right->next == NULL) return head;
            left = left->next->next;
            right = right->next->next;
        }
        return head;
    }
};
