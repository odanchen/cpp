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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL or head->next == NULL) return head;
        ListNode* tail = head, *newHead, *newTail = head;
        int cnt = 1;
        while(tail->next != NULL) {
            tail = tail->next;
            cnt++;
        }
        k %= cnt;
        if (k == 0) return head;
        for (int i = 0; i < cnt - k - 1; i++) newTail = newTail->next;
        newHead = newTail->next;
        tail->next = head;
        newTail->next = NULL;
        return newHead;
    }
};
