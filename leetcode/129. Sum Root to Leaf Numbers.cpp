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
    int count(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        if (root->left == NULL and root->right == NULL) return sum * 10 + root->val;
        return count(root->left, sum * 10 + root->val) + count(root->right, sum * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return count(root, 0);
    }
};
