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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL or head->next == NULL) return head;
        ListNode* left = head->val < x ? head : NULL, *right = head, *temp = NULL;
        while (left != NULL and left->next != NULL and left->val < x and left->next->val < x) left = left->next;
        right = left == NULL ? head->next : left->next;
        temp = left == NULL ? head : left;
        while (right != NULL) {
            while (right != NULL and right->val >= x) {
                right = right->next;
                temp = temp->next;
            }
            if (right == NULL) return head;
            temp->next = right->next;
            if (left == NULL) {
                right->next = head;
                head = right;
            } else {
                right->next = left->next;
                left->next = right;
            }
            left = right;
            right = temp->next;
        }
        return head;
    }
};
