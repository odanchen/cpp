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
    TreeNode* flattenTree(TreeNode* root) {
        if (root == NULL || (root->left == NULL and root->right == NULL)) return root;

        TreeNode* temp = root->right;
        root->right = flattenTree(root->left);
        root->left = NULL;
        TreeNode* treeEnd = root;
        while(treeEnd->right != NULL) treeEnd = treeEnd->right;
        treeEnd->right = flattenTree(temp);

        return root;
    }
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};
