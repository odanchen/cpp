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
    ListNode* getNode(ListNode *&node) {
        int sum = 0;
        while (node->val != 0) {
            sum += node->val;
            node = node->next;
        }
        return new ListNode(sum);
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* left = head, *right = head->next;
        while (right) {
            if (head->val == 0) head = left = getNode(right);
            else {
                left->next = getNode(right);
                left = left->next;
            }
            right = right->next;
        }
        return head;
    }
};
