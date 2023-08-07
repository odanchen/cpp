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
    int countLongest(TreeNode *root, bool isRight, int cur) {
        if (root == nullptr) return 0;
        return max(cur, max(countLongest(root->left, false, isRight ? cur + 1 : 1),
                            countLongest(root->right, true, isRight ? 1 : cur + 1)));
    }

    int longestZigZag(TreeNode *root) {
        return max(countLongest(root->left, false, 1), countLongest(root->right, true, 1));
    }
};
