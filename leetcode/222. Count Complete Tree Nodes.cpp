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
    int countDepth(TreeNode* root) {
        int cnt = 0;
        while (root) {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    bool checkNode(TreeNode* root, int num, int depth) {
        int left = 0, right = 1 << (depth - 1);
        for (int i = 1; i < depth; i++) {
            int mid = (left + right) / 2;
            if (num <= mid) {
                root = root->left;
                right = mid;
            } else {
                root = root->right;
                left = mid;
            }
        }
        return root != NULL;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = countDepth(root);
        int left = 0, right = 1 << (depth - 1);
        while (left < right) {
            int mid = (left + right) / 2;
            if (checkNode(root, mid, depth)) left = mid + 1;
            else right = mid;
        }
        return (1 << (depth - 1)) + left - 1 - (checkNode(root, left, depth) ? 0 : 1);
    }
};
