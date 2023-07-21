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
    void getNum(TreeNode* root, int &ans, int cur) {
        if (root == nullptr) return;
        cur = root->val ? cur * 2 + 1 : cur * 2;
        if (root->left == nullptr and root->right == nullptr) ans += cur;
        getNum(root->left, ans, cur);
        getNum(root->right, ans, cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        getNum(root, ans, 0);
        return ans;
    }
};
