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
    pair<int, int> count(TreeNode* root, int &ans) {
        if (root == nullptr) return {0, 0};
        auto leftRes = count(root->left, ans), rightRes = count(root->right, ans);
        pair<int, int> curRes = {leftRes.first + rightRes.first + root->val, leftRes.second + rightRes.second + 1};
        if (floor((double) curRes.first / curRes.second) == root->val) ans++;
        return curRes;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        count(root, ans);
        return ans;
    }
};
