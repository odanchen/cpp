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
    struct NodePath {
        int left;
        int right;
        NodePath(int left, int right) : left(left), right(right) {}
    };
    NodePath getMaxPath(TreeNode* root, int &ans) {
        if (root == nullptr) return {0, 0};

        NodePath left = getMaxPath(root->left, ans), right = getMaxPath(root->right, ans);
        NodePath cur(max(0, max(left.left, left.right)), max(0, max(right.left, right.right)));
        ans = max(ans, max(0, cur.left) + max(0, cur.right) + root->val);
        cur.left += root->val;
        cur.right += root->val;
        return cur;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        getMaxPath(root, ans);
        return ans;
    }
};
