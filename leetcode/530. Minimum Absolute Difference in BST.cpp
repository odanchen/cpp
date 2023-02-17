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
    optional<int> prev;
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) return INT_MAX;

        int ans = getMinimumDifference(root->left);
        ans = min(prev.has_value() ? abs(root->val - prev.value()) : INT_MAX, ans);
        prev = root->val;
        ans = min (ans, getMinimumDifference(root->right));

        return ans;
    }
};
