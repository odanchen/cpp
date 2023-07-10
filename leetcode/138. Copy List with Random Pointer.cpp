/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> nodes;
        Node *cur = new Node(head->val), *newHead = cur;
        nodes.insert({head, newHead});
        while (head != NULL) {
            if (head->next != NULL and nodes.find(head->next) == nodes.end()) {
                cur->next = new Node(head->next->val);
                nodes.insert({head->next, cur->next});
            } else if (head->next != NULL) cur->next = nodes[head->next];

            if (head->random != NULL and nodes.find(head->random) == nodes.end()) {
                cur->random = new Node(head->random->val);
                nodes.insert({head->random, cur->random});
            } else if (head->random != NULL) cur->random = nodes[head->random];
            cur = cur->next;
            head = head->next;
        }
        return newHead;
    }
};
