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
    int getSum(TreeNode* root, bool isParent, bool isGrandparent) {
        if (root == nullptr) return 0;
        return (isGrandparent ? root->val : 0) + getSum(root->left, !(root->val % 2), isParent) + 
                getSum(root->right, !(root->val % 2), isParent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        return getSum(root, false, false);
    }
};
