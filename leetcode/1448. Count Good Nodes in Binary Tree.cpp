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
    int countNodes(TreeNode *root, int curMax) {
        if (root == nullptr) return 0;
        return (root->val >= curMax ? 1 : 0) + countNodes(root->left, max(curMax, root->val)) +
            countNodes(root->right, max(curMax, root->val));
    }

    int goodNodes(TreeNode *root) {
        return 1 + countNodes(root->left, root->val) + countNodes(root->right, root->val);
    }
};
