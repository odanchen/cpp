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
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if ((root == NULL) ^ (subRoot == NULL)) return false;
        if (root == NULL) return true;
        return root->val == subRoot->val and 
            sameTree(root->left, subRoot->left) and sameTree(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (sameTree(root, subRoot)) return true;
        if (root == NULL) return false; 
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
