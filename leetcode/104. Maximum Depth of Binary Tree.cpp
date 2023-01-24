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
    void traverse(TreeNode* root, int curDepth, int &max_depth)
    {
        if(root == nullptr) return;

        max_depth = max(curDepth, max_depth);
        traverse(root->left, curDepth + 1, max_depth);
        traverse(root->right, curDepth + 1, max_depth);
    }
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        traverse(root, 1, max_depth);
        return max_depth;
    }
};
