/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    uint8_t dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if (ans or !root) return 0;
        uint8_t check = (root == p ? 1 : 0) | (root == q ? 2 : 0);
        if (check == 3 and !ans) ans = root;
        check |= dfs(root->left, p, q, ans) | dfs(root->right, p, q, ans);
        if (check == 3 and !ans) ans = root;
        return check;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        dfs(root, p, q, ans);
        return ans;
    }
};
