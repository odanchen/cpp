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
    ListNode* middleNode(ListNode* head) {
        ListNode* slowPtr = head, *fastPtr = head;
        while(fastPtr->next && fastPtr->next->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
    }
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (p1 == NULL and p2 == NULL) return NULL;
        ListNode* cur;
        if (p1 != NULL and (p2 == NULL or p1->val < p2->val)) {
            cur = p1;
            cur->next = merge(p1->next, p2);
        } else {
            cur = p2;
            cur->next = merge(p1, p2->next);
        }
        return cur;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL or head->next == NULL) return head;
        ListNode* mid = middleNode(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        return merge(sortList(head), sortList(right));
    }
};
