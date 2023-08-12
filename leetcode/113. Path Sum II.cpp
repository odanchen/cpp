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
    void traverse(TreeNode* root, int target, int sum, vector<int> &elements, vector<vector<int>> &ans) {
        if (root == nullptr) return;
        
        sum += root->val;
        elements.push_back(root->val);
        if (root->left == nullptr and root->right == nullptr) {
            if (sum == target) ans.push_back(elements);
        } else {
            traverse(root->left, target, sum, elements, ans);
            traverse(root->right, target, sum, elements, ans);
        }
        elements.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> elements;
        traverse(root, targetSum, 0, elements, ans);
        return ans;
    }
};
