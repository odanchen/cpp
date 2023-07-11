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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL or head->next == NULL) return head;
        ListNode* left = head, *right, *cur;
        bool headFound = false;
        while(left != NULL) {
            right = left;
            while (right->next != NULL and left->val == right->next->val) right = right->next;
            if (right == left) {
                if (headFound) {
                    cur->next = left;
                    cur = cur->next;
                } else {
                    head = left;
                    cur = left;
                    headFound = true;
                }
            } else if (headFound) cur->next = NULL;
            left = right->next;
        }
        return headFound ? head : NULL;
    }
};
