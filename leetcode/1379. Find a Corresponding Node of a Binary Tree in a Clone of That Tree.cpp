/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == nullptr or cloned->val == target->val) return cloned;
        auto ans = getTargetCopy(original->left, cloned->left, target); 
        if (ans != nullptr) return ans;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
