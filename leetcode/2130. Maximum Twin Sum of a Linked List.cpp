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
        ListNode* slowPtr = head, * fastPtr = head;
        while(fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr->next;
    }
    int pairSum(ListNode* head) {
        int ans = 0;
        stack<int> nums;
        ListNode* mid = middleNode(head);
        while (head != mid) {
            nums.push(head->val);
            head = head->next;
        }
        while (head) {
            ans = max(ans, head->val + nums.top());
            nums.pop();
            head = head->next;
        }
        return ans;
    }  
};
