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
    bool hasSum(TreeNode* root, int targetSum, int curSum) {
        if (root == NULL) return false;
        if (root->left == NULL and root->right == NULL) return curSum + root->val == targetSum;
        return hasSum(root->left, targetSum, curSum + root->val) or hasSum(root->right, targetSum, curSum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return hasSum(root, targetSum, 0);
    }
};
