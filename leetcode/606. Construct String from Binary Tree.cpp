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
    string tree2str(TreeNode* root) {
        if (root == nullptr) return "";
        string left = tree2str(root->left), right = tree2str(root->right);
        if (left.empty() and right.empty()) return to_string(root->val);
        return to_string(root->val) + '(' + left + ')' + (right.empty() ? "" : '(' + right + ')');
    }
};
