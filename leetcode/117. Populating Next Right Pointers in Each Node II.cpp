/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void checkNode(Node* node, Node *&head, Node *&prev) {
        if (head == NULL) head = prev = node;
        else {
            prev->next = node;
            prev = node;
        }
    }
    Node* connect(Node* root) {
        Node* cur = root;
        while(cur) {
            Node *head = NULL, *prev = NULL;
            while(cur) {
                if (cur->left) checkNode(cur->left, head, prev);
                if (cur->right) checkNode(cur->right, head, prev);
                cur = cur->next;
            }
            cur = head;
        }
        return root;
    }
};
