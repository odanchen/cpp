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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        queue<Node*> nodeQueue({root});
        while(!nodeQueue.empty()) {
            int toProcess = nodeQueue.size();
            vector<int> layer;
            for (int i = 0; i < toProcess; i++) {
                auto cur = nodeQueue.front();
                nodeQueue.pop();
                layer.push_back(cur->val);
                for (auto child : cur->children) nodeQueue.push(child);
            }
            ans.push_back(layer);
        }
        return ans;
    }
};
