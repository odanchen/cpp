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
    void processNode(Node *root)
    {
        if (root->left == NULL) return;

        Node *leftRoot = root->left, *rightRoot = root->right;
        while(leftRoot != NULL)
        {
            leftRoot->next = rightRoot;
            leftRoot = leftRoot->right;
            rightRoot = rightRoot->left;
        }
    }
    void dfs(Node *root)
    {
        if (root == NULL) return;

        processNode(root);
        dfs(root->left);
        dfs(root->right);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};
