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
    void addElements(TreeNode* root, int depth, vector<int> &ans) {
        if (root == NULL) return;

        if (depth == ans.size()) ans.push_back(root->val);
        addElements(root->right, depth + 1, ans);
        addElements(root->left, depth + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        addElements(root, 0, ans);
        return ans;
    }
};
