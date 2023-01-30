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
    struct toReverse {
        stack<ListNode*> midNodes;
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
    };
    void reverse(toReverse nodes) {
        if (nodes.leftNode != NULL) nodes.leftNode->next = nodes.midNodes.top();
        ListNode* prev = nodes.midNodes.top(); nodes.midNodes.pop();

        while(!nodes.midNodes.empty()) {
            prev->next = nodes.midNodes.top();
            prev = nodes.midNodes.top();
            nodes.midNodes.pop();
        }
        prev->next = nodes.rightNode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool isFirst = true;
        ListNode *cur = head;

        while (cur != NULL) {
            toReverse nodes;
            if (!isFirst) {
                nodes.leftNode = cur;
                cur = cur->next;
            }
            ListNode* newLeft = cur;
            for (int i = 0; i < k; i++) {
                if (cur == NULL) return head;
                nodes.midNodes.push(cur);
                if (i != k - 1) cur = cur->next;
            }
            nodes.rightNode = cur->next;
            if (isFirst) head = nodes.midNodes.top();
            isFirst = false;
            reverse(nodes);
            cur = newLeft;
        }
        return head;
    }
};
