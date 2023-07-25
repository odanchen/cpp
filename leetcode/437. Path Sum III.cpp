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
    int traverse(TreeNode* root, long long sum, unordered_map<long long, int> &frequencies, int target) {
        if (root == nullptr) return 0;
        sum += root->val;
        int ans = frequencies[sum - target];
        frequencies[sum]++;
        ans += traverse(root->left, sum, frequencies, target) + traverse(root->right, sum, frequencies, target);
        frequencies[sum]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> intMap = {{0, 1}};
        return traverse(root, 0, intMap, targetSum);
    }
};
