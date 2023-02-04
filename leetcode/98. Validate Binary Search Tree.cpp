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
    bool isValidNode(TreeNode *node, optional<int> low, optional<int> high) {
        if (node == NULL) return true;
        if (low.has_value() and node->val <= *low) return false;
        if (high.has_value() and node->val >= *high) return false;
        return isValidNode(node->left, low, optional<int>(node->val)) and 
                isValidNode(node->right, optional<int>(node->val), high);
    }
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, optional<int>(), optional<int>());
    }
};
