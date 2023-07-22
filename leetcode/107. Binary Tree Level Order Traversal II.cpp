/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> nodeQueue({root});
        while (!nodeQueue.empty()) {
            size_t toProcess = nodeQueue.size();
            vector<int> layer;
            for (int i = 0; i < toProcess; i++) {
                auto cur = nodeQueue.front();
                nodeQueue.pop();
                layer.push_back(cur->val);
                if (cur->left) nodeQueue.push(cur->left);
                if (cur->right) nodeQueue.push(cur->right);
            }
            ans.push_back(layer);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
