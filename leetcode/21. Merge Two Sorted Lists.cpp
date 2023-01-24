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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head;
        ListNode *cur;
        
        if (list1 == NULL && list2 == NULL) return NULL;
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if(list1->val < list2->val)
        {
            cur = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            cur = new ListNode(list2->val);
            list2 = list2->next;
        }
        head = cur;

        while(list1 != nullptr || list2 != nullptr)
        {
            ListNode *temp = new ListNode;
            if (list2 == nullptr || (list1 != nullptr && list1->val < list2->val)) 
            {
                temp->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                temp->val = list2->val;
                list2 = list2->next;
            }

            cur->next = temp;
            cur = cur->next;
        }
        return head;
    }
};
