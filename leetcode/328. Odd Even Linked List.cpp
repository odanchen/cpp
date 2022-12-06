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
    int getNextVal(queue<int> &odds, queue<int> &evens)
    {
        int ans;
        if (not(odds.empty())) 
        {
            ans = odds.front(); 
            odds.pop();
            return ans;
        }
        else 
        {
            ans = evens.front(); 
            evens.pop();
            return ans;
        }
    }
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        queue<int> odds;
        queue<int> evens;
        int isOdd = true;
        while (head != nullptr)
        {
            if (isOdd) odds.push(head->val);
            else evens.push(head->val);
            isOdd = not(isOdd);
            head = head->next;
        }

        ListNode *newHead, *cur;
        newHead = new ListNode;
        cur = new ListNode;

        newHead->val = getNextVal(odds, evens);
        cur->val = getNextVal(odds, evens);

        newHead->next = cur;
        while (not(odds.empty()) || not(evens.empty()))
        {
            ListNode* temp = new ListNode;
            temp->val = getNextVal(odds, evens);

            cur->next = temp;
            cur = cur->next;
        }

        return newHead;
    }
};
