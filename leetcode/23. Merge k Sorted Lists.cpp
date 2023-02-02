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
    class LinkedList {
        ListNode* head = NULL;
        ListNode* tail = NULL;
    public:
        void push(int val) {
            if (head == NULL) {
            head = new ListNode(val);
                tail = head;
            }
            else {
                ListNode* temp = new ListNode(val);
                tail->next = temp;
                tail = tail->next;
            }
        }
        ListNode* getHead() {return head;}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*,  ListNode*)>> nQueue(comp);
        for (ListNode* list : lists) {
            if(list != NULL) nQueue.push(list);
        }
        LinkedList ans;
        while(!nQueue.empty()) {
            ListNode* list = nQueue.top();
            nQueue.pop();
            ans.push(list->val);
            if (list->next != NULL) nQueue.push(list->next);
        }
        return ans.getHead();
    }
};
