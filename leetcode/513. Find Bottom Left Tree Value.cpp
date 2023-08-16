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
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        queue<TreeNode*> nodeQueue({root});
        while (!nodeQueue.empty()) {
            int toProcess = nodeQueue.size();
            for (int i = 0; i < toProcess; i++) {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                if (i == 0) ans = cur->val;
                if (cur->left) nodeQueue.push(cur->left);
                if (cur->right) nodeQueue.push(cur->right); 
            }
        }
        return ans;
    }
};
