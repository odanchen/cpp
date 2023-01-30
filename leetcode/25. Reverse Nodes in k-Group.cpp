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
    void reverse(ListNode* prev, ListNode* cur, int depth, int k) {
        if (depth < k) {
            reverse(cur, cur->next, depth + 1, k);
            cur->next = prev;
        }
    }
    ListNode* getNodeForward(ListNode* node, int k) {
        for (int i = 0; i < k; i++) {
            if (node == NULL) return NULL;
            node = node->next;
        }
        return node;
    }
    void solve(ListNode *cur, int k) {
        ListNode *left = NULL, *next = getNodeForward(cur, k);
        ListNode *lNext = getNodeForward(cur, k - 1);
        while(lNext != NULL) {
            reverse(NULL, cur, 0, k);
            if (left != NULL) left->next = lNext;
            cur->next = next;
            left = cur;
            cur = cur->next;
            next = getNodeForward(cur, k);
            lNext = getNodeForward(cur, k - 1);
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = getNodeForward(head, k - 1);
        ListNode *ans = (newHead == NULL) ? head : newHead;
        solve(head, k);
        return ans;
    }
};
