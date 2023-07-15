/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int getDepth(Node* root, int depth) {
        int ans = depth;
        for (auto child : root->children) ans = max(ans, getDepth(child, depth + 1));
        return ans;
    }
    int maxDepth(Node* root) {
        return root == NULL ? 0 : getDepth(root, 1);
    }
};
