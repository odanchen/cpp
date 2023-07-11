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
        while(fastPtr->next != NULL and fastPtr->next->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return (fastPtr->next == nullptr) ? slowPtr : slowPtr->next;
    }
    bool checkPalindrome(ListNode **left, ListNode* right) {
        if (right == NULL) return true;
        bool ans1 = checkPalindrome(left, right->next), ans2 = (*left)->val == right->val;
        *left = (*left)->next;
        return ans1 and ans2;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        return checkPalindrome(&head, mid);
    }
};
