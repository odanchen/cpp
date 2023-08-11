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
    void getSum(TreeNode* root, int &maxLevel, int &sum, int curLevel) {
        if (root == nullptr) return;
        
        if (root->left == nullptr and root->right == nullptr) {
            if (curLevel == maxLevel) sum += root->val;
            else if (curLevel > maxLevel) {
                sum = root->val;
                maxLevel = curLevel;
            }
        } else {
            getSum(root->left, maxLevel, sum, curLevel + 1); 
            getSum(root->right, maxLevel, sum, curLevel + 1); 
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxLevel = 0, sum = 0;
        getSum(root, maxLevel, sum, 0);
        return sum;
    }
};
