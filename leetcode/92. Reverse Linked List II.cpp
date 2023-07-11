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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* temp, *next = head->next;
        head->next = NULL;
        while (next) {
            temp = next->next;
            next->next = head;
            head = next;
            next = temp;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL or head->next == NULL or left == right) return head;
        ListNode* leftEnd = head, *begin, *end = head, *rightEnd;
        for (int i = 1; i < right; i++) {
            if (i < left - 1) leftEnd = leftEnd->next;
            end = end->next;
        }
        begin = (left == 1) ? head : leftEnd->next;
        rightEnd = end->next;
        end->next = NULL;
        reverseList(begin);
        if (left > 1) leftEnd->next = end;
        begin->next = rightEnd;
        return left == 1 ? end : head;
    }
};
