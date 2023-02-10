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
    set<int> search;
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return NULL;
        if (search.find(root->val) != search.end()) return true;
        search.insert(k - root->val);
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
};
