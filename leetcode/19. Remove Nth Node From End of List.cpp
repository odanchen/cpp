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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        ListNode* left = head;
        int cnt = 1;

        while (right->next != nullptr)
        {
            right = right->next;
            cnt++;
        }
        
        if (cnt == n) return head->next;

        for (int i = 0; i < cnt - n - 1; i++) left = left->next;

        if (left->next->next != nullptr) left->next = left->next->next;
        else left->next = nullptr; 
        return head;
    }
};
