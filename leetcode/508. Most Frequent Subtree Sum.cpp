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
    int traverse(TreeNode *root, vector<int> &ans, unordered_map<int, int> &frequencies, int &curMax) {
        if (root == nullptr) return 0;

        int sum = traverse(root->left, ans, frequencies, curMax) + traverse(root->right, ans, frequencies, curMax) +
                root->val;
        if (++frequencies[sum] > curMax) {
            ans = {sum};
            curMax = frequencies[sum];
        }
        else if (frequencies[sum] == curMax) ans.push_back(sum);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> ans;
        unordered_map<int, int> frequencies;
        int curMax = 0;
        traverse(root, ans, frequencies, curMax);
        return ans;
    }
};
