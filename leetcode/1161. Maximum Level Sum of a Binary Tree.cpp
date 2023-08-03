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
    int maxLevelSum(TreeNode *root) {
        int ans = 1, level = 1, maxSum = root->val;
        queue<TreeNode *> nodeQueue({root});
        while (!nodeQueue.empty()) {
            int toProcess = nodeQueue.size(), curSum = 0;
            for (int i = 0; i < toProcess; i++) {
                auto cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur->left) nodeQueue.push(cur->left);
                if (cur->right) nodeQueue.push(cur->right);
                curSum += cur->val;
            }
            if (curSum > maxSum) {
                ans = level;
                maxSum = curSum;
            }
            level++;
        }
        return ans;
    }
};
