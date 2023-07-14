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
    int* getAns(TreeNode* root, int &k) {
        if (root == NULL) return NULL;
        int* left = getAns(root->left, k);
        if (--k == 0 or left) return k == 0 ? new int(root->val) : left;
        return getAns(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return *getAns(root, k);
    }
};
