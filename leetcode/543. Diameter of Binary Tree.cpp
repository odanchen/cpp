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
    int getAns(TreeNode* root, int &ans) {
        if (root == nullptr) return 0;
        int left = getAns(root->left, ans), right = getAns(root->right, ans);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getAns(root, ans);
        return ans == 0 ? 0 : ans - 1;
    }
};
